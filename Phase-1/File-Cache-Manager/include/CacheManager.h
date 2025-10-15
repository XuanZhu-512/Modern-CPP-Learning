#pragma once
#include <string>
#include <unordered_map>
#include <list>
#include <memory>
#include <mutex>
#include "FileCache.h"
#include "FileLoader.h"

// CacheManager：管理整个文件缓存池，支持LRU自动清理
// 提供缓存查找与加载、LRU策略、线程安全与智能指针管理
class CacheManager {
public:
    explicit CacheManager(size_t maxSize = 5); // 默认缓存最多5个文件

    // 禁止拷贝但允许移动（资源独占）
    CacheManager(const CacheManager&) = delete;
    CacheManager& operator=(const CacheManager&) =  delete;
    CacheManager(CacheManager&&) noexcept = default;
    CacheManager& operator=(CacheManager&&) noexcept = default;

    // 获取文件缓存（若未缓存则自动加载）
private:
};