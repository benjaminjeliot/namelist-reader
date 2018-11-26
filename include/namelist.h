//
// include/namelist.h
//

#ifndef INCLUDE_NAMELIST_H_
#define INCLUDE_NAMELIST_H_

#include <boost/spirit/home/x3.hpp>
#include "ast.h"

namespace nmlcpp {
namespace parser {
  namespace x3 = boost::spirit::x3;
  struct namelist_class;
  using namelist_type = x3::rule<namelist_class, ast::namelist>;
  BOOST_SPIRIT_DECLARE(namelist_type);
}  // parser
parser::namelist_type namelist();
}  // nmlcpp

#endif  // INCLUDE_NAMELIST_H_
