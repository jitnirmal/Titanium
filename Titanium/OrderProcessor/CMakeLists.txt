set(OrderProcessor_SRCS
    Order.cpp
	Order.h
	OrderBook.cpp
	OrderBook.h
	OrderDef.cpp
	OrderDef.h
	OrderMatcher.cpp
	OrderMatcher.h
	Trade.cpp
	Trade.h
)

# Declare the library
add_library(OrderProcessor STATIC
    ${OrderProcessor_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(  OrderProcessor
	Instrument
	Util
)

# Specify here the include directories exported
# by this library
target_include_directories(OrderProcessor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
