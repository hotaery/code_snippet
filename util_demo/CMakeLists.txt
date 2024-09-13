cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(VCPKG_TARGET_TRIPLET x86-windows-static)
project(UtilDemo)
find_package(spdlog CONFIG REQUIRED)

add_executable(SpdlogExample examples/SpdlogExample.cpp)
target_link_libraries(SpdlogExample PRIVATE spdlog::spdlog)

add_executable(main main.cpp)