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
    //
    // reference
    //
    //      function for evaluating references, e.g. ref(123)
    //
    ////////////////////////////////////////////////////////////////////////////

    namespace result_of
    {
        template <typename Env, typename T>
        struct reference
            : boost::result_of<eval_grammar(T&)>
        {};
    }
    
    struct reference
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename T>
        struct result<This(Env&, T&)>
            : result_of::reference<Env, T>
        {};

        template <typename Env, typename T>
        typename result_of::reference<Env, T>::type
        operator()(Env& env, T& ref) const
        {
            return eval(ref);
        }
    };
    
    template <typename T>
    struct make_reference : compose<reference, T&> {};

    template <typename T>
    typename make_reference<T>::type const
    ref(T& t)
    {
        return make_reference<T>()(t);
    }

    template <typename T>
    typename make_reference<T const>::type const
    cref(T& t)
    {
        return make_reference<T const>()(t);
    }

}}

#endif
