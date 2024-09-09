cmake_minimum_required(VERSION 3.22 VERSION 0.1.0)

# cairo_gtk_demo

project(CairoGtk3Window)

set(HEADER_FILES src/pch/myzdin-pch.h)

file(GLOB_RECURSE SOURCE_FILES "src/*.c")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(STANDARD_C_VERSION_FLAG "-std=c11")
set(OPTIMIZE_FLAG "-O3")
set(WARNING_FLAGS "-Werror -Wpedantic -Wall -Wextra -Wno-unused-parameter")
set(DEBUG_FLAGS "-g")
set(FLAGS "-I${GTK3_INCLUDE_DIRS}")

file(COPY lint_codebase.sh DESTINATION ${CMAKE_BINARY_DIR})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${STANDARD_C_VERSION_FLAG} ${OPTIMIZE_FLAG} ${WARNING_FLAGS} ${DEBUG_FLAGS} ${FLAGS}")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(SYSTEM ${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE ${HEADER_FILES})
