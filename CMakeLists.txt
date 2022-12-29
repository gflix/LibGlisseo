cmake_minimum_required(VERSION 3.22)

# set project name and version
file(STRINGS ".version" VERSION_FILE)
project(libglisseo VERSION ${VERSION_FILE} LANGUAGES CXX)

find_package(PkgConfig REQUIRED)
find_package(Threads REQUIRED)
pkg_check_modules(JSONCPP jsoncpp>=1.7 REQUIRED IMPORTED_TARGET)
pkg_check_modules(SYSTEMD libsystemd>=0.29 REQUIRED IMPORTED_TARGET)

# import directory names used on GNU systems
include(GNUInstallDirs)

include(glisseo.cmake)
include(unittest.cmake)
