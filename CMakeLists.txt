cmake_minimum_required(VERSION 3.24)
project(SCHC_Contribution)

set(CMAKE_CXX_STANDARD 17)

link_libraries(ws2_32 wsock32)

##
# Add subdirectories to the build.
##

add_subdirectory(Client-Server-App)