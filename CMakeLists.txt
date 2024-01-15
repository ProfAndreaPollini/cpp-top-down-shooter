cmake_minimum_required(VERSION 3.27)
project(cpp-top-down-shooter CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib/SimpleGameKit)

set(MODULE_FILES
    main.cpp
    src/PlayScene.cpp
    src/Components.cpp
)
add_executable(${PROJECT_NAME} ${MODULE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE src)
set_source_files_properties(${MODULE_FILES} PROPERTIES COMPILE_OPTIONS "-Wall;-Wextra;-Wpedantic")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE -g -O0 -DDEBUG)
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE SimpleGameKit)
