//
// test/ParserFortranIdentifierTest.cpp
//

#include <gtest/gtest.h>
#include "ast.hpp"
#include "namelist_def.hpp"

TEST(ParserFortranIdentifierTest, Initialisation) {
  using boost::spirit::x3::ascii::space;
  using boost::spirit::x3::phrase_parse;
  bool r;

  std::string::const_iterator iter, end;

  std::string alphas = "alphas";
  iter = alphas.cbegin();
  end = alphas.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::fortran_identifier, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  std::string alphas_nums_underscores = "my_variable_1";
  iter = alphas_nums_underscores.cbegin();
  end = alphas_nums_underscores.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::fortran_identifier, space);
  EXPECT_TRUE(r);
  EXPECT_EQ(end, iter);

  std::string contains_space = "identifier_1 another_identifier";
  iter = contains_space.cbegin();
  end = contains_space.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::fortran_identifier, space);
  EXPECT_TRUE(r);
  // Check that we have only consumed 'identifier_1' from the input
  EXPECT_EQ('a', *iter);

  std::string leading_num = "3_leading_numeric";
  iter = leading_num.cbegin();
  end = leading_num.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::fortran_identifier, space);
  EXPECT_FALSE(r);

  std::string leading_underscore = "_leading_underscore";
  iter = leading_underscore.cbegin();
  end = leading_underscore.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::fortran_identifier, space);
  EXPECT_FALSE(r);

  std::string leading_dollar = "$leading_dollar";
  iter = leading_dollar.cbegin();
  end = leading_dollar.cend();
  r = phrase_parse(iter, end, nmlcpp::parser::fortran_identifier, space);
  EXPECT_FALSE(r);
}
