# - Find gflags
# Find the gflags compression library and includes
#
# GFLAGS_INCLUDE_DIR - where to find gflags.h, etc.
# GFLAGS_LIBRARIES - List of libraries when using gflags.
# GFLAGS_FOUND - True if gflags found.

if (NOT GFLAGS_ROOT_DIR)
  set (GFLAGS_ROOT_DIR "/home/vinit/install/gflags-master/Release")
endif()

find_path(gflags_INCLUDE_DIR
  NAMES gflags/gflags.h
  HINTS ${GFLAGS_ROOT_DIR}/include)

find_path(gflags_LIB_DIR
  NAMES "libgflags.so"
  HINTS ${GFLAGS_ROOT_DIR}/lib)
#message(${gflags_LIB_DIR})

find_library(gflags_LIBRARIES
  NAMES gflags 
  PATHS ${GFLAGS_ROOT_DIR}/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(gflags DEFAULT_MSG gflags_LIBRARIES gflags_INCLUDE_DIR)

mark_as_advanced(
  gflags_LIBRARIES
  gflags_INCLUDE_DIR)
