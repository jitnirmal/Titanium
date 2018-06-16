set(OrderInterface_SRCS
    OrderEvtIn.h
	OrderEvtIn.cpp
	OrderEvtOut.h
	OrderEvtOut.cpp
	FileReader.h
	FileReader.cpp
	OrderStore.h
	OrderStore.cpp
)

# Declare the library
add_library(OrderInterface STATIC
    ${OrderInterface_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(  OrderInterface
	OrderProcessor
	Core
	Util
)

# Specify here the include directories exported
# by this library
target_include_directories(OrderInterface PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
