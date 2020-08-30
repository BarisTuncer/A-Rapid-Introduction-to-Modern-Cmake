
project(csapp)
add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_DIR}/src/csapp.c)
# make it PUBLIC anyone who "links" it can use it: So mylib can see it but not driver!
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include) 
target_compile_options(${PROJECT_NAME} PRIVATE "-O2")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread)
