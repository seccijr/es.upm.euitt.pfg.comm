cmake_minimum_required(VERSION 2.8)
set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME Comm)
set(ArduinoUnit_RECURSE true)
project(${PROJECT_NAME})

register_hardware_platform(${ARDUINO_SDK_PATH}/hardware/arduino/avr/)
print_board_list()
print_programmer_list()

file(GLOB comm_SRCS
    "src/*.cpp")

file(GLOB comm_HDRS
    "src/*.h")

file(GLOB test_SRCS
    "tests/*.cpp")

file(GLOB test_HDRS
    "tests/*.h")

generate_arduino_firmware(test
    SRCS ${comm_SRCS} ${test_SRCS}
    HDRS ${comm_HDRS} ${test_HDRS}
    BOARD uno
    SERIAL picocom @SERIAL_PORT@ -b 9600 -l
    PORT  /dev/ttyACM0)
