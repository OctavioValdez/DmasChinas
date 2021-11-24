cmake_minimum_required(VERSION 3.20)
project(DmasChinas C)


set(CMAKE_C_STANDARD 99)

find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0

add_executable(DmasChinas main.c settings.c)

target_link_libraries(${PROJECT_NAME} raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
