#include "FileManager.h"
#include <iostream>

int main() {
    std::string startPath = std::filesystem::current_path().string();
    FileManager fm(startPath);

    std::cout << "Simple File Manager (C++)\n";
    std::cout << "Current path: " << fm.getCurrentPath() << std::endl;
    std::cout << "Commands: ls, cd <dir>, mkdir <name>, rm <name>, search <keyword>, exit\n\n";

    while (true) {
        std::cout << "> ";
        std::string cmd;
        std::cin >> cmd;

        try {
            if (cmd == "ls") {
                fm.listDirectory();
            }
            else if (cmd == "cd") {
                std::string path;
                std::cin >> path;
                fm.changeDirectory(path);
                std::cout << "Current Folder: " << fm.getCurrentPath() << std::endl;
            }
            else if (cmd == "mkdir") {
                std::string name;
                std::cin >> name;
                fm.createFolder(name);
            }
            else if (cmd == "rm") {
                std::string name;
                std::cin >> name;
                fm.deleteItem(name);
            }
            else if (cmd == "search") {
                std::string keyword;
                std::cin >> keyword;
                fm.search(keyword);
            }
            else if (cmd == "exit") {
                std::cout << "Exiting file manager.\n";
                break;
            }
            else {
                std::cout << "Unknown command.\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}