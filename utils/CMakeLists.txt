project(utils)

set(HEADER_FILES
        casting.h
        misc.h
        )

set(HEADER_FILES
        casting.cpp
        misc.cpp
        )



add_library(utils STATIC ${SOURCE_FILES} ${HEADER_FILES})
