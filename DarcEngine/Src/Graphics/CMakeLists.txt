file (GLOB GRAPHICS_SOURCES 
		"*.h"
		"*.cpp")

# Additional include directories
include_directories(${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include) # GLFW
include_directories(${CMAKE_SOURCE_DIR}/Dependencies/GLFW/deps) # GLFW
include_directories(${CMAKE_SOURCE_DIR}/Dependencies/OpenGl/include) # OpenGl
include_directories(${CMAKE_SOURCE_DIR}/Src)

add_library(Graphics STATIC ${GRAPHICS_SOURCES})
set_target_properties(Graphics PROPERTIES DEBUG_POSTFIX "_d")

# For copy dlls
# install (TARGETS Graphics RUNTIME DESTINATION "${PROJECT_BINARY_DIR}/bin")

# For copy .lib
install (TARGETS Graphics DESTINATION "${PROJECT_BINARY_DIR}/lib/Debug" CONFIGURATIONS "Debug")
install (TARGETS Graphics DESTINATION "${PROJECT_BINARY_DIR}/lib/Release" CONFIGURATIONS "Release")
