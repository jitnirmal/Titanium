set(IO_SRCS
	FileReader.h
	FileReader.cpp
)

# Declare the library
add_library(IO STATIC
    ${IO_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(IO PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
