#pragma once

#include <string>
#include <memory.h>
#include <filesystem>
#include <chrono>

/**
 * @brief FileCache: 表示一个文件缓存对象
 *        提供对文件的操作，
 *        负责保存文件内容、路径与时间信息
 */
class FileCache {
public:
    // 构造函数，接收文件路径和内容
    FileCache(const std::filesystem::path& path, std::shared_ptr<std::string> content);

    // 禁止拷贝，但允许移动（保证资源独占）
    FileCache(const FileCache&) = delete;
    FileCache& operator=(const FileCache&) = delete;
    FileCache(FileCache&&) noexcept = default;
    FileCache& operator=(FileCache&&) noexcept = default;

    ~FileCache() = default; // RAII 自动释放 share_ptr 资源

    // 获取文件路径
    const std::filesystem::path& getPath();

    // 获取文件内容
    std::shared_ptr<const std::string> getContent() const;

    // 获取上次修改时间（文件系统时间戳）
    std::filesystem::file_time_type getLastWriteTime() const;

    // 获取缓存加载时间（系统当前时间）
    std::chrono::system_clock::time_point getLoadTime() const;

private:
    std::filesystem::path filePath_; // 文件路径
    std::shared_ptr<std::string> content_; // 文件内容的智能指针
    std::filesystem::file_time_type lastWriteTime_; // 文件系统修改时间
    std::chrono::system_clock::time_point loadTime_; // 缓存加载时间
};