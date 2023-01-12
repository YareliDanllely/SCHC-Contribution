project(utils)

set(HEADER_FILES
        schc.h
        )

set(HEADER_FILES
       schc.cpp
        )


add_library(config STATIC ${SOURCE_FILES} ${HEADER_FILES})