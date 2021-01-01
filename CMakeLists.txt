cmake_minimum_required(VERSION 3.16)
project(langocr)
include(conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR})

## Library source files
file(GLOB LIB_SRC_FILES lib/*.cpp)
include_directories(${CONAN_INCLUDE_DIRS})

## Gui source files
file(GLOB GUI_SRC_FILES gui/*.cpp)
file(GLOB GUI_MAIN)
include_directories(gui)
add_executable(langocr ${GUI_SRC_FILES} ${LIB_SRC_FILES})

# Server
file(GLOB SERVER_SRC_FILES server/*.c*)
file(GLOB SERVER_MAIN server/main/main.cpp)
include_directories(server)
add_executable(langocrd ${SERVER_MAIN} ${SERVER_SRC_FILES} ${LIB_SRC_FILES})

## Test exe set-up
## file(GLOB TEST_SRC_FILES test/server/*.cpp)
## file(GLOB TEST_MAIN test/main/main.cpp)
## include_directories(test)
## include_directories(test/server)
## #add_executable(langocr_test ${TEST_MAIN} ${TEST_SRC_FILES} ${SERVER_SRC_FILES} ${LIB_SRC_FILES})
## add_executable(langocr_test ${TEST_SRC_FILES} ${SERVER_SRC_FILES} ${LIB_SRC_FILES})

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(.)

target_compile_options(langocr PRIVATE -fPIC)
target_link_libraries(langocr Qt5::Widgets ${CONAN_LIBS})

target_compile_options(langocrd PRIVATE -fPIC)

# I shouldn't need to add lib 'archive', it should be in ${CONAN_LIBS} and
# part of the conan recipt. But, its not...
target_link_libraries(langocrd ${CONAN_LIBS} archive)

add_subdirectory(test)
#target_link_libraries(langocr_test ${CONAN_LIBS} archive)

# Run unit test on each compilation
#enable_testing()
#add_executable(config_value_test test/server/config_value_unittest.cpp)
#
#target_link_libraries(config_value_test ${CONAN_LIBS})
#add_test(NAME config_value_unittest
#  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#  COMMAND config_value_test)

#set(UNIT_TEST langocr_test)
#add_custom_command(
#     TARGET ${UNIT_TEST}
#     COMMENT "Run tests"
#     POST_BUILD
#     COMMAND ${UNIT_TEST}
#)
