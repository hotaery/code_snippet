cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(OpenSSLDemo)
add_executable(Base64 examples/Base64.cpp)

find_package(OpenSSL CONFIG REQUIRED)

target_link_libraries(Base64 PRIVATE OpenSSL::SSL OpenSSL::Crypto)