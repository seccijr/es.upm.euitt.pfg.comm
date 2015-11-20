cmake_minimum_required(VERSION 2.8)
set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME Comm)
set(ArduinoUnit_RECURSE true)
project(${PROJECT_NAME})

register_hardware_platform(${ARDUINO_SDK_PATH}/hardware/arduino/avr/)
link_directories(${ARDUINO_SDK_PATH}/hardware/arduino/avr/libraries)

file(GLOB_RECURSE comm_SRCS
    "src/*.cpp")

file(GLOB_RECURSE comm_HDRS
    "src/*.h")

file(GLOB_RECURSE testing_SRCS
    "test/*.cpp")

file(GLOB_RECURSE testing_HDRS
    "test/*.h")

include_directories(src test)

set(testing_SKETCH  ${CMAKE_CURRENT_SOURCE_DIR}/test/unit/unit.ino)
set(testing_SRCS ${comm_SRCS} ${testing_SRCS})
set(testing_HDRS ${comm_HDRS} ${testing_HDRS})
set(testing_BOARD uno)
set(testing_PORT  /dev/ttyACM3)

generate_arduino_firmware(testing)
