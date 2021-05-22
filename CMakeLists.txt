project(vector_matrix_zee)
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)

# Set paths and other variables
add_subdirectory(src)
include_directories($(PROJECT_SOURCE_DIR)/src/include)
enable_testing()
add_subdirectory(tests)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
set(EXECUTABLE_OUTPUT_PATH $(PROJECT_SOURCE_DIR)/bin)
set(LIBRARY_OUTPUT_PATH $(PROJECT_SOURCE_DIR)/lib)
# set(CMAKE_CXX_FLAGS_RELEASE "-03")