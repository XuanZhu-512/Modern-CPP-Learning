#include "Scheduler.h"
#include <ctime>

Schedule::Schedule(int id, std::string name, TimePoint time, std::function<void()> task) 
        : id_(id), name_(std::move(name)), time_(time), task_(task) {}

int Schedule::getID() const { return id_; }

const std::string &Schedule::getName() const { return name_; }

Schedule::TimePoint Schedule::getTime() const { return time_; }

void Schedule::setTime(TimePoint newTime) { time_ = newTime; }

void Schedule::run() const {
    std::cout << "[Task] Running: " << name_ << std::endl;
    task_();
}

bool Schedule::operator<(const Schedule &other) const {
    return time_ < other.time_;
}

void Schedule::print() const {
    std::time_t t = Clock::to_time_t(time_);
    std::cout << "Task[" << id_ << "] " << name_
              << " @" << std::ctime(&t);
}