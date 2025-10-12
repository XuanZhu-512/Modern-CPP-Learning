# 编译器
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I$(INCLUDE_DIR)

# 目录（去掉引号）
SRC_DIR = D:/Learning/Modern\  C++\ Learning/Phase\ 1/Mini\ File\ Explorer/src
BUILD_DIR = D:/Learning/Modern\  C++\ Learning/Phase\ 1/Mini\ File\ Explorer/build
INCLUDE_DIR = D:/Learning/Modern\  C++\ Learning/Phase\ 1/Mini\ File\ Explorer/include

# 源文件
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/FileManager.cpp

# 对应的对象文件
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/FileManager.o

# 可执行文件
TARGET = $(BUILD_DIR)/MiniFileExplorer.exe

# 默认目标
all: build $(TARGET)

# 链接可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# 编译对象文件
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/FileManager.o: $(SRC_DIR)/FileManager.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 创建 build 目录
build:
	if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"

# 清理
clean:
	if exist "$(BUILD_DIR)" del /Q "$(BUILD_DIR)\*" 2>nul