cmake_minimum_required(VERSION 3.24)
project(Client_Server_App)


set(CMAKE_CXX_STANDARD 17)

add_executable(Client Client.cpp)
add_executable(Server Server.cpp)
