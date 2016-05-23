file (GLOB APP_SOURCES 
		"*.h"
		"*.cpp")

# Additional include directories
include_directories(${CMAKE_SOURCE_DIR}/DarcEngine/Src)

# Additional Library Directories
link_directories(${CMAKE_SOURCE_DIR}/DarcEngine/_build/lib/Release)
link_directories(${CMAKE_SOURCE_DIR}/DarcEngine/_build/lib/Debug)
link_directories(${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib) # OpenGl
link_directories(${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib) # OpenGl

# Adding OpenGl library
add_library(stGLUT STATIC IMPORTED)

# Adding GLFW library
add_library(glfwDebug STATIC IMPORTED)
add_library(glfwRelease STATIC IMPORTED)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set_property(TARGET stGLUT PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/glut32.lib)
	# Copy OpenGl Dll
	install (FILES ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/glut32.dll DESTINATION "${PROJECT_BINARY_DIR}/bin/Debug")
	install (FILES ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/glut32.dll DESTINATION "${PROJECT_BINARY_DIR}/bin/Release")

	set_property(TARGET glfwDebug PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib/glfw3_d.lib)
	set_property(TARGET glfwRelease PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib/glfw3.lib)
	# Copy glfw debug and release
	#install (FILES ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib/glfw3_d.dll DESTINATION "${PROJECT_BINARY_DIR}/bin/Debug")
	#install (FILES ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib/glfw3.dll DESTINATION "${PROJECT_BINARY_DIR}/bin/Debug")

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set_property(TARGET stGLUT PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/libglut.a)
	install (FILES ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/libglut.3.6.so DESTINATION "${PROJECT_BINARY_DIR}/bin")

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

	find_library(OPEN_GL_OSX OpenGL)
	if (NOT OPEN_GL_OSX)
		message("--- FATAL ERROR: OpenGL not found")
	endif()

	find_library(GLUT_OSX GLUT)
	if (NOT GLUT_OSX)
		message("--- FATAL ERROR: GLUT not found")
	endif()	

endif()


# Create executable
add_executable(App ${APP_SOURCES})
message ("---CMAKE_BUILD_TYPE " ${CMAKE_BUILD_TYPE})
# Additional dependencies
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")

	target_link_libraries(App debug Engine_d.lib Graphics_d.lib Utilities_d.lib Application_d.lib stGLUT opengl32.lib glu32.lib glfwDebug)
	target_link_libraries(App optimized Engine.lib Graphics.lib Utilities.lib Application.lib stGLUT opengl32.lib glu32.lib glfwRelease)


elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	target_link_libraries(App Engine Graphics Utilities Application stGLUT X11 GL GLU Xi Xmu)

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	target_link_libraries(App Engine Graphics Utilities Application ${OPEN_GL_OSX} ${GLUT_OSX})

endif()

# Install
install (TARGETS App DESTINATION "${PROJECT_BINARY_DIR}/bin/Release" CONFIGURATIONS "Release")
install (TARGETS App DESTINATION "${PROJECT_BINARY_DIR}/bin/Debug" CONFIGURATIONS "Debug")


if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	# Configure the template file
	# We use this to update the project settings of visual studio
	SET(USER_FILE App.vcxproj.user)
	SET(DEBUG_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin/Debug")
	SET(RELEASE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin/Release")
	CONFIGURE_FILE(App.user ${USER_FILE} @ONLY)
endif()