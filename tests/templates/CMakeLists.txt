cmake_minimum_required(VERSION 2.8.2)
include(CTest)


project(Testing)
# Trivial example using gtest and gmock
add_executable(template_test templateTest.cpp)

target_link_libraries(template_test
        gtest gmock_main
        ${ARMADILLO_LIBRARIES}
        ${MKL_LIBRARIES} pthread dl)

add_test(NAME template_test COMMAND template_test)
