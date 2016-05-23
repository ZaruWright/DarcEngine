file (GLOB UTILITIES_SOURCES 
		"*.h"
		"*.cpp")

# Additional include directories
# include_directories(${CMAKE_SOURCE_DIR}/Src)

add_library(Utilities STATIC ${UTILITIES_SOURCES})
set_target_properties(Utilities PROPERTIES DEBUG_POSTFIX "_d")

# For copy dlls
# install (TARGETS Utilities RUNTIME DESTINATION "${PROJECT_BINARY_DIR}/bin")

# For copy .lib
install (TARGETS Utilities DESTINATION "${PROJECT_BINARY_DIR}/lib/Debug" CONFIGURATIONS "Debug")
install (TARGETS Utilities DESTINATION "${PROJECT_BINARY_DIR}/lib/Release" CONFIGURATIONS "Release")