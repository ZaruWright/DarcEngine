file (GLOB ENGINE_SOURCES 
		"*.h"
		"*.cpp")

# Additional include directories
include_directories(${CMAKE_SOURCE_DIR}/Src)
include_directories(${CMAKE_SOURCE_DIR}/Dependencies/OpenGl/include) # OpenGl

add_library(Engine STATIC ${ENGINE_SOURCES})

# For copy .lib
install (TARGETS Engine DESTINATION "${PROJECT_BINARY_DIR}/lib")