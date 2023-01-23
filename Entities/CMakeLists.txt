project(Entities)

set(HEADER_FILES
        Rule.h
        SigFoxProfile.h
        exceptions.h
        )

set(SOURCE_FILES
       Rule.cpp
        SigFoxProfile.cpp
        exceptions.cpp
        )


add_library(Entities STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(Entities utils)
