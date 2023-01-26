project(Messages)


set(HEADER_FILES
        Header.h
        FragmentHeader.h
        ACKHeader.h
        Fragment.h
        )

set(SOURCE_FILES
        Header.cpp
        FragmentHeader.cpp
        ACKHeader.cpp
        Fragment.cpp
        json.hpp
        )



add_library(Messages STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(Messages utils)
target_link_libraries(Messages Entities)



