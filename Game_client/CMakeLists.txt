cmake_minimum_required(VERSION 3.17)
project(Game_client)

set(CMAKE_CXX_STANDARD 20)

add_link_options(-pthread)
add_link_options(-lrt)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(Game_client main.cpp player.cpp player.h)
target_link_libraries(Game_client ${CURSES_LIBRARIES})
TARGET_LINK_LIBRARIES(Game_client ${Boost_LIBRARIES} rt)
