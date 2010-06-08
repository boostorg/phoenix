/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_VALUE_HPP
#define PHOENIX_CORE_VALUE_HPP

#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/as_actor.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // Values
    ////////////////////////////////////////////////////////////////////////////

    // function for evaluating values, e.g. val( 123 )
    struct value
    {
        template<typename T>
        struct as_actor : phoenix::as_actor<value, actor, T>
        {};

        template<typename Sig>
        struct result;

        template<typename This, typename Env, typename T>
        struct result<This(Env &,T &)>
            : boost::result_of<eval_grammar(T)>
        {};

        template<typename Env, typename T>
        typename boost::result_of<eval_grammar(T)>::type
        operator()(Env & env, T const & t)
        {
            return eval(t);
        }
    };

    template<typename T>
    typename value::as_actor<T>::result_type
    val(T const & t )
    {
        return value::as_actor<T>()(t);
    }

}}

#endif
