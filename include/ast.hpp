//
// include/ast.hpp
//

#include <std::string>
#include <unordered_map>

namespace client {
namespace parser {

struct namelist {
  std::unordered_map<std::string, std::string> data_;
};

}  // namespace parser
}  // namespace client
