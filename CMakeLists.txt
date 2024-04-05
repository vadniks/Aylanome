cmake_minimum_required(VERSION 3.26)
set(CMAKE_C_COMPILER /usr/bin/clang)
project(Aylanome C)

set(CMAKE_C_STANDARD 23)

add_compile_options("-Wall")
add_compile_options("-Wextra")
add_compile_options("-Wpedantic")
add_compile_options("-O3")

file(GLOB SOURCES CONFIGURE_DEPENDS src/*.c src/*.h)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} SDL2 GL GLEW)
