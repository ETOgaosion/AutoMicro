CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET (CMAKE_CXX_STANDARD 20)

AUX_SOURCE_DIRECTORY(. SRC)

include_directories(../../libgen/)
include_directories(../Messages)
include_directories(../utils)

ADD_LIBRARY(sequentialops OBJECT ${SRC})
