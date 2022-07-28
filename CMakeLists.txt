cmake_minimum_required(VERSION 3.5)

project(Morsecode VERSION 1.0 LANGUAGES CXX)

include(CTest)

add_subdirectory(src)
add_subdirectory(tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
