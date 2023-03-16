CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
SET (CMAKE_CXX_STANDARD 17)

AUX_SOURCE_DIRECTORY(. SRC)
ADD_LIBRARY(utility_common OBJECT ${SRC})

target_include_directories(utility_common PRIVATE 
    ../include
    ../../../iUtility/stdBase/include
    ../../../iUtility
    ../../../third_party
    ../../../iSTA/third-party)

target_link_libraries(utility_common log)
