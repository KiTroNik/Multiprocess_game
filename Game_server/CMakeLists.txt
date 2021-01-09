cmake_minimum_required(VERSION 3.17)
project(Game_server)

set(CMAKE_CXX_STANDARD 20)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_link_options(-pthread)
add_link_options(-lrt)
add_executable(Game_server main.cpp)
target_link_libraries(Game_server ${CURSES_LIBRARIES})
TARGET_LINK_LIBRARIES(Game_server ${Boost_LIBRARIES} rt)