cmake_minimum_required(VERSION 3.16)
project(LangOCR)

set(CMAKE_CXX_STANDARD 14)

include_directories(packages/include)

include_directories(gui)

file(GLOB SRC_FILES gui/*.cpp)

add_executable(LangOCR ${SRC_FILES})
