# Include libraries
add_subdirectory(include)
add_executable(main main.cpp)
include_directories(include)
# Link libraries
target_link_libraries(main PUBLIC vector_matrix)