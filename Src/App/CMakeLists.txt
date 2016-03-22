file (GLOB APP_SOURCES 
		"*.h"
		"*.cpp")

# Additional include directories
include_directories(${CMAKE_SOURCE_DIR}/DarcEngine/Src)

# Additional Library Directories
link_directories(${CMAKE_SOURCE_DIR}/DarcEngine/_build/lib)
link_directories(${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib) # OpenGl

# Adding OpenGl library
add_library(stOpenGl STATIC IMPORTED)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set_property(TARGET stOpenGl PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/glut32.lib)
	# Copy OpenGl Dll
	install (FILES ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/glut32.dll DESTINATION "${PROJECT_BINARY_DIR}/bin")

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set_property(TARGET stOpenGl PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/libglut.a)
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

# Additional dependencies
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	target_link_libraries(App Engine Graphics stOpenGl opengl32.lib glu32.lib)

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	target_link_libraries(App Engine Graphics stOpenGl X11 GL GLU)

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	target_link_libraries(App Engine Graphics ${OPEN_GL_OSX} ${GLUT_OSX})

endif()

# Install
install (TARGETS App DESTINATION "${PROJECT_BINARY_DIR}/bin")

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	# Configure the template file
	# We use this to update the project settings of visual studio
	SET(USER_FILE App.vcxproj.user)
	SET(DEBUG_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
	CONFIGURE_FILE(App.user ${USER_FILE} @ONLY)
endif()