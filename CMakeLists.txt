cmake_minimum_required(VERSION 3.16)
project(Graphs C)

set(CMAKE_C_STANDARD 99)

add_library(Graphs basic.c basic.h DepthFirst.c DepthFirst.h main.c BreadthFirst.c BreadthFirst.h Queue.c Queue.h TopologicalSort.c TopologicalSort.h DijkstraSPA.c DijkstraSPA.h)