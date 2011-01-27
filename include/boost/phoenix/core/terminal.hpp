/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_TERMINAL_HPP
#define PHOENIX_CORE_TERMINAL_HPP

#include <boost/is_placeholder.hpp>

namespace boost { namespace phoenix
{
    template <typename T>
    struct is_custom_terminal
        : mpl::false_ {};

    template <typename T>
    struct custom_terminal;

    namespace rule
    {
        struct argument
            : proto::if_<boost::is_placeholder<proto::_value>()>
        {};

        struct custom_terminal
            : proto::if_<is_custom_terminal<proto::_value>()>
        {};
        
        struct terminal
            : proto::terminal<proto::_>
        {};
    }

    template <typename Grammar>
    struct meta_grammar::case_<proto::tag::terminal, Grammar>
        : proto::or_<
            proto::when<rule::argument       , proto::external_transform>
          , proto::when<rule::custom_terminal, proto::external_transform>
          , proto::when<rule::terminal       , proto::external_transform>
        >
    {};

    template <typename Grammar>
    struct default_actions::when<rule::custom_terminal, Grammar>
        : proto::lazy<custom_terminal<proto::_value>(proto::_value, _context)>
    {};

    namespace detail
    {
        template <typename N>
        struct placeholder_idx
            : mpl::int_<N::value>
        {};
    }
    
    template <typename Grammar>
    struct default_actions::when<rule::argument, Grammar>
        : proto::call<
            proto::functional::at(
                _env
              , detail::placeholder_idx<boost::is_placeholder<proto::_value>()>()
            )
        >
    {};
}}

#endif
