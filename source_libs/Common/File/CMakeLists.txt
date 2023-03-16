cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Messages)
add_subdirectory(SequentialOps)
# add_subdirectory(tools)
add_subdirectory(utils)

add_library(file OBJECT
$<TARGET_OBJECTS:messages>
$<TARGET_OBJECTS:sequentialops>
$<TARGET_OBJECTS:utils>
# $<TARGET_OBJECTS:file-tools>
FileReaderIntoStream.h)