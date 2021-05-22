# Include libraries
add_library(vector include/vector.cpp)
add_library(matrix include/matrix.cpp)
add_executable(main main.cpp)
# Link libraries
target_link_libraries(main vector matrix)
