cmake_minimum_required(VERSION 3.22)
project(optimization C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
        src/utils/vector.c
        src/utils/vector.h
        src/simplex.c
        main.c
        )

add_executable(main ${SOURCES})
include_directories(src src/utils)