cmake_minimum_required(VERSION 3.0)
project(project C CXX)

add_library(lib lib/lib.c)

add_executable(main main/main.c)
target_include_directories(main PRIVATE lib)
target_link_libraries(main PRIVATE lib)

include(FetchContent)
FetchContent_Declare(
  	googletest
  	GIT_REPOSITORY https://github.com/google/googletest.git
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)
    # add the targets: gtest,gtest_main,gmock,gmock_main
    add_subdirectory(
        ${googletest_SOURCE_DIR}
        ${googletest_BINARY_DIR}
    )
endif()

enable_testing()

add_executable(unit_test)
target_sources(unit_test PRIVATE test/test.cc)
target_include_directories(unit_test PRIVATE ./lib)
target_link_libraries(unit_test PRIVATE lib gtest_main)
add_test(NAME unit_test COMMAND $<TARGET_FILE:unit_test>)