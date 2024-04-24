cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(RayGUI)

# Project variables
set(SRC ${PROJECT_SOURCE_DIR}/src)
set(LIB ${PROJECT_SOURCE_DIR}/lib)
set(INCLUDE ${PROJECT_SOURCE_DIR}/include)
set(BIN ${PROJECT_BINARY_DIR})

message(STATUS "Build in ${PROJECT_BINARY_DIR}")

IF (NOT CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message(STATUS "This project has a top-level one called ${CMAKE_PROJECT_NAME}")
ELSE()
    message(STATUS "This project is top-level")
ENDIF()

# Library type definition
IF (NOT DEFINED -DLIBRARY_TYPE)
    add_definitions(-DLIBRARY_TYPE)
ENDIF()

IF ((NOT LIBRARY_TYPE STREQUAL STATIC) AND (NOT LIBRARY_TYPE STREQUAL SHARED))
    set(LIBRARY_TYPE STATIC)
    message(STATUS "Wrong value of LIBRARY_TYPE was changed to default ${LIBRARY_TYPE}")
ENDIF()


add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/log.txt
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_directory
    ${INCLUDE} 
    ${BIN}/include
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_directory
    ${SRC}/headers 
    ${BIN}/include
)

add_custom_target(
    clear
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/log.txt
)

# SubProject
set(-DBUILD_EXAMPLES NO)
add_subdirectory(${LIB}/raylib)

# add executable
add_library(${PROJECT_NAME} ${LIBRARY_TYPE})
add_dependencies(${PROJECT_NAME} clear )
target_sources(${PROJECT_NAME}
    PRIVATE
        ${SRC}/Window.cpp
        ${SRC}/GuiElements.cpp
)

target_link_libraries(${PROJECT_NAME} raylib)
target_include_directories(${PROJECT_NAME} 
    PRIVATE
        ${LIB}/raylib/src
    PUBLIC
        ${SRC}/headers
)