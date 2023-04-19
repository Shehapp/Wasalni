cmake_minimum_required(VERSION 3.25)
project(dataBaseProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(dataBaseProject main.cpp classes/GraphComponent/Node.cpp classes/GraphComponent/Node.h classes/GraphComponent/Point.cpp classes/GraphComponent/Point.h classes/GraphComponent/Graph.cpp classes/GraphComponent/Graph.h classes/Algorithm/ShortPathAlgorithm.cpp classes/Algorithm/ShortPathAlgorithm.h classes/Algorithm/Dfs.cpp classes/Algorithm/Dfs.h classes/Algorithm/Floyd.cpp classes/Algorithm/Floyd.h classes/Algorithm/Dijkstra.cpp classes/Algorithm/Dijkstra.h classes/Application/App.cpp classes/Application/App.h)
