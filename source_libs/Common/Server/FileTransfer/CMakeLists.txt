cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)

aux_source_directory(. SRC)

add_library(file-transfer-server OBJECT ${SRC})

target_include_directories(file-transfer-server PRIVATE 
    ../../Common/libgen 
    ../../Common/File/Messages 
    ../../Common/File/SequentialOps 
    ../../Common/File/utils 
    ../../Common/File)