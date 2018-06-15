set(MatchingEngine_SRCS
    main.cpp
)

add_executable(MatchingEngine
    ${MatchingEngine_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries( MatchingEngine 
	OrderProcessor
	MDFeed
)

install(TARGETS MatchingEngine DESTINATION bin)
