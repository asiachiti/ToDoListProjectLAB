cmake_minimum_required(VERSION 3.20)
project(ToDoListProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
file(GLOB_RECURSE CORE_HEADERS "include/*.h")
file(GLOB_RECURSE CORE_SOURCES "src/*.cpp")

add_library(core STATIC ${CORE_SOURCES} ${CORE_HEADERS})
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(todolist_app src/main.cpp)
target_link_libraries(todolist_app PRIVATE core)

add_subdirectory(test/lib/googletest-main)
include_directories(test/lib/googletest/googletest/include)

file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")
add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests PRIVATE core gtest gtest_main)

enable_testing()
add_test(NAME ToDoListTests COMMAND runTests)
