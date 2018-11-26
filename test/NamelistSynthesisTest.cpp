//
// NamelistSynthesisTest.cpp
//

#include <iostream>
#include <string>

#include <gtest/gtest.h>
#include "ast.h"
#include "ast_adapted.h"
#include "config.h"
#include "namelist.h"
#include "namelist_def.h"

TEST(NamelistSynthesisTest, EmptyNamelist) {
  // Empty namelist
  std::string input_string = " &an_empty_namelist\n /";

  nmlcpp::parser::iterator_type iter = input_string.cbegin();
  nmlcpp::parser::iterator_type end = input_string.cend();

  namespace x3 = boost::spirit::x3;
  using boost::spirit::x3::error_handler_tag;
  using error_handler_type = boost::spirit::x3::error_handler<nmlcpp::parser::iterator_type>;
  error_handler_type error_handler(iter, end, std::cerr);

  auto const parser =
      x3::with<error_handler_tag>(std::ref(error_handler))[nmlcpp::parser::namelist];
  using boost::spirit::x3::ascii::space;
  nmlcpp::ast::namelist nl;

  bool r = phrase_parse(iter, end, parser, space, nl);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
  EXPECT_EQ("an_empty_namelist", nl.name_);
  EXPECT_EQ(0, nl.data_.size());
}

TEST(NamelistSynthesisTest, DoubleQuotedString) {
  // Namelist with double-quoted string
  std::string input_string = " &nl_with_string\n a_value = \"some text\"\n /";

  nmlcpp::parser::iterator_type iter = input_string.cbegin();
  nmlcpp::parser::iterator_type end = input_string.cend();

  namespace x3 = boost::spirit::x3;
  using boost::spirit::x3::error_handler_tag;
  using error_handler_type = boost::spirit::x3::error_handler<nmlcpp::parser::iterator_type>;
  error_handler_type error_handler(iter, end, std::cerr);

  auto const parser =
      x3::with<error_handler_tag>(std::ref(error_handler))[nmlcpp::parser::namelist];
  using boost::spirit::x3::ascii::space;
  nmlcpp::ast::namelist nl;

  bool r = phrase_parse(iter, end, parser, space, nl);
  EXPECT_EQ(end, iter);
  EXPECT_EQ("nl_with_string", nl.name_);
  EXPECT_EQ(1, nl.data_.size());
  ASSERT_NE(0, nl.data_.count("a_value"));
  EXPECT_EQ("some text", boost::get<std::string>(nl.data_.at("a_value")));
}

TEST(NamelistSynthesisTest, Integers) {
  // Namelist with double-quoted string
  std::string input_string = " &nl_with_string\n an_int = 125\n another_int = -599\n /";

  nmlcpp::parser::iterator_type iter = input_string.cbegin();
  nmlcpp::parser::iterator_type end = input_string.cend();

  namespace x3 = boost::spirit::x3;
  using boost::spirit::x3::error_handler_tag;
  using error_handler_type = boost::spirit::x3::error_handler<nmlcpp::parser::iterator_type>;
  error_handler_type error_handler(iter, end, std::cerr);

  auto const parser =
      x3::with<error_handler_tag>(std::ref(error_handler))[nmlcpp::parser::namelist];
  using boost::spirit::x3::ascii::space;
  nmlcpp::ast::namelist nl;

  bool r = phrase_parse(iter, end, parser, space, nl);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
  EXPECT_EQ("nl_with_string", nl.name_);
  EXPECT_EQ(2, nl.data_.size());
  ASSERT_NE(0, nl.data_.count("an_int"));
  EXPECT_EQ(125, boost::get<int>(nl.data_.at("an_int")));
  ASSERT_NE(0, nl.data_.count("an_int"));
  EXPECT_EQ(-599, boost::get<int>(nl.data_.at("another_int")));
}
