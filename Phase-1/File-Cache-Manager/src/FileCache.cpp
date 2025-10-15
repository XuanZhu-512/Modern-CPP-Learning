#include "FileCache.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

FileCache::FileCache(const std::filesystem::path &path, std::shared_ptr<std::string> content) 
    : filePath_(path),
      content_(std::move(content)),
      loadTime_(std::chrono::system_clock::now()) {

    if (!std::filesystem::exists(path)) {
        throw std::runtime_error("FileCache: File does not exist: " + filePath_.string());
    }

    // 记录文件系统修改时间
    lastWriteTime_ = std::filesystem::last_write_time(filePath_);
}

const std::filesystem::path &FileCache::getPath() {
    return filePath_;
}

std::shared_ptr<const std::string> FileCache::getContent() const {
    return content_;
}

std::filesystem::file_time_type FileCache::getLastWriteTime() const {
    return lastWriteTime_;
}

std::chrono::system_clock::time_point FileCache::getLoadTime() const {
    return loadTime_;
}