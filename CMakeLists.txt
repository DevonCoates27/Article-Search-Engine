cmake_minimum_required(VERSION 3.15)
project(FinalProjExamples)

# filesystem.h require C++17
set(CMAKE_CXX_STANDARD 17)

file(COPY sample_data/ DESTINATION sample_data/)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic -g)

add_executable(supersearch rapidJSONExample.cpp AVLTree.h IndexHandler.h IndexHandler.cpp DocumentParser.cpp DocumentParser.h AVLMap.h Word.cpp Word.h documentID.cpp documentID.h UserInterface.cpp UserInterface.h AVLMap.cpp porter2_stemmer-master/porter2_stemmer.h porter2_stemmer-master/porter2_stemmer.cpp)

# this makes sure we also link rapidjson
target_include_directories(supersearch PRIVATE rapidjson/)



set(CMAKE_VERBOSE_MAKEFILE OFF)
# testing with the single_include versions of Catch2 V2 (in directory catch2)
include(CTest)
add_executable(tests test.cpp AVLTree.h DocumentParser.cpp DocumentParser.h AVLMap.h Word.cpp Word.h IndexHandler.cpp IndexHandler.h documentID.cpp documentID.h AVLMap.cpp porter2_stemmer-master/porter2_stemmer.h porter2_stemmer-master/porter2_stemmer.cpp)
add_test(NAME SimpleTest COMMAND tests)

