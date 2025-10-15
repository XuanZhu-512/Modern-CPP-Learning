#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <memory>
#include "FileLoader.h"

/**
 * @brief Filesearcher：用于在文件系统中搜索文件名或文件内容
 *        依赖 FileLoader 从磁盘中加载文件内容
 *        支持递归搜索、模糊匹配、内容匹配
 */
class FileSearcher {
public:
    explicit FileSearcher(std::shared_ptr<FileLoader> loader);

    // 按文件名搜索
    std::vector<std::filesystem::path> searchByName(
        const std::filesystem::path& root, 
        const std::string& keyword
    ) const;

    // 按文件内容搜索
    std::vector<std::filesystem::path> searchByContent(
        const std::filesystem::path& root,
        const std::string& keyword
    ) const;

private:
    std::shared_ptr<FileLoader> loader;
};