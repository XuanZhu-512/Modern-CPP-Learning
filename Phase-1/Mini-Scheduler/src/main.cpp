#include "Scheduler.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std::chrono_literals;

int main() {
    std::cout << "=== Mini-Scheduler Demo ===\n";
    
    // 获取当前时间
    auto now = std::chrono::system_clock::now();

    // 创建任务列表
    std::vector<Schedule> tasks;

    // 任务1：打印 Tick，每隔 2 秒执行一次
    tasks.emplace_back(1, "Tick", now + 2s, [] {
        std::cout << "[Task] Tick executed\n";
    });

    // 任务2：打印 Tock，每隔 3 秒执行一次
    tasks.emplace_back(2, "Tock", now + 3s, [] {
        std::cout << "[Task] Tock executed\n";
    });

    // 任务3：打印 Hello，每隔 5 秒执行一次
    tasks.emplace_back(3, "Hello", now + 5s, [] {
        std::cout << "[Task] Hello executed\n";
    });

    // 打印任务信息
    for (const auto& t : tasks) {
        t.print();
    }

    // 模拟简单的调度器：每秒检查一次任务是否到期
    std::cout << "\n--- Scheduler running ---\n";

    for (int i = 0; i < 10; i++) {
        auto current = std::chrono::system_clock::now();

        for (auto& t : tasks) {
            if (current >= t.getTime()) {
                t.run();
                // 更新下一次执行时间
                t.setTime(current + std::chrono::seconds((t.getName() == "Tick") ? 2 :
                                                         (t.getName() == "Tock") ? 3 : 5));
            }
        }

        std::this_thread::sleep_for(1s);
    }

    std::cout << "--- Scheduler stopped ---\n";

    return 0;
}