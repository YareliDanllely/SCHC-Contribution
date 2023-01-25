# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})



target_link_libraries(castingTest  gtest gtest_main)
target_link_libraries(castingTest utils)


target_link_libraries(miscTest  gtest gtest_main)
target_link_libraries(miscTest utils)

target_link_libraries(nestedDictTest  gtest gtest_main)
target_link_libraries(nestedDictTest utils)

target_link_libraries(sigFoxSocketTest  gtest gtest_main)
target_link_libraries(sigFoxSocketTest sockets)

target_link_libraries(dbTest  gtest gtest_main)
target_link_libraries(dbTest db)

target_link_libraries(ruleTest  gtest gtest_main)
target_link_libraries(ruleTest Entities)

target_link_libraries(sigFoxProfileTest  gtest gtest_main)
target_link_libraries(sigFoxProfileTest Entities)

target_link_libraries(headerTest  gtest gtest_main)
target_link_libraries(headerTest Messages)

target_link_libraries(fragmentHeaderTest  gtest gtest_main)
target_link_libraries(fragmentHeaderTest Messages)

target_link_libraries(ACKHeaderTest  gtest gtest_main)
target_link_libraries(ACKHeaderTest Messages)

target_link_libraries(fragmentTest  gtest gtest_main)
target_link_libraries(fragmentTest Messages)

target_link_libraries(senderAbortTest  gtest gtest_main)
target_link_libraries(senderAbortTest Messages)