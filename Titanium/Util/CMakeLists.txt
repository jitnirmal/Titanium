set(Util_SRCS
    ObjectId.h
	Singleton.h
	Singleton.cpp
	Observer.h
	Visitor.h
	Factory.h
    ObjectId.cpp
	Util.h
	Util.cpp
)

# Declare the library
add_library(Util STATIC
    ${Util_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(Util PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
