
# Try to find the Google Boost library and headers.
#  Boost_FOUND        - system has benchmark lib
#  Boost_INCLUDE_DIRS - the benchmark include directory
#  Boost_LIBRARIES    - libraries needed to use benchmark
if (Boost_FOUND)
    return()
endif(Boost_FOUND)

if (NOT Boost_ROOT)
    set(Boost_ROOT "/home/vinit/install/boost/Release")
endif(NOT Boost_ROOT)

message("${Boost_ROOT}")

find_path(Boost_INCLUDE_DIR
  NAMES boost/locale.hpp
  HINTS "${Boost_ROOT}/include"
)

find_path(Boost_LIB_DIR
  NAMES libboost_system.so
  HINTS "${Boost_ROOT}/lib"
)

message("${Boost_LIB_DIR}")

find_library(Boost_SYSTEM_LIBRARY
  NAMES boost_system 
  HINTS ${Boost_LIB_DIR} 
)

find_library(Boost_THREAD_LIBRARY
  NAMES boost_thread 
  HINTS ${Boost_LIB_DIR} 
)

find_library(Boost_TIMER_LIBRARY
  NAMES boost_timer 
  HINTS ${Boost_LIB_DIR} 
)

find_library(Boost_CHRONO_LIBRARY
  NAMES boost_chrono 
  HINTS ${Boost_LIB_DIR} 
)

find_library(Boost_REGEX_LIBRARY
  NAMES boost_regex 
  HINTS ${Boost_LIB_DIR} 
)

find_library(Boost_LOG_LIBRARY
  NAMES boost_log 
  HINTS ${Boost_LIB_DIR} 
)

find_library(Boost_FS_LIBRARY
  NAMES boost_filesystem 
  HINTS ${Boost_LIB_DIR} 
)

find_library(Boost_PO_LIBRARY
  NAMES boost_program_options 
  HINTS ${Boost_LIB_DIR} 
)

set(Boost_INCLUDE_DIRS ${Boost_INCLUDE_DIR})
set(Boost_LIBRARIES    ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_CHRONO_LIBRARY} 
  ${Boost_REGEX_LIBRARY} ${Boost_LOG_LIBRARY} ${Boost_FS_LIBRARY} ${Boost_PO_LIBRARY}
)
#message(${Boost_LIBRARIES})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Boost
  FOUND_VAR Boost_FOUND
  REQUIRED_VARS Boost_INCLUDE_DIR Boost_LIBRARIES
)

mark_as_advanced(Boost_FOUND)

