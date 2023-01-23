project(Entities)

set(HEADER_FILES
        Header.h
        FragmentHeader.h
        )

set(SOURCE_FILES
        Header.cpp
        FragmentHeader.cpp
        )

add_library(Messages STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(Messages utils)
target_link_libraries(Messages Entities)

