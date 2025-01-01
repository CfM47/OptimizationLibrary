cmake_minimum_required(VERSION 3.22)
project(optimization C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
        src/allocation.c
        src/allocation.h
        src/optimization.h
        src/simplex.c
        src/simplex.h

        main.c
        )

add_executable(main ${SOURCES})
include_directories(src src/utils)