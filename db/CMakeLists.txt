
project(db)

set(HEADER_FILES
        FileStorage.h
        CommonFileStorage.h
        )

set(SOURCE_FILES
        FileStorage.cpp
        CommonFileStorage.cpp
        )


add_library(db STATIC ${SOURCE_FILES} ${HEADER_FILES})
add_executable(ComonFile CommonFileStorage.cpp)

