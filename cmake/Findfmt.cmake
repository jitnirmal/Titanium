
# Try to find the Google fmt library and headers.
#  fmt_FOUND        - system has fmt lib
#  fmt_INCLUDE_DIRS - the fmt include directory
#  fmt_LIBRARIES    - libraries needed to use fmt
if (fmt_FOUND)
    return()
endif(fmt_FOUND)

if (NOT fmt_ROOT)
    set(fmt_ROOT "/home/vinit/install/fmt-4.1.0/Release")
endif(NOT fmt_ROOT)

find_path(fmt_INCLUDE_DIR
  NAMES fmt/format.h
  HINTS "${fmt_ROOT}/include"
)

find_path(fmt_LIB_DIR
  NAMES libfmt.a
  HINTS "${fmt_ROOT}/lib"
)

find_library(fmt_LIBRARY
  NAMES libfmt.a
  HINTS "${fmt_ROOT}/lib"
)

set(fmt_INCLUDE_DIRS ${fmt_INCLUDE_DIR})
set(fmt_LIBRARIES    ${fmt_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(fmt
  FOUND_VAR fmt_FOUND
  REQUIRED_VARS fmt_INCLUDE_DIR fmt_LIBRARY
)

mark_as_advanced(fmt_FOUND)

