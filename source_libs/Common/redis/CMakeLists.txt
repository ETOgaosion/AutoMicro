CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET (CMAKE_CXX_STANDARD 20)

AUX_SOURCE_DIRECTORY(. SRC)

file(GLOB HDR "*.h")

ADD_LIBRARY(redis OBJECT ${SRC} ${HDR})

target_include_directories(redis PRIVATE
    ../libgen
    ../tools
)

target_include_directories(redis PUBLIC
)

# <------------ add hiredis dependency here --------------->
find_path(HIREDIS_HEADER hiredis)
target_include_directories(redis PUBLIC ${HIREDIS_HEADER})

find_library(HIREDIS_LIB hiredis)
target_link_libraries(redis ${HIREDIS_LIB})

# <------------ add redis-plus-plus dependency here -------------->
find_path(REDIS_PLUS_PLUS_HEADER sw)      # NOTE: this should be *sw* NOT *redis++*
target_include_directories(redis PUBLIC ${REDIS_PLUS_PLUS_HEADER})

find_library(REDIS_PLUS_PLUS_LIB redis++)
target_link_libraries(redis ${REDIS_PLUS_PLUS_LIB})