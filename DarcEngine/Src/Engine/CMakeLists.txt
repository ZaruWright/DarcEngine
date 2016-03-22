file (GLOB ENGINE_SOURCES 
		"*.h"
		"*.cpp")

# Additional include directories
include_directories(${CMAKE_SOURCE_DIR}/Src)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	include_directories(/System/Library/Frameworks/GLUT.framework/Headers) # OpenGl

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows" OR
	  ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	include_directories(${CMAKE_SOURCE_DIR}/Dependencies/OpenGl/include) # OpenGl

endif()

add_library(Engine STATIC ${ENGINE_SOURCES})

# For copy .lib
install (TARGETS Engine DESTINATION "${PROJECT_BINARY_DIR}/lib")