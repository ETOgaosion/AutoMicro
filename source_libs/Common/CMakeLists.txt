CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET (CMAKE_CXX_STANDARD 20)

add_subdirectory(File)
add_subdirectory(libgen)
add_subdirectory(redis)
add_subdirectory(utility)

add_library(common-library STATIC
$<TARGET_OBJECTS:file>
$<TARGET_OBJECTS:libgen>
$<TARGET_OBJECTS:utility_common>
$<TARGET_OBJECTS:redis>)

find_package(OpenSSL REQUIRED)

target_link_libraries(common-library str gflags glog log stdc++fs time yaml-cpp pthread unwind OpenSSL::Crypto ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})

target_include_directories(common-library PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_include_directories(common-library PUBLIC
    Threads::Threads
)

# <------------ add hiredis dependency here --------------->
find_path(HIREDIS_HEADER hiredis)
target_include_directories(common-library PUBLIC ${HIREDIS_HEADER})

find_library(HIREDIS_LIB hiredis)
target_link_libraries(common-library ${HIREDIS_LIB})

# <------------ add redis-plus-plus dependency here -------------->
find_path(REDIS_PLUS_PLUS_HEADER sw)      # NOTE: this should be *sw* NOT *redis++*
target_include_directories(common-library PUBLIC ${REDIS_PLUS_PLUS_HEADER})

find_library(REDIS_PLUS_PLUS_LIB redis++)
target_link_libraries(common-library ${REDIS_PLUS_PLUS_LIB})

target_link_libraries(common-library Eigen3::Eigen)