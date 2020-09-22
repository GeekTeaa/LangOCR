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

file(GLOB GUI_SRC_FILES gui/*.cpp)
file(GLOB SERVER_SRC_CPP_FILES server/*.cpp)
file(GLOB LIB_SRC_FILES lib/*.cpp)
add_executable(LangOCR ${GUI_SRC_FILES} ${LIB_SRC_FILES})
add_executable(langocrd ${SERVER_SRC_FILES} ${LIB_SRC_FILES})

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(${CONAN_INCLUDE_DIRS})
include_directories(gui)
include_directories(server)
include_directories(.)

target_compile_options(LangOCR PRIVATE -fPIC)
target_link_libraries(LangOCR Qt5::Widgets ${CONAN_LIBS})

target_compile_options(langocrd PRIVATE -fPIC)

# I shouldn't need to add 'archive', it should be in ${CONAN_LIBS} and
# part of the conan recipt. But, its not...
target_link_libraries(langocrd ${CONAN_LIBS} archive)

