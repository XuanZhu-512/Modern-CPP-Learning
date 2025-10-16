#pragma once
#include <string>
#include <filesystem>
#include <memory>

/**
 * @brief FileLoader：负责从磁盘加载文件内容
 *        当 Cache 未命中时，它将文件从磁盘读取到内存中
 */
class FileLoader{
public:
    FileLoader() = default;
    ~FileLoader() = default;

    // 读取整个文件内容
    std::shared_ptr<std::string> loadFile(const std::filesystem::path& path) const;

private:
    static constexpr std::size_t MAX_FILE_SIZE = 10 * 1024 * 1024;
};