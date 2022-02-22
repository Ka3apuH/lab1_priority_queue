cmake_minimum_required(VERSION 3.5)

project(lab1_priority_queue)

add_executable(${PROJECT_NAME} main.cpp ../src/priority_queue.cpp)

set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
)
#find_package(src CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE priority_queue_lib)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
            )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Werror -Wall -Wimplicit-fallthrough -pedantic-errors
            )
endif()