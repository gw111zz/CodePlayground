cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)

project(Pimpl)

include_directories ("${PROJECT_SOURCE_DIR}")

add_executable(MyClient MyClient.cpp MyLibObject.cpp)


