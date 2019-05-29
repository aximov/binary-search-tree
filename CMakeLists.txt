cmake_minimum_required(VERSION 3.14)
project(binary_search_tree)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(binary_search_tree
        BinarySearchTree.hh
        main.cc)
