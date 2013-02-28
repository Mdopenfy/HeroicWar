cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME HeroicWar)
project(${PROJECT_NAME})

set(EXECUTABLE_NAME "${PROJECT_NAME}")

set(FLAGS_G "-O2 -pipe -ansi -pedantic -Wextra -Wunused -Werror -Wall -Wconversion -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Winit-self -Wwrite-strings -Wswitch-default -Wfloat-equal -Wundef ")
set(CMAKE_C_FLAGS "${FLAGS_G} -Wmissing-declarations -Wmissing-prototypes -Wdeclaration-after-statement -Wstrict-prototypes")
set(CMAKE_CXX_FLAGS ${FLAGS_G})
set(CMAKE_EXE_LINKER_FLAGS "-O2 -flto -s")

# set version information in a config.h file
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)

set(PROJECT_SOURCE_DIR "../src")
set(PROJECT_BINARY_DIR "../bin")

configure_file(
  "src/config.h.in"
  "${PROJECT_SOURCE_DIR}/config.h"
)

file(
  GLOB_RECURSE
  src_file
  src/*
)

include_directories(
   /usr/include/SFML
   # "${PROJECT_BINARY_DIR}"
)

add_executable(${PROJECT_BINARY_DIR}/${EXECUTABLE_NAME} ${src_file})


target_link_libraries(${PROJECT_BINARY_DIR}/${EXECUTABLE_NAME}
  sfml-graphics
  sfml-audio
  sfml-window
  sfml-system
)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
include(CPack)
