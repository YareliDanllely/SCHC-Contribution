cmake_minimum_required(VERSION 3.24)
project(SCHC_Contribution)

link_libraries(ws2_32 wsock32)

set(CMAKE_CXX_STANDARD 17)

#Add executable to test
add_executable(castingTest Google_tests/castingTest.cpp)

##
# Specifies include directories
##

target_include_directories (
        castingTest
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

##
# Include directories
# Used for adding headers search paths
##

include_directories(utils)


##
# Add subdirectories to the build.
##
add_subdirectory(utils)
add_subdirectory(Google_tests)
add_subdirectory(Client-Server-App)

##
# Add target link
##

target_link_libraries(castingTest utils)