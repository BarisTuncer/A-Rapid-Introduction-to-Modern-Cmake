# set the project name
project(driver)
# specify the executable and corresponding source file
add_executable(main ${PROJECT_SOURCE_DIR}/main.c)

# gcc -o main -std=c11 -Wall -Wextra main.c