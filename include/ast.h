//
// include/ast.h
//

#ifndef INCLUDE_AST_H_
#define INCLUDE_AST_H_

#include <string>
#include <unordered_map>

#include <boost/fusion/include/io.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

namespace nmlcpp {
namespace ast {

namespace x3 = boost::spirit::x3;

struct namelist_value : x3::variant<std::string, double, int> {
  using base_type::base_type;
  using base_type::operator=;
};

typedef std::pair<std::string, namelist_value> key_value;

struct namelist : x3::position_tagged {
  std::string name_;
  std::unordered_map<std::string, namelist_value> data_;
};

using boost::fusion::operator<<;

}  // namespace ast
}  // namespace nmlcpp

#endif  // INCLUDE_AST_H_
