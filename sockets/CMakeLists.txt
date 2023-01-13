project(utils)

set(HEADER_FILES
        Socket.h
        )

set(HEADER_FILES
        socket.cpp
        SigfoxSocket.cpp
        )


add_library(sockets STATIC ${SOURCE_FILES} ${HEADER_FILES})