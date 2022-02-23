cmake_minimum_required(VERSION 3.5)

project(priority_queue_BENCHMARK)

set(MAIN_BENCHMARK_TEST benchmark_priority_queue.cpp benchmark_priority_queue.h)

FetchContent_Declare(
        googleBenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.6.1        # release-1.10.0
)

set(benchmark_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(GoogleBenchmark)

enable_testing()

add_executable(${PROJECT_NAME} ${MAIN_BENCHMARK_TEST})

set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../priority_queue
)

target_link_libraries(
        ${PROJECT_NAME}
        benchmark_main
        benchmark
        pthread

)

#include(GoogleBenchmark)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
            )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Werror -Wall -Wimplicit-fallthrough -pedantic-errors
            )
endif()

