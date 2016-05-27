file (GLOB APP_SOURCES 
		"*.h"
		"*.cpp")

# Additional include directories
include_directories(${CMAKE_SOURCE_DIR}/DarcEngine/Src)

# Additional Library Directories
#link_directories(${CMAKE_SOURCE_DIR}/DarcEngine/_build/lib/Release)
#link_directories(${CMAKE_SOURCE_DIR}/DarcEngine/_build/lib/Debug)

set(DARC_DEBUG_LIBS_URL ${CMAKE_SOURCE_DIR}/DarcEngine/_build/lib/Debug)
set(DARC_RELEASE_LIBS_URL ${CMAKE_SOURCE_DIR}/DarcEngine/_build/lib/Release)

link_directories(${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib) # OpenGl
link_directories(${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib) # OpenGl

# Adding Darc libraries
add_library(Engine STATIC IMPORTED)
add_library(Graphics STATIC IMPORTED)
add_library(Utilities STATIC IMPORTED)
add_library(Application STATIC IMPORTED)

# Adding OpenGl library
add_library(stGLUT STATIC IMPORTED)

# Adding GLFW library
add_library(glfw STATIC IMPORTED)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	
	# Set Darc libraries dependencies
	set_target_properties(Engine PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/Engine_d.lib)
	set_target_properties(Graphics PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/Graphics_d.lib)
	set_target_properties(Utilities PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/Utilities_d.lib)
	set_target_properties(Application PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/Application_d.lib)

	set_target_properties(Engine PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/Engine.lib)
	set_target_properties(Graphics PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/Graphics.lib)
	set_target_properties(Utilities PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/Utilities.lib)
	set_target_properties(Application PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/Application.lib)

	set_property(TARGET stGLUT PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/glut32.lib)
	# Copy OpenGl Dll
	install (FILES ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/glut32.dll DESTINATION "${PROJECT_BINARY_DIR}/bin/Debug")
	install (FILES ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/glut32.dll DESTINATION "${PROJECT_BINARY_DIR}/bin/Release")

	set_target_properties(glfw PROPERTIES IMPORTED_LOCATION_DEBUG ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib/glfw3_d.lib)
	set_target_properties(glfw PROPERTIES IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib/glfw3.lib)

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	# Set Darc libraries dependencies
	set_target_properties(Engine PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/libEngine_d.a)
	set_target_properties(Graphics PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/libGraphics_d.a)
	set_target_properties(Utilities PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/libUtilities_d.a)
	set_target_properties(Application PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/libApplication_d.a)

	set_target_properties(Engine PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/libEngine.a)
	set_target_properties(Graphics PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/libGraphics.a)
	set_target_properties(Utilities PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/libUtilities.a)
	set_target_properties(Application PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/libApplication.a)

	set_property(TARGET stGLUT PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/libglut.a)
	install (FILES ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/OpenGl/lib/libglut.3.6.so DESTINATION "${PROJECT_BINARY_DIR}/bin")

	set_property(TARGET glfw PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib/libglfw3.a)	
	# Copy glfw debug and release
	#install (FILES ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib/libglfw3.a DESTINATION "${PROJECT_BINARY_DIR}/bin/Debug")

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

	# Set Darc libraries dependencies
	set_target_properties(Engine PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/libEngine_d.a)
	set_target_properties(Graphics PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/libGraphics_d.a)
	set_target_properties(Utilities PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/libUtilities_d.a)
	set_target_properties(Application PROPERTIES IMPORTED_LOCATION_DEBUG ${DARC_DEBUG_LIBS_URL}/libApplication_d.a)

	set_target_properties(Engine PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/libEngine.a)
	set_target_properties(Graphics PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/libGraphics.a)
	set_target_properties(Utilities PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/libUtilities.a)
	set_target_properties(Application PROPERTIES IMPORTED_LOCATION_RELEASE ${DARC_RELEASE_LIBS_URL}/libApplication.a)

	find_library(OPEN_GL_OSX OpenGL)
	if (NOT OPEN_GL_OSX)
		message("--- FATAL ERROR: OpenGL not found")
	endif()

	find_library(GLUT_OSX GLUT)
	if (NOT GLUT_OSX)
		message("--- FATAL ERROR: GLUT not found")
	endif()	

	set_target_properties(glfw PROPERTIES IMPORTED_LOCATION_DEBUG ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib/libglfw3_mac_d.a)
	set_target_properties(glfw PROPERTIES IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/DarcEngine/Dependencies/GLFW/lib/libglfw3_mac.a)

endif()

# Create executable
add_executable(App ${APP_SOURCES})
message ("---CMAKE_BUILD_TYPE " ${CMAKE_BUILD_TYPE})

# Additional dependencies
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")

	target_link_libraries(App Engine Graphics Utilities Application stGLUT opengl32.lib glu32.lib glfw)

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	#target_link_libraries(App Engine Graphics Utilities Application glfw stGLUT X11 GL GLU Xi Xmu Xxf86vm Xrandr Xinerama Xcursor rt )
	 #target_link_libraries(App debug libEngine_d.a libGraphics_d.a libUtilities_d.a libApplication_d.a glfw X11 Xrandr Xinerama Xi Xxf86vm Xcursor GL dl pthread)
	 #target_link_libraries(App optimized libEngine.a libGraphics.a libUtilities.a libApplication.a glfw X11 Xrandr Xinerama Xi Xxf86vm Xcursor GL dl pthread)

	 target_link_libraries(App Engine Graphics Utilities Application glfw X11 Xrandr Xinerama Xi Xxf86vm Xcursor GL dl pthread)

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	#target_link_libraries(App debug libEngine_d.a libGraphics_d.a libUtilities_d.a libApplication_d.a glfwDebug "-framework cocoa" "-framework OpenGL" "-framework IOKit" "-framework CoreVideo")  
	#target_link_libraries(App optimized libEngine.a libGraphics.a libUtilities.a libApplication.a glfwRelease "-framework cocoa" "-framework OpenGL" "-framework IOKit" "-framework CoreVideo")
	
	target_link_libraries(App Engine Graphics Utilities Application glfw "-framework cocoa" "-framework OpenGL" "-framework IOKit" "-framework CoreVideo")	

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