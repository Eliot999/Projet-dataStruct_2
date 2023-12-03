cmake_minimum_required(VERSION 3.26)
project(Projet_dataStruct_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_dataStruct_2
        main.c
        set.c
        set.h
        timer.c
        timer.h
        tree.h
        diary.h
        diary.c)
