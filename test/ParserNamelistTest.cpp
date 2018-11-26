//
// test/ParserNamelistTest.cpp
//

#include <boost/spirit/home/x3/support/utility/error_reporting.hpp>
#include <gtest/gtest.h>
#include "ast.h"
#include "config.h"
#include "namelist_def.h"

TEST(ParserNamelistTest, EmptyNamelist) {
  using boost::spirit::x3::ascii::space;

  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;

  // Empty namelist
  input_string = " &a_namelist\n /";
  iter = input_string.cbegin();
  end = input_string.cend();

  namespace x3 = boost::spirit::x3;
  using boost::spirit::x3::error_handler_tag;
  using error_handler_type = boost::spirit::x3::error_handler<nmlcpp::parser::iterator_type>;
  error_handler_type error_handler(iter, end, std::cerr);

  auto const parser =
      x3::with<error_handler_tag>(std::ref(error_handler))[nmlcpp::parser::namelist];

  r = phrase_parse(iter, end, parser, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}

TEST(ParserNamelistTest, DoubleQuotedString) {
  using boost::spirit::x3::ascii::space;

  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;
  input_string = " &a_namelist\n a_value = \"some text\"\n /";
  iter = input_string.cbegin();
  end = input_string.cend();

  namespace x3 = boost::spirit::x3;
  using boost::spirit::x3::error_handler_tag;
  using error_handler_type = boost::spirit::x3::error_handler<nmlcpp::parser::iterator_type>;
  error_handler_type error_handler(iter, end, std::cerr);

  auto const parser =
      x3::with<error_handler_tag>(std::ref(error_handler))[nmlcpp::parser::namelist];

  r = phrase_parse(iter, end, parser, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}

TEST(ParserNamelistTest, SimpleQuotedString) {
  using boost::spirit::x3::ascii::space;

  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;

  input_string = " &a_namelist\n a_value = 'some text'\n /";
  iter = input_string.cbegin();
  end = input_string.cend();

  namespace x3 = boost::spirit::x3;
  using boost::spirit::x3::error_handler_tag;
  using error_handler_type = boost::spirit::x3::error_handler<nmlcpp::parser::iterator_type>;
  error_handler_type error_handler(iter, end, std::cerr);

  auto const parser =
      x3::with<error_handler_tag>(std::ref(error_handler))[nmlcpp::parser::namelist];

  r = phrase_parse(iter, end, parser, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}

TEST(ParserNamelistTest, Integer) {
  using boost::spirit::x3::ascii::space;

  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;

  input_string = " &a_namelist\n a_value = 42\n /";
  iter = input_string.cbegin();
  end = input_string.cend();

  namespace x3 = boost::spirit::x3;
  using boost::spirit::x3::error_handler_tag;
  using error_handler_type = boost::spirit::x3::error_handler<nmlcpp::parser::iterator_type>;
  error_handler_type error_handler(iter, end, std::cerr);

  auto const parser =
      x3::with<error_handler_tag>(std::ref(error_handler))[nmlcpp::parser::namelist];

  r = phrase_parse(iter, end, parser, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}

TEST(ParserNamelistTest, Double) {
  using boost::spirit::x3::ascii::space;

  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;
  input_string = " &a_namelist\n a_value = -9.9\n /";
  iter = input_string.cbegin();
  end = input_string.cend();

  namespace x3 = boost::spirit::x3;
  using boost::spirit::x3::error_handler_tag;
  using error_handler_type = boost::spirit::x3::error_handler<nmlcpp::parser::iterator_type>;
  error_handler_type error_handler(iter, end, std::cerr);

  auto const parser =
      x3::with<error_handler_tag>(std::ref(error_handler))[nmlcpp::parser::namelist];

  r = phrase_parse(iter, end, parser, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}

TEST(ParserNamelistTest, DISABLED_IntegerWithIndex) {
  using boost::spirit::x3::ascii::space;

  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;
  input_string = " &a_namelist\n an_array(1) = 42\n /";
  iter = input_string.cbegin();
  end = input_string.cend();

  namespace x3 = boost::spirit::x3;
  using boost::spirit::x3::error_handler_tag;
  using error_handler_type = boost::spirit::x3::error_handler<nmlcpp::parser::iterator_type>;
  error_handler_type error_handler(iter, end, std::cerr);

  auto const parser =
      x3::with<error_handler_tag>(std::ref(error_handler))[nmlcpp::parser::namelist];

  r = phrase_parse(iter, end, parser, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);
}

TEST(ParserNamelistTest, BogusNamelist) {
  using boost::spirit::x3::ascii::space;

  bool r;
  std::string::const_iterator iter, end;
  std::string input_string;

  // Bogus namelist with equals sign '=' instead of value
  input_string = " &bogus_namelist\n a_key = =/";
  iter = input_string.cbegin();
  end = input_string.cend();

  namespace x3 = boost::spirit::x3;
  using boost::spirit::x3::error_handler_tag;
  using error_handler_type = boost::spirit::x3::error_handler<nmlcpp::parser::iterator_type>;
  error_handler_type error_handler(iter, end, std::cerr);

  auto const parser =
      x3::with<error_handler_tag>(std::ref(error_handler))[nmlcpp::parser::namelist];

  r = phrase_parse(iter, end, parser, space);
  EXPECT_FALSE(r);
}
