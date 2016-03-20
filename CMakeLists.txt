cmake_minimum_required(VERSION 2.6)

project("Game")

# Set flags to linux compiler
message ("---CMAKE_SYSTEM_NAME " ${CMAKE_SYSTEM_NAME})
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wwrite-strings -std=c++11")
	message("---CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS})
endif()

add_subdirectory("Src")