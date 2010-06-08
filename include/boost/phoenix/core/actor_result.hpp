/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ACTOR_RESULT_HPP
#define PHOENIX_CORE_ACTOR_RESULT_HPP

#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/fusion/container/vector/vector10.hpp>
#include <boost/utility/result_of.hpp>

#include <boost/mpl/void.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // Return type computation 
    ////////////////////////////////////////////////////////////////////////////
    template<typename Sig>
    struct actor_result;

    template <typename Actor>
    struct actor_result<Actor()>
      : boost::result_of<eval_grammar(Actor&, fusion::vector0<>&)>
    {};

    template <typename Actor, typename A0>
    struct actor_result<Actor(A0)>
      : boost::result_of<eval_grammar(Actor&, fusion::vector1<A0>&)>
    {};

    template <typename Actor, typename A0, typename A1>
    struct actor_result<Actor(A0, A1)>
      : boost::result_of<eval_grammar(Actor&, fusion::vector2<A0, A1>&)>
    {};
    
    /*... more ...*/
}}

#endif
