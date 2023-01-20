project(Entities)

set(HEADER_FILES
        Rule.h
        SigFoxProfile.h
        )

set(SOURCE_FILES
       Rule.cpp
        SigFoxProfile.cpp
        )


add_library(Entities STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(Entities utils)
