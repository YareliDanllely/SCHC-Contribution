cmake_minimum_required(VERSION 3.24)
project(SCHC_Contribution)

link_libraries(ws2_32 wsock32)

set(CMAKE_CXX_STANDARD 17)

#Add executable to test
add_executable(castingTest Google_tests/utils/castingTest.cpp)
add_executable(miscTest Google_tests/utils/miscTest.cpp)
add_executable(nestedDictTest Google_tests/utils/nestedDictTest.cpp)
add_executable(sigFoxSocketTest Google_tests/sockets/sigFoxSocketTest.cpp)
add_executable(dbTest Google_tests/db/dbTest.cpp)
##
# Specifies include directories
##

target_include_directories (
        castingTest
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_include_directories (
        miscTest
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_include_directories (
        nestedDictTest
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_include_directories (
        sigFoxSocketTest
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/sockets
)


##
# Include directories
# Used for adding headers search paths
##

include_directories(utils)
include_directories(config)
include_directories(sockets)
include_directories(db)

##
# Add subdirectories to the build.
##
add_subdirectory(utils)
add_subdirectory(Google_tests)
add_subdirectory(Client-Server-App)
add_subdirectory(config)
add_subdirectory(sockets)
add_subdirectory(db)

##
# Add target link
##

target_link_libraries(castingTest utils)
target_link_libraries(miscTest utils)
target_link_libraries(nestedDictTest utils)
target_link_libraries(sigFoxSocketTest sockets)
target_link_libraries(dbTest db)

