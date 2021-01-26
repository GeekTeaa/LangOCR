cmake_minimum_required(VERSION 2.8)
project(unit-test CXX)

# Initialize Conan #############################################################
include_directories(${CONAN_INCLUDE_DIRS})
conan_basic_setup()

# Setup main for GTest #########################################################
file(GLOB TEST_GMAIN main/main.cpp)

# Setup variable for locating files ############################################
set(SERVER_TEST_DIR ${PROJECT_SOURCE_DIR}/server)
set(SERVER_SRC_DIR ${CMAKE_SOURCE_DIR}/server)

# Include the proper directories ###############################################
include_directories(${SERVER_SRC_DIR})
include_directories(${SERVER_TEST_DIR})

# Add unittest source files ####################################################
file(GLOB SERVER_TEST_FILES ${SERVER_TEST_DIR}/*.cpp)

# Create application test ######################################################
add_executable(${PROJECT_NAME} ${TEST_GMAIN} ${SERVER_TEST_FILES} ${SERVER_SRC_FILES} ${LIB_SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

enable_testing()
