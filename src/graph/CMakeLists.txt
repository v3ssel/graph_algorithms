cmake_minimum_required(VERSION 3.5)
project(graph LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_compile_options(-Wall -Werror -Wextra)

set(${PROJECT_NAME}_SOURCES 
    graph.cc
    graph.h
)

add_library(${PROJECT_NAME} STATIC
    ${${PROJECT_NAME}_SOURCES}
)


project(graph_algorithms LANGUAGES CXX)

set(${PROJECT_NAME}_ALG_SOURCES 
    graph_algorithms.cc
    graph_algorithms.h
    TSM/AntColonyTSM.cc
    TSM/AntColonyTSM.h
    TSM/GeneticTSM.cc
    TSM/GeneticTSM.h
    TSM/BranchesAndBoundsTSM.cc
    TSM/BranchesAndBoundsTSM.h
    ../containers/queue.h
    ../containers/stack.h
)
    
add_library(${PROJECT_NAME} STATIC
    ${${PROJECT_NAME}_ALG_SOURCES}
    ${PROJECT_NAME}
)
   