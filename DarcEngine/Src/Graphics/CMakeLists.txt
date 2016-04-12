file (GLOB GRAPHICS_SOURCES 
		"*.h"
		"*.cpp")

# Additional include directories
include_directories(${CMAKE_SOURCE_DIR}/Dependencies/OpenGl/include) # OpenGl
#include_directories(${CMAKE_SOURCE_DIR}/Src)

add_library(Graphics STATIC ${GRAPHICS_SOURCES})

# For copy dlls
# install (TARGETS Graphics RUNTIME DESTINATION "${PROJECT_BINARY_DIR}/bin")

# For copy .lib
install (TARGETS Graphics DESTINATION "${PROJECT_BINARY_DIR}/lib")