add_executable(
    my_gtest
    my_gtest.cc
)
target_link_libraries(
    my_gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(my_gtest)