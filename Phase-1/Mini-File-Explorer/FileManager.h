#pragma once
#include <string>
#include <filesystem>

class FileManager {
public:
    // 构造函数，初始化当前路径
    explicit FileManager(const std::string& path);

    // 列出当前目录下的文件和文件夹（ls）
    void listDirectory() const;

    // 改变当前路径（cd）
    void changeDirectory(const std::string& newPath);

    // 返回当前路径
    std::string getCurrentPath() const;

    // 创建新文件夹（mkdir）
    void createFolder(const std::string& foldername);

    // 删除文件或文件夹（文件夹支持递归删除）（rm）
    void deleteItem(const std::string& name);

    // 搜索当前目录下匹配关键字的文件
    void search(const std::string& keyword);

private:
    std::filesystem::path currentPath;
};