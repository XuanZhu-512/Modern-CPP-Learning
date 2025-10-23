#pragma once

#include <string>
#include <chrono>
#include <functional>
#include <iostream>

class Schedule {
public:
    // 使用 using 关键词创建别名
    using Clock = std::chrono::system_clock;
    using TimePoint = Clock::time_point;

private:
    int id_;                        // 每个任务的唯一编号
    std::string name_;              // 任务名称
    TimePoint time_;                // 执行时间
    std::function<void()> task_;    // 要执行的任务（函数）

public:
    // 构造函数
    Schedule(int id, std::string name, TimePoint time, std::function<void()> task);

    // 获取任务ID
    int getID() const;

    // 获取任务名称
    const std::string& getName() const;

    // 获取执行时间
    TimePoint getTime() const;

    // 设置新的执行时间
    void setTime(TimePoint newTime);

    // 执行任务
    void run() const;

    // 比较函数（方便在容器中排序）
    bool operator<(const Schedule& other) const;

    // 输出调试信息
    void print() const;
};