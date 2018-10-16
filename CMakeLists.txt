#
# CMakeLists.txt
#

cmake_minimum_required(VERSION 3.1)

project(namelist_reader LANGUAGES Fortran C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(Testing_enabled "Testing is enabled" ON)
option(Example_data_enabled "Example data is enabled" ON)

find_package(Boost REQUIRED)

add_subdirectory(src)

if(Testing_enabled)
  enable_testing()
  add_subdirectory(test)
endif()

