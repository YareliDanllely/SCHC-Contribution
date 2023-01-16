project(utils)

set(HEADER_FILES
        Socket.h
        sigFoxClient.h
        sigFoxServer.h
        )

set(SOURCE_FILES
        Socket.cpp
        sigFoxClient.cpp
        sigFoxServer.cpp
        )


add_library(sockets STATIC ${SOURCE_FILES} ${HEADER_FILES})
add_executable(sigFoxServer sigFoxServer.cpp)