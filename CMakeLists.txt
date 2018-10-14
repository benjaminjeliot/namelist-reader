#
# CMakeLists.txt
#

cmake_minimum_required(VERSION 3.1)

project(namelist_reader LANGUAGES Fortran C CXX)

option(Testing_enabled "Testing is enabled" ON)
option(Example_data_enabled "Example data is enabled" ON)

add_subdirectory(src)

if(Testing_enabled)
  enable_testing()
  add_subdirectory(test)
endif()

