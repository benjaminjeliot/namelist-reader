#
# src/CMakeLists.txt
#

set(NAMELIST_SOURCES
  namelist.cpp
)

add_library(nmlcpp ${NAMELIST_SOURCES})

target_include_directories(nmlcpp
  PUBLIC ${PROJECT_SOURCE_DIR}/include
  PRIVATE ${Boost_INCLUDE_DIRS}
)
