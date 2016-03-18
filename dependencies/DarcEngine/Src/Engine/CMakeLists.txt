file (GLOB ENGINE_SOURCES 
		"*.h"
		"*.cpp")

add_library(Engine STATIC ${ENGINE_SOURCES})

# For copy .lib
install (TARGETS Engine DESTINATION "${PROJECT_BINARY_DIR}/lib")