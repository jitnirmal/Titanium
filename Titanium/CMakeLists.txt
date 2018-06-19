cmake_minimum_required(VERSION 2.8)
set(BOOST_INCLUDE_DIR C:/local/boost_1_67_0)
set(BOOST_LIBRARYDIR C:/local/boost_1_67_0/stage/lib)
include_directories(${BOOST_INCLUDE_DIR})
link_directories(${BOOST_LIBRARYDIR})
SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})


add_subdirectory(Core)
add_subdirectory(Engine)
add_subdirectory(Instrument)
add_subdirectory(OrderProcessor)
add_subdirectory(OrderInterface)
add_subdirectory(MDFeed)
add_subdirectory(Util)
add_subdirectory(IO)

