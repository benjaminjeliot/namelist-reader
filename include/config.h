//
// include/config.h
//

#ifndef INCLUDE_CONFIG_H_
#define INCLUDE_CONFIG_H_

#include <functional>
#include <string>

#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/utility/error_reporting.hpp>

namespace nmlcpp {
namespace parser {
namespace x3 = boost::spirit::x3;

//! Iterator type
using iterator_type = std::string::const_iterator;

//! Phrase parse context type
using phrase_parse_context_type = x3::phrase_parse_context<x3::ascii::space_type>::type;

//! Error handler type
using error_handler_type = x3::error_handler<iterator_type>;

//! Error handler and phrase parse context type
using context_type = x3::context<x3::error_handler_tag, std::reference_wrapper<error_handler_type> const, phrase_parse_context_type>;

}
}

#endif  // INCLUDE_CONFIG_H_
