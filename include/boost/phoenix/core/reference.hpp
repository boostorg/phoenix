/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_REFERENCE_HPP
#define PHOENIX_CORE_REFERENCE_HPP

#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/compose.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // References
    ////////////////////////////////////////////////////////////////////////////
    
    // function for evaluating references, e.g. ref( 123 )
    struct reference
    {
        template<typename T>
        struct compose : phoenix::compose<reference, T&>
        {};

        template<typename Sig>
        struct result;

        template<typename This, typename Env, typename T>
        struct result<This(Env &, T &)>
            : boost::result_of<eval_grammar(T &)>
        {};

        template<typename Env, typename T>
        typename boost::result_of<eval_grammar(T &)>::type
        operator()(Env & env, T & t) const
        {
            return eval(t);
        }
    };

    template<typename T>
    typename reference::compose<T>::result_type
    ref(T & t)
    {
        return reference::compose<T>()(t);
    }

    template<typename T>
    typename reference::compose<T const>::result_type
    cref(T & t)
    {
        return reference::compose<T const>()(t);
    }

}}

#endif
