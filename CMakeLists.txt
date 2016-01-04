project(cake)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

add_executable(${PROJECT_NAME}
  src/main.cpp
  src/AnimatedSprite.h
  src/AnimatedSprite.cpp
  src/GameObject.h
  src/GameObject.cpp
  src/Scene.h
  src/Scene.cpp
  src/Layer.h
  src/Layer.cpp
  src/Rook.h
  src/Rook.cpp
  )

SET (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
FIND_PACKAGE(SFML 2 REQUIRED system window graphics network audio)

if(${SFML_FOUND})
    INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()


set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED
  COMPONENTS
  system
  date_time
  thread
  regex
  filesystem
  program_options
  )

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  link_libraries(${Boost_LIBRARIES})
endif()

include(FindPkgConfig)
pkg_check_modules(yaml-cpp REQUIRED yaml-cpp>=0.2.5)
include_directories(${yaml-cpp_INCLUDE_DIRS})
link_directories(${yaml-cpp_LIBRARY_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${yaml-cpp_LIBRARIES})