cmake_minimum_required(VERSION 3.5)

project(priority_queue_lib)

set(SOURCE priority_queue.cpp)
set(HEDADERS priority_queue.hpp)

add_library(${PROJECT_NAME} ${SOURCE} ${HEDADERS})

set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
