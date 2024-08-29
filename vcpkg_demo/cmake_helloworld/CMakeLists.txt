cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(VCPKG_TARGET_TRIPLET x86-windows-static)

project(HelloWorld)
add_executable(HelloWorld main.cpp)

find_package(boost_system CONFIG REQUIRED)

find_package(mailio CONFIG REQUIRED)
target_link_libraries(HelloWorld PRIVATE mailio)