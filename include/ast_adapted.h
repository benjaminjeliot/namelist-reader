//
// include/ast_adapted.h
//

#ifndef INCLUDE_AST_ADAPTED_H_
#define INCLUDE_AST_ADAPTED_H_

#include <boost/fusion/include/adapt_struct.hpp>
#include "ast.h"

BOOST_FUSION_ADAPT_STRUCT(nmlcpp::ast::namelist, name_, data_)

#endif  // INCLUDE_AST_ADAPTED_H_
