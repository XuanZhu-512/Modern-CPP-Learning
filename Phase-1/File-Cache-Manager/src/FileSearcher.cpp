#include "FileSearcher.h"
#include <iostream>
#include <fstream>

FileSearcher::FileSearcher(std::shared_ptr<FileLoader> loader) 
    : loader(std::move(loader)) {}

std::vector<std::filesystem::path> FileSearcher::searchByName(
    const std::filesystem::path &root, 
    const std::string &keyword
) const {
    std::vector<std::filesystem::path> res;

    if (!std::filesystem::exists(root)) {
        std::cerr << "Direcotry not found: " << root << std::endl;
        return res;
    }

    for (const auto& entry : std::filesystem::recursive_directory_iterator(root)) {
        if (entry.is_regular_file()) {
            std::string filename = entry.path().filename().string();
            if (filename.find(keyword) != std::string::npos) {
                res.push_back(entry.path());
            }
        }
    }

    return res;
}

std::vector<std::filesystem::path> FileSearcher::searchByContent(
    const std::filesystem::path &root, 
    const std::string &keyword
) const {
    std::vector<std::filesystem::path> res;

    if (!std::filesystem::exists(root)) {
        std::cerr << "Direcotry not found: " << root << std::endl;
        return res;
    }

    for (const auto& entry : std::filesystem::recursive_directory_iterator(root)) {
        if (!entry.is_regular_file()) continue;

        try {
            std::string content = loader->loadFile(entry.path());
            if (content.find(keyword) != std::string::npos) {
                res.push_back(entry.path());
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Skipping file (error reading): " 
                      << entry.path() << " (" << e.what() << ")" << std::endl;
        }
    }

    return res;
}
