set(MDFeed_SRCS
    MData.h
    MData.cpp
)

# Declare the library
add_library(MDFeed STATIC
    ${MDFeed_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(MDFeed PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
