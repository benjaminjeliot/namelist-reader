//
// include/ast.h
//

#ifndef INCLUDE_AST_H_
#define INCLUDE_AST_H_

#include <string>
#include <unordered_map>

namespace nmlcpp {
namespace ast {

struct namelist {
  std::unordered_map<std::string, std::string> data_;
};

}  // namespace ast
}  // namespace nmlcpp

#endif  // INCLUDE_AST_H_
