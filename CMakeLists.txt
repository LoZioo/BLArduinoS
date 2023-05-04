cmake_minimum_required(VERSION 3.10)
project(main VERSION 1.0)

# --------------------| Libraries |------------------------------

add_library(BLArduinoS STATIC lib/BLArduinoS/BLArduinoS.cpp)
target_include_directories(BLArduinoS PUBLIC lib/BLArduinoS)

# --------------------| Main file |------------------------------

add_executable(main src/main.cpp)

# --------------------| Linking |------------------------------

target_include_directories(main PUBLIC include)				# include dir.
target_link_libraries(main PUBLIC BLArduinoS)
