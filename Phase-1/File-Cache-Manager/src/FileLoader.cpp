#include "FileLoader.h"
#include <fstream>
#include <sstream>

std::shared_ptr<std::string> FileLoader::loadFile(const std::filesystem::path &path) const {
    if (!std::filesystem::exists(path)) {
        throw std::runtime_error("File not found: " + path.string());
    }

    if (!std::filesystem::is_regular_file(path)) {
        throw std::runtime_error("Not a regular file: " + path.string()); 
    }

    std::uintmax_t fileSize = std::filesystem::file_size(path);
    if (fileSize > MAX_FILE_SIZE) {
        throw std::runtime_error("File too large (> 10MB): " + path.string());
    }

    std::ifstream file(path, std::ios::in | std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + path.string());
    }

    std::ostringstream buffer;
    buffer << file.rdbuf(); // 读取整个文件到内存

    return std::make_shared<std::string>(buffer.str());
}