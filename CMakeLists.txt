cmake_minimum_required(VERSION 3.12)
project(MPointers)

set(CMAKE_CXX_STANDARD 11)

add_executable(MPointers main.cpp MPointer.cpp LinkedList.cpp MPointer.h MPointerGC.h Mapa_Memoria.cpp Mapa_Memoria.h LinkedList.h)