file (GLOB GRAPHICS_SOURCES 
		"*.h"
		"*.cpp")

add_library(Graphics STATIC ${GRAPHICS_SOURCES})

message ("-----------" ${PROJECT_BINARY_DIR})

# For copy dlls
# install (TARGETS Graphics RUNTIME DESTINATION "${PROJECT_BINARY_DIR}/bin")

# For copy .lib
install (TARGETS Graphics DESTINATION "${PROJECT_BINARY_DIR}/lib")