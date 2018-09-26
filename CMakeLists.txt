cmake_minimum_required(VERSION 3.12)
project(MPointers)

include_directories(${MY_SOURCE_DIR} /home/isaac/Downloads/rapidjson-master/include)
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(MPointers main.cpp MPointer.cpp Mapa_Memoria.cpp DataStructures/LinkedList.cpp MPointer.h MPointerGC.h Mapa_Memoria.h DoubleLinkedList.cpp Sort.cpp Server/Server.cpp Server/Server.h Server/Client.cpp Server/Client.h)