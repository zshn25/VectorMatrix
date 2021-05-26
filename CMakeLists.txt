project(vector_matrix_zee
        DESCRIPTION "A vector and matrix class")
cmake_minimum_required(VERSION 3.15.1)
set(CMAKE_CXX_STANDARD 11)

# Set paths and other variables
add_subdirectory(src)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(CTest)
enable_testing()
add_subdirectory(tests)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
set(EXECUTABLE_OUTPUT_PATH $(PROJECT_SOURCE_DIR)/bin)
set(LIBRARY_OUTPUT_PATH $(PROJECT_SOURCE_DIR)/lib)
# set(CMAKE_CXX_FLAGS_RELEASE "-03")