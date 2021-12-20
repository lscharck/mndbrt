cmake_minimum_required(VERSION 3.20.5)

project(mndbrt VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

file(GLOB_RECURSE SRC_FILES src/*/*.c)
add_executable(${PROJECT_NAME} ${SRC_FILES})
install(TARGETS ${PROJECT_NAME} DESTINATION ~/bin)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
