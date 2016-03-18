file (GLOB APP_SOURCES 
		"*.h"
		"*.cpp")

# Additional include directories
include_directories(${CMAKE_SOURCE_DIR}/dependencies/DarcEngine/Src)

# Additional Library Directories
link_directories(${CMAKE_SOURCE_DIR}/dependencies/DarcEngine/_build/lib)

# Create executable
add_executable(App ${APP_SOURCES})

# Additional dependencies
target_link_libraries(App Engine Graphics)