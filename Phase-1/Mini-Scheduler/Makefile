# ==== 项目配置 ====
CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Iinclude
BUILD_DIR := build
SRC_DIR := src
TARGET := MiniScheduler        # 可执行文件名（会生成在当前目录）

# ==== 自动搜集所有源文件 ====
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# ==== 默认目标 ====
all: $(TARGET)

# ==== 链接可执行文件 ====
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o ./$@      
	@echo "✅ Build finished: $(TARGET)"

# ==== 编译每个 .cpp ====
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ==== 创建 build 目录（如果不存在） ====
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# ==== 清理 ====
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	@echo "🧹 Cleaned all build files."

# ==== 伪目标 ====
.PHONY: all clean
