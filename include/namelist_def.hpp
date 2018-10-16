//
// include/namelist_def.hpp
//

#include <boost/spirit/home/x3.hpp>

namespace client {
namespace parser {

namespace x3 = boost::spirit::x3;

using x3::lit;

auto const namelist_def =
  lit("$")
;

}  // namespace client
}  // namespace parser
