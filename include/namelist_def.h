//
// include/namelist_def.h
//

#ifndef INCLUDE_NAMELIST_DEF_H_
#define INCLUDE_NAMELIST_DEF_H_

#include <boost/spirit/home/x3.hpp>
#include "ast.h"
#include "ast_adapted.h"
#include "namelist.h"

namespace nmlcpp {
namespace parser {

namespace x3 = boost::spirit::x3;

using x3::alpha;
using x3::alnum;
using x3::attr;
using x3::char_;
using x3::double_;
using x3::int_;
using x3::lexeme;
using x3::lit;
using x3::string;

x3::rule<class fortran_identifier /* , ast::fortran_identifier */ > const fortran_identifier = "fortran_identifier";
x3::rule<class namelist_header /* , ast::namelist_header */ > const namelist_header = "namelist_header";
x3::rule<class double_quoted_string /* , ast::double_quoted_string */ > const double_quoted_string = "double_quoted_string";
x3::rule<class single_quoted_string /* , ast::single_quoted_string */ > const single_quoted_string = "single_quoted_string";
x3::rule<class single_value /* , ast::single_value */ > const single_value = "single_value";
x3::rule<class key_value /* , ast::key_value */ > const key_value = "key_value";
x3::rule<class key_index /* , ast::key_index */ > const key_index = "key_index";
x3::rule<class key_array_value /* , ast::key_array_value */ > const key_array_value = "key_array_value";
x3::rule<class namelist, ast::namelist> const namelist = "namelist";

//! Parser for Fortran identifier name
auto const fortran_identifier_def = lexeme[(alpha >> *(alnum | char_("_")))];

//! Parser for Fortran namelist header
//! An ampersand '&' followed by an identifier
auto const namelist_header_def = lexeme[lit('&') >> fortran_identifier];

// TODO: Extend parser to deal with a double quote escaped with a double quote
//! Parser for a double quoted string
auto const double_quoted_string_def = lexeme['"' >> *(("\"\"" >> attr('"')) | (char_ - '"')) >> '"'];

//! Parser for a single quoted string
auto const single_quoted_string_def = lexeme['\'' >> *(char_ - '\'') >> '\''];

// TODO: Modify the int case to stop if a space follows the dot
//! Parser for a single value, i.e. the right hand side of an key value pair
//! Don't parse an int that is followed by a dot, as it is probably floating point number
auto const single_value_def = double_quoted_string | single_quoted_string | (int_ >> !char_('.')) | double_;

//! Parser for a single (non-array) namelist entry
auto const key_value_def = fortran_identifier >> '=' >> single_value;

//! Parser for a key with array indices
auto const key_index_def = fortran_identifier >> '(' >> int_ % ',' >> ')';

//! TODO: Modify this to handle a comma separated list of values following the equals sign
//! Parser for an array namelist entry
auto const key_array_value_def = key_index >> '=' >> single_value;

//! Parser for namelist block

auto const namelist_def = namelist_header >> *(key_value | key_array_value) >> '/';

BOOST_SPIRIT_DEFINE(fortran_identifier, namelist_header, double_quoted_string,
		            single_quoted_string, single_value, key_value, key_index,
					key_array_value, namelist)

}  // namespace parser
}  // namespace nmlcpp

#endif  // INCLUDE_NAMELIST_DEF_H_
