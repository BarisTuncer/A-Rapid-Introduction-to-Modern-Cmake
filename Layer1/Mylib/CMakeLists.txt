project(mylib)
add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_DIR}/src/mylib.c)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include) # only public header will be accesible
target_link_libraries(${PROJECT_NAME} PRIVATE csapp) # PRIVATE so that driver can't access csapp
target_link_libraries(${PROJECT_NAME} PUBLIC log) # PUBLIC so that driver can access log
