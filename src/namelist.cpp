//
// src/namelist.cpp
//

#include "config.h"
#include "namelist_def.h"

namespace nmlcpp {
namespace parser {

  //! Creates parse_rule
  BOOST_SPIRIT_INSTANTIATE(namelist_type, iterator_type, context_type);
}

parser::namelist_type namelist() {
  return parser::namelist;
}
}
