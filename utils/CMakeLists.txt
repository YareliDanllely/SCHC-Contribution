project(utils)

set(HEADER_FILES
        casting.h
        misc.h
        nestedDict.h
        )

set(SOURCE_FILES
        casting.cpp
        misc.cpp
        nestedDict.cpp
        )



add_library(utils STATIC ${SOURCE_FILES} ${HEADER_FILES})
