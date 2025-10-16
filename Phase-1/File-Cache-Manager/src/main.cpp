#include <iostream>
#include <string>
#include <memory>
#include "CacheManager.h"

int main() {
    // 创建缓冲池，最大缓存 5 个文件
    CacheManager cacheManager(5);

    std::cout << "=== Simple File Cache Manager ===" << std::endl;
    std::cout << "Commands:" << std::endl
              << "  load <path>   - Load file into cache" << std::endl
              << "  show <path>   - Show file content" << std::endl
              << "  status        - Print cache status" << std::endl
              << "  clear         - Clear all cache" << std::endl
              << "  exit          - Quit program" << std::endl;
            
    std::string command;
    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, command);

        if (command.empty()) continue;

        if (command == "exit") break;
        else if (command == "status") {
            cacheManager.printStatus();
        }
        else if (command == "clear") {
            cacheManager.clear();
        }
        else if (command.rfind("load ", 0) == 0) {
            std::string path = command.substr(5);
            try {
                auto content = cacheManager.getFile(path);
                std::cout << "[Info] Loaded file into cache: " << path << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "[Error] " << e.what() << std::endl; 
            }
        }
        else if (command.rfind("show ", 0) == 0) {
            std::string path = command.substr(5);
            try {
                auto content = cacheManager.getFile(path);
                std::cout << "----- File Content Start -----\n";
                std::cout << *content << "\n";
                std::cout << "----- File Content End -----\n";
            }
            catch (const std::exception& e) {
                std::cerr << "[Error] " << e.what() << std::endl;
            }
        }
        else {
            std::cout << "[Error] Unknown command" << std::endl;
        }
    }

    std::cout << "Exiting File Cache Manager..." << std::endl;
    return 0;
}