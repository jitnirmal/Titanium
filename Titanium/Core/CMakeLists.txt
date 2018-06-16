set(Core_SRCS
	Service.h
	Service.cpp
    Event.h
    Event.cpp
)

# Declare the library
add_library(Core STATIC
    ${Core_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
