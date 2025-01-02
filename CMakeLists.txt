cmake_minimum_required(VERSION 3.22)
project(optimization C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
        src/allocation.c
        src/allocation.h
        src/optimization.h
        src/simplex/simplex.c
        src/simplex/simplex.h
        src/simplex/tests.c
        src/simplex/tests.h
        

        main.c
        )

add_executable(main ${SOURCES})
include_directories(src src/utils)