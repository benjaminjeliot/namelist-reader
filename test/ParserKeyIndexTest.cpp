//
// test/ParserKeyIndexTest.cpp
//

#include <gtest/gtest.h>
#include "ast.hpp"
#include "namelist_def.hpp"

TEST(ParserKeyIndexTest, FriendlyCases) {
  using boost::spirit::x3::ascii::space;
  using boost::spirit::x3::phrase_parse;
  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;

  input_string = "an_array(1)";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_index, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = "an_array(1, 2)";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_index, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = "an_array(1, 2, 3, 4)";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_index, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = "an_array(1,2,3,4)";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::key_index, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}
