//
// include/namelist_def.hpp
//

#include <boost/spirit/home/x3.hpp>

namespace nmlcpp {
namespace parser {

namespace x3 = boost::spirit::x3;

using x3::lit;
using x3::string;
using x3::int_;
using x3::char_;
using x3::alpha;
using x3::alnum;

//! Parser for Fortran identifier name
auto const fortran_identifier = (alpha >> *(alnum | char_("_")));

//! Parser for Fortran namelist header
//! A dollar sign '$' followed by an identifier
auto const namelist_def = lit('$') >> fortran_identifier;

}  // namespace nmlcpp
}  // namespace parser
