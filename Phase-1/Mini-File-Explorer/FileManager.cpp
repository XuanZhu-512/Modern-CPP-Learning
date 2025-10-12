#include "FileManager.h"
#include <iostream>

FileManager::FileManager(const std::string &path) : currentPath(path) {
    if (!std::filesystem::exists(currentPath)) {
        // 抛出一个运行时异常（当前路径不存在）
        throw std::runtime_error("Current path does not exist: " + path);
    }
}

void FileManager::listDirectory() const {
    std::cout << "Listing: " << currentPath << std::endl;

    for (const auto& entry : std::filesystem::directory_iterator(currentPath)) {
        std::string type = entry.is_directory() ? "[DIR]" : "[FILE]";
        std::string size = entry.is_regular_file() ? std::to_string(entry.file_size()) : "-";
        std::cout << type << "\t" << size << "\t" << entry.path().filename().string() << std::endl;
    }
}

void FileManager::changeDirectory(const std::string &newPath) {
    std::filesystem::path target = currentPath / newPath;
    target = std::filesystem::absolute(target);

    if (!std::filesystem::exists(target) || !std::filesystem::is_directory(target)) {
        throw std::runtime_error("New path does not exist or is not a directory: " + target.string());
    }

    currentPath = target;
}

std::string FileManager::getCurrentPath() const {
    return currentPath.string();
}

void FileManager::createFolder(const std::string &foldername) {
    std::filesystem::path newFolderPath = currentPath / foldername;

    if (std::filesystem::exists(newFolderPath)) {
        throw std::runtime_error("Folder already exists: " + newFolderPath.string());
    }

    try {
        if (!std::filesystem::create_directory(newFolderPath)) {
            throw std::runtime_error("Failed to create folder: " + newFolderPath.string());
        }
        std::cout << "Folder created: " << newFolderPath.string() << "\n";
    }
    catch (const std::filesystem::filesystem_error &e) {
        throw std::runtime_error("Filesystem error: " + std::string(e.what()));
    }
}

void FileManager::deleteItem(const std::string &name) {
    std::filesystem::path targetPath = currentPath / name;

    if (!std::filesystem::exists(targetPath)) {
        throw std::runtime_error("Target does not exist: " + targetPath.string());
    }

    try {
        if (std::filesystem::is_directory(targetPath)) {
            size_t count = std::filesystem::remove_all(targetPath);
            std::cout << "Directory deleted (" << count << " items): " << targetPath.string() << std::endl;
        }
        else if (std::filesystem::remove(targetPath)) {
            std::cout << "File deleted: " << targetPath.string() << std::endl;
        }
        else {
            throw std::runtime_error("Failed to delete file: " + targetPath.string());
        }
    }
    catch (const std::filesystem::filesystem_error &e) {
        throw std::runtime_error("File system error: " + std::string(e.what()));
    }
}

void FileManager::search(const std::string &keyword) {
    bool found = false;

    try {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(currentPath)) {
            std::string filename = entry.path().filename().string();

            if (filename.find(keyword) != std::string::npos) {
                found = true;
                std::cout << (entry.is_directory() ? "[DIR]  " : "[FILE]  ")
                          << entry.path().string() << std::endl;
            }
        }

        if (!found) {
            std::cout << "No items found matching keyword: " << keyword << std::endl; 
        }
    }
    catch (const std::filesystem::filesystem_error& e) {
        throw std::runtime_error("File system error during search: " + std::string(e.what()));
    }
}