cmake_minimum_required(VERSION 3.26)
project(Projet_dataStruct_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_dataStruct_2
        cell.c
        cell.h
        list.h
        tree.h
        list.c
        set.h
        set.c)
