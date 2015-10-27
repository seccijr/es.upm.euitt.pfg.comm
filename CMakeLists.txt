cmake_minimum_required(VERSION 2.8)
set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME Comm)
project(${PROJECT_NAME})

print_board_list()
print_programmer_list()

add_subdirectory(src)

set(ArduinoUnit_RECURSE true)

generate_arduino_firmware(test
    SRCS tests/Test.cpp
    BOARD uno
    SERIAL picocom @SERIAL_PORT@ -b 9600 -l
    PORT  /dev/ttyACM0)
