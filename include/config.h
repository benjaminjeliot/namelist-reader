//
// include/config.h
//

#ifndef INCLUDE_CONFIG_H_
#define INCLUDE_CONFIG_H_

#include <string>

#include <boost/spirit/home/x3.hpp>

namespace nmlcpp {
namespace parser {
namespace x3 = boost::spirit::x3;

//! Iterator type used by the parser
using iterator_type = std::string::const_iterator;

//! Context type used by the parser
using context_type = x3::phrase_parse_context<x3::ascii::space_type>::type;
}
}

#endif  // INCLUDE_CONFIG_H_
