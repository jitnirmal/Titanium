set(OrderProcessor_SRCS
    Order.h
    Order.cpp
)

# Declare the library
add_library(OrderProcessor STATIC
    ${OrderProcessor_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(OrderProcessor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
