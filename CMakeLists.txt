cmake_minimum_required(VERSION 3.26)
project(cfroglang C)

set(CMAKE_C_STANDARD 11)

add_executable(cfroglang main.c
        common.h
        chunk.h
        chunk.c
        memory.h
        memory.c
        debug.h
        debug.c
        value.h
        value.c
        vm.h
        vm.c)
