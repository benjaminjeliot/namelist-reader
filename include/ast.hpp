//
// include/ast.hpp
//

#include <string>
#include <unordered_map>

namespace nmlcpp {
namespace parser {

struct namelist {
  std::unordered_map<std::string, std::string> data_;
};

}  // namespace parser
}  // namespace nmlcpp
