cmake_minimum_required(VERSION 3.0.0)
project(thermostate VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

add_executable(thermostate)
target_sources(thermostate PRIVATE main.cpp 
                                    src/thermostate.cpp
                                    src/heater.cpp
                                    src/cooler.cpp 
                                    src/temperature_celsius.cpp
                                    src/thermostate_controller.cpp 
                                    include/${PROJECT_NAME}/thermostate.h 
                                    include/${PROJECT_NAME}/thermostate_controller.h
                                    include/${PROJECT_NAME}/heater.h 
                                    include/${PROJECT_NAME}/cooler.h
                                    include/${PROJECT_NAME}/temperature_celsius.h 
                                    include/${PROJECT_NAME}/temperature_device_controller.h
                                    include/${PROJECT_NAME}/temperature_device.h 
                                    include/${PROJECT_NAME}/temperature_modifier.h
                                    include/${PROJECT_NAME}/temperature.h)

#add_executable(tests)
#target_sources(tests test/Gtests.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
