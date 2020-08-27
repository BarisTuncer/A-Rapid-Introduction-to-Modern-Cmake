project(log)
add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_DIR}/src/log.c)
# announce the headers to the ones who are linking this lib: So, mylib can't access it!
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(${PROJECT_NAME} PUBLIC LOG_USE_COLOR)