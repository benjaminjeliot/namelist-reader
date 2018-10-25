#
# src/CMakeLists.txt
#

set(NAMELIST_SOURCES
  namelist.cpp
)

add_library(namelist ${NAMELIST_SOURCES})

target_include_directories(namelist
  PUBLIC ${PROJECT_SOURCE_DIR}/include
  PRIVATE ${Boost_INCLUDE_DIRS}
)
