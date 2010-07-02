/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_VALUE_HPP
#define PHOENIX_CORE_VALUE_HPP

#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/compose.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // values
    //
    //      function for evaluating values, e.g. val(123)
    //
    ////////////////////////////////////////////////////////////////////////////

    namespace result_of
    {
        template <typename Env, typename T>
        struct value
            : boost::result_of<eval_grammar(T const&)>
        {};
    }

    struct value
    {
        template<typename Sig>
        struct result;

        template<typename This, typename Env, typename T>
        struct result<This(Env&,T const&)>
            : result_of::value<Env, T>
        {};

        template<typename Env, typename T>
        typename result_of::value<Env, T>::type
        operator()(Env& env, T const& t)
        {
            return eval(t);
        }
    };

    template <typename T>
    struct make_value : compose<value, T> {};

    template<typename T>
    typename make_value<T>::type const
    val(T const & t )
    {
        return make_value<T>()(t);
    }

    template<typename T>
    typename make_value<T>::type const
    val(T & t )
    {
        return make_value<T>()(t);
    }

}}

#endif
