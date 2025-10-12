# -----------------------------
# Mini File Explorer Makefile
# 可执行文件生成在根目录
# 不使用 -p
# -----------------------------

# 编译器
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

# 目录
SRC_DIR := src
BUILD_DIR := build

# 源文件、目标文件和依赖文件
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# 可执行文件（放在根目录）
TARGET := FileManager

# -----------------------------
# 默认目标
# -----------------------------
all: $(TARGET)

# 链接可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# 编译源文件为目标文件，并生成依赖文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# 包含依赖文件，如果不存在则忽略
-include $(DEPS)

# -----------------------------
# 清理目标
# -----------------------------
.PHONY: clean
clean:
	@echo Cleaning...
	@rmdir /S /Q $(BUILD_DIR) 2>NUL || rm -rf $(BUILD_DIR)/* 2>/dev/null || true
	@rm -f $(TARGET) 2>NUL || true

# -----------------------------
# 重新编译
# -----------------------------
.PHONY: rebuild
rebuild: clean all