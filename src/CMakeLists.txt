# Include libraries
add_subdirectory(include)
add_executable(main main.cpp)
# Link libraries
target_link_libraries(main vector_matrix)