cmake_minimum_required(VERSION 3.17)
project(RPG_GAME)

set(CMAKE_CXX_STANDARD 14)
add_executable(RPG_GAME main.cpp Character.cpp Character.h Status.cpp Status.h Inventory.cpp Inventory.h Shop.cpp Shop.h Item.cpp Item.h Monster.cpp Monster.h character_integrity_check.cpp character_integrity_check.h warningMessage.cpp warningMessage.h Town.cpp Town.h)

