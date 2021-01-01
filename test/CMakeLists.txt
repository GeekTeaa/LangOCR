cmake_minimum_required(VERSION 2.8)
project(unit-test CXX)

# Initialize Conan #############################################################
include_directories(${CONAN_INCLUDE_DIRS})
include_directories(../server/)
conan_basic_setup()

# Create application test ######################################################
add_executable(${PROJECT_NAME} main/main.cpp server/config_value_unittest.cpp ../server/config_value.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

# Include Encryptor test #######################################################
enable_testing()
add_test(
  NAME config-value
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
  COMMAND ${PROJECT_NAME})
