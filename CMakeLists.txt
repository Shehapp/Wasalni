cmake_minimum_required(VERSION 3.25)
project(dataBaseProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(dataBaseProject main.cpp classes/Node.cpp classes/Node.h classes/Point.cpp classes/Point.h classes/Edge.cpp classes/Edge.h classes/Graph.cpp classes/Graph.h classes/Algorithm/ShortPathAlgorithm.cpp classes/Algorithm/ShortPathAlgorithm.h classes/Algorithm/Dfs.cpp classes/Algorithm/Dfs.h classes/Algorithm/Floyd.cpp classes/Algorithm/Floyd.h classes/Algorithm/Dijkstra.cpp classes/Algorithm/Dijkstra.h)
