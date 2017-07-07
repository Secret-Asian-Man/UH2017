cmake_minimum_required(VERSION 2.8.3)

project(mobility)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  sensor_msgs
  std_msgs
  random_numbers
  tf
)

find_package(PythonLibs REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})

catkin_package(
  CATKIN_DEPENDS geometry_msgs roscpp sensor_msgs std_msgs random_numbers tf
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)

configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

include_directories("${PROJECT_BINARY_DIR}")

set(EXECUTABLE_NAME "mobility")

add_executable(
  ${EXECUTABLE_NAME}
  src/PickUpController.cpp
  src/DropOffController.cpp
  src/SearchController.cpp
  src/mobility.cpp
)

add_dependencies(${EXECUTABLE_NAME} ${catkin_EXPORTED_TARGETS})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(SFML_ROOT "/home/swarmie/rover_workspace/src/mobility/cmake_modules/SFML-2.4.2")

find_package(SFML 2.4.2 REQUIRED network audio graphics window system)

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(
  ${EXECUTABLE_NAME} 
  ${SFML_LIBRARIES} 
  ${SFML_DEPENDENCIES}
  ${catkin_LIBRARIES}
  ${PYTHON_LIBRARIES}
)
else()
  target_link_libraries(
  ${EXECUTABLE_NAME} 
  ${catkin_LIBRARIES}
  ${PYTHON_LIBRARIES}
)
endif()


install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)
