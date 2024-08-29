cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(HelloWorld)
add_executable(HelloWorld main.cpp)
add_executable(CreateThread examples/CreateThread.cpp)
add_executable(Libloaderapi examples/Libloaderapi.cpp)
add_executable(GetAdaptersInfo examples/GetAdaptersInfo.cpp)

# dll
add_library(MyPuts SHARED examples/dll/dllmain.cpp)
add_executable(DLLTest examples/dll/main.cpp)