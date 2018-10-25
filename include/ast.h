//
// include/ast.h
//

#ifndef INCLUDE_AST_H_
#define INCLUDE_AST_H_

#include <string>
#include <unordered_map>

namespace nmlcpp {
namespace parser {

struct namelist {
  std::unordered_map<std::string, std::string> data_;
};

}  // namespace parser
}  // namespace nmlcpp

#endif  // INCLUDE_AST_H_
