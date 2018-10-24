//
// test/ParserNamelistTest.cpp
//

#include <gtest/gtest.h>
#include "ast.hpp"
#include "namelist_def.hpp"

TEST(ParserNamelistTest, SimpleNamelists) {
  using boost::spirit::x3::ascii::space;
  using boost::spirit::x3::phrase_parse;
  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;

  // Empty namelist
  input_string = " &a_namelist\n /";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::namelist, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = " &a_namelist\n a_value = \"some text\"\n /";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::namelist, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = " &a_namelist\n a_value = 'some text'\n /";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::namelist, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = " &a_namelist\n a_value = 42\n /";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::namelist, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = " &a_namelist\n a_value = -9.9\n /";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::namelist, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  input_string = " &a_namelist\n an_array(1) = 42\n a_value = -9.9\n /";
  iter = input_string.cbegin();
  end = input_string.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::namelist, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}
