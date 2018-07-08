cmake_minimum_required(VERSION 3.10)
project(powerline-c C)
add_compile_options("-Ofast")

set(CMAKE_C_STANDARD 11)

add_executable(powerline-c src/main.c
        src/print.c
        src/ansi.h
        src/print.h
        src/powerline.h
        src/ansi.c src/utils.c)

install(TARGETS powerline-c DESTINATION bin)
