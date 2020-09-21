cmake_minimum_required(VERSION 3.16)
project(LangOCR)
include(conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR})

file(GLOB SRC_FILES gui/*.cpp)
add_executable(LangOCR ${SRC_FILES})

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(${CONAN_INCLUDE_DIRS})
include_directories(gui)

target_compile_options(LangOCR PRIVATE -fPIC)
target_link_libraries(LangOCR Qt5::Widgets ${CONAN_LIBS})
