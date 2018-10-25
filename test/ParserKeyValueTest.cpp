//
// test/ParserKeyValueTest.cpp
//

#include <gtest/gtest.h>
#include "ast.h"
#include "namelist_def.h"

TEST(ParserKeyValueTest, VariousTypes) {
  using boost::spirit::x3::ascii::space;
  using boost::spirit::x3::phrase_parse;
  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;

  input_string = "the_answer = 42";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_value, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = "pi = 3.14159";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_value, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = "double_quotes = \"hello double quotes\"";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_value, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = "single_quotes = 'hello single quotes'";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_value, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}

TEST(ParserKeyValueTest, AwkwardThings) {
  using boost::spirit::x3::ascii::space;
  using boost::spirit::x3::phrase_parse;
  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;

  input_string = "space_dot_after_int = 5 .33";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_value, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(*iter, '.');
}
