//
// test/ParserSingleValueTest.cpp
//

#include <gtest/gtest.h>
#include "ast.hpp"
#include "namelist_def.hpp"

TEST(ParserSingleObjectTest, FriendlyObjects) {
  using boost::spirit::x3::ascii::space;
  using boost::spirit::x3::phrase_parse;
  bool r;

  std::string::const_iterator iter, end;

  std::string six_sixty = "660";
  iter = six_sixty.cbegin();
  end = six_sixty.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::single_value, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}
