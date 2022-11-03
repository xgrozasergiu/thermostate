cmake_minimum_required(VERSION 3.0.0)
project(thermostate VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

add_executable(thermostate)
target_sources(thermostate PRIVATE main.cpp src/thermostate.cpp include/${PROJECT_NAME}/thermostate.h src/thermostate_controller.cpp include/${PROJECT_NAME}/thermostate_controller.h)

#add_executable(tests)
#target_sources(tests test/Gtests.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
