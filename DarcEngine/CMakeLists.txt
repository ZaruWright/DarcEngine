cmake_minimum_required(VERSION 2.6)

# Maps to Visual Studio solution file (Tutorial.sln)
# The solution will have all targets (exe, lib, dll) 
# as Visual Studio projects (.vcproj)
project("Darc Engine")

# Set flags to linux compiler
message ("---CMAKE_SYSTEM_NAME " ${CMAKE_SYSTEM_NAME})
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wwrite-strings -std=c++11")
	message("---CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS})
endif()

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Showing verbose info
set(CMAKE_VERBOSE_MAKEFILE on)

# Create a Projects Directory
#file(MAKE_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR}/Projects)
#file(MAKE_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR}/bin)

# Sub-directories where more CMakeLists.txt exists
add_subdirectory(Src)