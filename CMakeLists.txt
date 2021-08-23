cmake_minimum_required(VERSION 3.20)
project(Motifs)

set(CMAKE_CXX_STANDARD 23)

file(GLOB PATTERN_FILES patterns/*.cpp)
add_executable(Motifs main.cpp Grid.cpp ${PATTERN_FILES})
target_link_libraries(Motifs SDL2)
