//
// test/ParserKeyArrayValueTest.cpp
//

#include <gtest/gtest.h>
#include "ast.hpp"
#include "namelist_def.hpp"

TEST(ParserKeyArrayValueTest, VariousTypes) {
  using boost::spirit::x3::ascii::space;
  using boost::spirit::x3::phrase_parse;
  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;

  input_string = "an_array(1) = 42";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_array_value, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = "my_array(1, 1) = -45.11";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_array_value, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = "my_array(-1, -1, -1) = \"hello double quotes\"";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_array_value, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = "my_array(0, 0, 0, 0) = 'hello single quotes'";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_array_value, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}
