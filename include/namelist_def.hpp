//
// include/namelist_def.hpp
//

#include <boost/spirit/home/x3.hpp>

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

//! Parser for Fortran identifier name
auto const fortran_identifier = lexeme[(alpha >> *(alnum | char_("_")))];

//! Parser for Fortran namelist header
//! A dollar sign '$' followed by an identifier
auto const namelist_def = lexeme[lit('$') >> fortran_identifier];

// TODO: Extend parser to deal with a double quote escaped with a double quote
//! Parser for a double quoted string
auto const double_quoted_string = lexeme['"' >> *(("\"\"" >> attr('"')) | (char_ - '"')) >> '"'];

//! Parser for a single quoted string
auto const single_quoted_string = lexeme['\'' >> *(char_ - '\'') >> '\''];

// TODO: Modify the int case to stop if a space follows the dot
//! Parser for a single value, i.e. the right hand side of an key value pair
//! Don't parse an int that is followed by a dot, as it is probably floating point number
auto const single_value = double_quoted_string | single_quoted_string | (int_ >> !char_('.')) | double_;

//! Parser for a single (non-array) namelist entry
auto const key_value = fortran_identifier >> '=' >> single_value;

auto const key_index = fortran_identifier >> '(' >> int_ % ',' >> ')';

}  // namespace nmlcpp
}  // namespace parser
