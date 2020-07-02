cmake_minimum_required(VERSION 3.16)
project(Chat_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chat_project main.cpp cmake-build-debug/Client.hpp CustomRSA.hpp uint256_t.cpp uint128_t.cpp uintT_t.hpp bitset_arithmetic.hpp)