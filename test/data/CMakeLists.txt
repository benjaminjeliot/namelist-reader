#
# test/data/CMakeLists.txt
#

if(Example_data_enabled)
  add_executable(data_generator data_generator.f90)
endif()

configure_file(nmlexint.txt ${CMAKE_CURRENT_BINARY_DIR}/nmlexint.txt)
configure_file(nmlexreal4.txt ${CMAKE_CURRENT_BINARY_DIR}/nmlexreal4.txt)
configure_file(nmlexreal8.txt ${CMAKE_CURRENT_BINARY_DIR}/nmlexreal8.txt)
configure_file(nmlexlogical.txt ${CMAKE_CURRENT_BINARY_DIR}/nmlexlogical.txt)
configure_file(nmlexchararray.txt ${CMAKE_CURRENT_BINARY_DIR}/nmlexchararray.txt)
