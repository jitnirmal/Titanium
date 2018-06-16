
# Try to find the Google Zmq library and headers.
#  Zmq_FOUND        - system has Zmq lib
#  Zmq_INCLUDE_DIRS - the Zmq include directory
#  Zmq_LIBRARIES    - libraries needed to use Zmq
if (Zmq_FOUND)
    return()
endif(Zmq_FOUND)

if (NOT Zmq_ROOT)
    set(Zmq_ROOT "/home/vinit/install/libzmq-master/Release")
endif(NOT Zmq_ROOT)

find_path(Zmq_INCLUDE_DIR
  NAMES zmq.h
  HINTS "${Zmq_ROOT}/include"
)

find_path(Zmq_LIB_DIR
  NAMES libzmq.so
  HINTS "${Zmq_ROOT}/lib"
)

find_library(Zmq_LIBRARY
  NAMES libzmq.so
  HINTS "${Zmq_ROOT}/lib"
)

set(Zmq_INCLUDE_DIRS ${Zmq_INCLUDE_DIR})
set(Zmq_LIBRARIES    ${Zmq_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Zmq
  FOUND_VAR Zmq_FOUND
  REQUIRED_VARS Zmq_INCLUDE_DIR Zmq_LIBRARY
)

mark_as_advanced(Zmq_FOUND)

