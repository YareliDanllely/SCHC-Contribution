project(utils)

set(HEADER_FILES
        casting.h)

set(HEADER_FILES
        casting.cpp)

add_library(utils STATIC ${SOURCE_FILES} ${HEADER_FILES})