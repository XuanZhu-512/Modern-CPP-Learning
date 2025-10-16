cmake_minimum_required(VERSION 3.15)
project(FileCacheManager LANGUAGES CXX)

# 使用现代 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# === 源码路径 ===
include_directories(include)
file(GLOB SOURCES src/*.cpp)

# === 生成可执行文件 ===
add_executable(FileCacheManager ${SOURCES})

# === 文件系统库支持（C++17 可能需要显式链接 stdc++fs）===
if (CMAKE_COMPILER_IS_GNUCXX)
    target_link_libraries(FileCacheManager stdc++fs)
endif()

# === 让所有可执行文件都输出到项目根目录 ===
set_target_properties(FileCacheManager PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${PROJECT_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${PROJECT_SOURCE_DIR}
)

# === 打印构建信息（可选调试）===
message(STATUS "Project source dir: ${PROJECT_SOURCE_DIR}")
message(STATUS "Executable output dir: ${PROJECT_SOURCE_DIR}")
