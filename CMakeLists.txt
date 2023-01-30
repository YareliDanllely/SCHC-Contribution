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
add_executable(ruleTest Google_tests/Entities/ruleTest.cpp)
add_executable(sigFoxProfileTest Google_tests/Entities/sigFoxProfileTest.cpp)
add_executable(headerTest Google_tests/Messages/headerTest.cpp)
add_executable(fragmentHeaderTest Google_tests/Messages/fragmentHeaderTest.cpp)
add_executable(ACKHeaderTest Google_tests/Messages/ACKHeaderTest.cpp)
add_executable(fragmentTest Google_tests/Messages/fragmentTest.cpp)
add_executable(senderAbortTest Google_tests/Messages/senderAbortTest.cpp)
add_executable(ACKTest Google_tests/Messages/ACKTest.cpp)






##
# Include directories
# Used for adding headers search paths
##

include_directories(utils)
include_directories(config)
include_directories(sockets)
include_directories(db)
include_directories(Entities)
include_directories(Messages)

##
# Add subdirectories to the build.
##
add_subdirectory(utils)
add_subdirectory(Google_tests)
add_subdirectory(Client-Server-App)
add_subdirectory(config)
add_subdirectory(sockets)
add_subdirectory(db)
add_subdirectory(Entities)
add_subdirectory(Messages)


