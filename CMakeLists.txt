cmake_minimum_required(VERSION 3.9)
project(main_sem3)

set(CMAKE_CXX_STANDARD 14)

add_executable(typetraits iterator.h main.cpp node.h slist.h dlist.h)