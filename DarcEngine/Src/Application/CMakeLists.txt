file (GLOB APPLICATION_SOURCES 
		"*.h"
		"*.cpp")

# Additional include directories
# include_directories(${CMAKE_SOURCE_DIR}/Src)

add_library(Application STATIC ${APPLICATION_SOURCES})
set_target_properties(Application PROPERTIES DEBUG_POSTFIX "_d")

# For copy dlls
# install (TARGETS Application RUNTIME DESTINATION "${PROJECT_BINARY_DIR}/bin")

# For copy .lib
install (TARGETS Application DESTINATION "${PROJECT_BINARY_DIR}/lib/Release" CONFIGURATIONS "Release")
install (TARGETS Application DESTINATION "${PROJECT_BINARY_DIR}/lib/Debug" CONFIGURATIONS "Debug")