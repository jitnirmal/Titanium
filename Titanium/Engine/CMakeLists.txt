set(Engine_SRCS
    main.cpp
)

add_executable(OrderManager
    ${Engine_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(OrderManager
)

install(TARGETS OrderManager DESTINATION bin)
