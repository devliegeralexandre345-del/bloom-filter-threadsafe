cmake_minimum_required(VERSION 3.14)
project(bloom_filter_threadsafe LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

add_library(bloom_filter STATIC src/bloom_filter.cpp include/bloom_filter.hpp)
target_include_directories(bloom_filter PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(main src/main.cpp)
target_link_libraries(main bloom_filter)

enable_testing()
add_executable(tests tests/test.cpp)
target_link_libraries(tests bloom_filter)
add_test(NAME BloomFilterTests COMMAND tests)