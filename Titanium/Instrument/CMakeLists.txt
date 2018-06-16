set(Instrument_SRCS
    Instrument.h
    Instrument.cpp
)

# Declare the library
add_library(Instrument STATIC
    ${Instrument_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(Instrument PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
