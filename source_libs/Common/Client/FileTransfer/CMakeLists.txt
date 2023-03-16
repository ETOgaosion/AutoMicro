CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET (CMAKE_CXX_STANDARD 20)

AUX_SOURCE_DIRECTORY(. SRC)

ADD_LIBRARY(file-transfer-client OBJECT ${SRC})

target_include_directories(file-transfer-client PRIVATE 
    ../../Common/libgen 
    ../../Common/File/Messages 
    ../../Common/File/SequentialOps 
    ../../Common/File/utils 
    ../../Common/File)