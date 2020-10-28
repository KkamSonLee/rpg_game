cmake_minimum_required(VERSION 3.17)
project(RPG_GAME)

set(CMAKE_CXX_STANDARD 14)
add_executable(RPG_GAME main.cpp Shop.cpp Shop.h Inventory.cpp Inventory.h Character.cpp Character.h Monster.cpp Monster.h Status.cpp Status.h Item.cpp Item.h battle.cpp battle.h warningMessage.cpp warningMessage.h Town.cpp Town.h)
