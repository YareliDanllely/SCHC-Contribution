project(Entities)
include(FetchContent)

set(HEADER_FILES
        Header.h
        FragmentHeader.h
        ACKHeader.h
        Fragment.h
        SenderAbort.h
        )

set(SOURCE_FILES
        Header.cpp
        FragmentHeader.cpp
        ACKHeader.cpp
        Fragment.cpp
        SenderAbort.cpp
        )

include_directories(${json_SOURCE_DIR}/include)


add_library(Messages STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(Messages utils)
target_link_libraries(Messages Entities)



