cmake_minimum_required(VERSION 3.20)
project(atmconsole)

set(CMAKE_CXX_STANDARD 20)

add_executable(atmconsole src/atm.cpp src/atm.hpp)
