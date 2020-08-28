project(mylib)
add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_DIR}/src/mylib.c)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include) # only public header will be accesible
target_link_libraries(${PROJECT_NAME} PRIVATE csapp)
# PRIVATE: main cannot access libcsapp. So, including "csapp.h" in main will cause an error.
# PUBLIC:  main now can access libcsapp.So, including "csapp.h" in main will NOT cause an error.