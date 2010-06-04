/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_META_GRAMMAR_HPP
#define PHOENIX_CORE_META_GRAMMAR_HPP

#include <boost/proto/proto.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // Our meta-grammar and expression evaluator
    ////////////////////////////////////////////////////////////////////////////
    struct eval_grammar
      : proto::switch_<struct eval_cases>
    {};
    
    ////////////////////////////////////////////////////////////////////////////
    // A function object we can call
    ////////////////////////////////////////////////////////////////////////////
    eval_grammar const eval = eval_grammar();

    ////////////////////////////////////////////////////////////////////////////
    // Open ended grammar dispatch allows us to extend the grammar
    // without modifying the code
    ////////////////////////////////////////////////////////////////////////////
    struct eval_cases
    {
        template <class Tag>
        struct case_ : proto::_default<eval_grammar> {};
    };

    ////////////////////////////////////////////////////////////////////////////
    // A dummy terminal that, when evaluated, returns the current state.
    ////////////////////////////////////////////////////////////////////////////
    struct env
    {};

    ////////////////////////////////////////////////////////////////////////////
    // wrapper for a Fusion extension evaluator function. Keep this POD.
    ////////////////////////////////////////////////////////////////////////////
    template <class Fun>
    struct funcwrap
    {
        typedef Fun type;
    };

    // Handling for terminals, with the special case for env terminals.
    struct func_grammar
      : proto::or_<
            proto::when<
                proto::terminal<funcwrap<proto::_> >, 
                mpl::deref<proto::_value>()>
          , proto::when<proto::terminal<env>, proto::_state>
          , proto::_
        >
    {};

    // Handling for function invocations. When _child0 is a 
    // funcwrap<>, don't evaluate the other child nodes. Just
    // pass then unevaluated to the function.
    template <>
    struct eval_cases::case_<proto::tag::function>
      : proto::or_<
            proto::when<
                proto::function<
                    proto::terminal<funcwrap<proto::_> >
                  , proto::terminal<env>
                  , proto::vararg<eval_grammar>
                >
              , proto::_default<func_grammar>
            >
          , proto::_default<eval_grammar>
        >
    {};
}}

#endif
