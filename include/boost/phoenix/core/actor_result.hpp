/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ACTOR_RESULT_HPP
#define PHOENIX_CORE_ACTOR_RESULT_HPP

#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/fusion/container/vector.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // Return type computation 
    ////////////////////////////////////////////////////////////////////////////
    template<class Sig>
    struct actor_result;

    template <template Actor, template A0>
    struct actor_result<Actor(A0)>
      : boost::result_of<eval_grammar(Actor&, fusion::vector<A0>&)>
    {};
    
    /*... more ...*/
}}

#endif
