//
// test/ParserStringTest.cpp
//

#include <gtest/gtest.h>
#include "ast.h"
#include "namelist_def.hpp"

TEST(ParserStringTest, FriendlyStrings) {
  using boost::spirit::x3::ascii::space;
  using boost::spirit::x3::phrase_parse;
  bool r;
  std::string::const_iterator iter, end;

  std::string hello = "\"nospaces\"";
  iter = hello.cbegin();
  end = hello.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::double_quoted_string, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  std::string string_with_space = "\"string with spaces\"";
  iter = string_with_space.cbegin();
  end = string_with_space.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::double_quoted_string, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}

TEST(ParserStringTest, AwkwardStrings) {
  using boost::spirit::x3::ascii::space;
  using boost::spirit::x3::phrase_parse;
  bool r;
  std::string::const_iterator iter, end;

  std::string string_with_quotes = "\"String \"\"containing\"\" quote\"";
  iter = string_with_quotes.cbegin();
  end = string_with_quotes.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::double_quoted_string, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}
