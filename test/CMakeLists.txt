#
# test/CMakeLists.txt
#

find_package(GTest REQUIRED)

add_subdirectory(data)

set(TEST_SOURCES
  ParserFortranIdentifierTest.cpp
  ParserStringTest.cpp
  ParserTest.cpp
  test_runner.cpp
)

add_executable(test_runner ${TEST_SOURCES})

target_include_directories(test_runner
  PUBLIC ${PROJECT_SOURCE_DIR}/include
  PRIVATE ${Boost_INCLUDE_DIRS}
)

target_link_libraries(test_runner
  GTest::GTest
)

gtest_discover_tests(test_runner)
