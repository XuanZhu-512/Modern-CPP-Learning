#include "CacheManager.h"
#include <iostream>

CacheManager::CacheManager(size_t maxSize) : maxSize_(maxSize) {}

std::shared_ptr<const std::string> CacheManager::getFile(const std::string &path) {
    // 给共享资源上互斥锁，确保线程安全
    std::lock_guard<std::mutex> lock(mtx_);

    auto it = cacheMap_.find(path);

    // 若已经缓存
    if (it != cacheMap_.end()) {
        touch(path);
    }

    // 若未缓存，从磁盘中加载
    auto content = loader_.loadFile(path);
    auto newCache = std::make_unique<FileCache>(path, content);

    // 插入缓存表
    usageOrder_.push_front(path);
    cacheMap_[path] = { std::move(newCache), usageOrder_.begin() };

    evictIfNeeded();
    return content;
}

/**
 * @brief 清除所有缓存（包括 LRU 队列、缓存文件主查找表）
 */
void CacheManager::clear() {
    std::lock_guard<std::mutex> lock(mtx_);
    cacheMap_.clear();
    usageOrder_.clear();
    std::cout << "[CacheManager] Cache cleared." << std::endl;
}

void CacheManager::printStatus() const {
    std::lock_guard<std::mutex> lock(mtx_);
    std::cout << "[CacheManger] Current cache:" << std::endl;
    for (const auto& name : usageOrder_) {
        std::cout << "  - " << name << std::endl; 
    }
}

/**
 * @brief 将给定路径（最新访问文件）移至 LRU 队列头部
 * 
 * @param 给定路径参数
 */
void CacheManager::touch(const std::string &path) {
    auto& entry = cacheMap_[path];
    usageOrder_.erase(entry.orderIt);
    usageOrder_.push_front(path);
    entry.orderIt = usageOrder_.begin();
}

/**
 * @brief 当缓存文件数超过上限时，删除最不经常访问文件
 */
void CacheManager::evictIfNeeded() {
    while (cacheMap_.size() > maxSize_) {
        std::string oldest = usageOrder_.back();
        usageOrder_.pop_back();
        cacheMap_.erase(oldest);
        std::cout << "[CacheManager] Evicted: " << oldest << std::endl;
    }
}