/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_IF_HPP
#define PHOENIX_STATEMENT_IF_HPP

#include <boost/config.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/compose.hpp>

#include <boost/phoenix/support/element_at.hpp>

#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4355) // 'this' used in base member initializer list
#endif

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // If-Else statements
    ////////////////////////////////////////////////////////////////////////////
    
    // Function for evaluating lambdas like: if_( foo )[ bar ].else_[ baz ]
    struct if_else_eval
    {
        typedef void result_type;
        
        template<typename Env, typename Cond, typename Then, typename Else>
        void
        operator()(Env & env, Cond const & cond, Then const & then, Else const & else_) const
        {
            if( eval( cond, env ) )
                eval( then, env );
            else
                eval( else_, env );
        }
    };

    // Function for evaluating lambdas like: if_( foo )[ bar ]
    struct if_eval
    {
        typedef void result_type;
        
        template<typename Env, typename Cond, typename Then>
        void
        operator()(Env & env, Cond const & cond, Then const & then) const
        {
            if( eval( cond, env ) )
                eval( then, env );
        }
    };

    // Generator for .else_[ expr ] branch.
    template<typename Cond, typename Then>
    struct else_gen
    {
        template<typename Else>
        struct compose : phoenix::compose<if_else_eval, Cond, Then, Else>
        {};

        else_gen(Cond const & cond, Then const & then)
            : cond( cond )
            , then( then ) {}

        template<typename Else>
        typename compose< Else >::result_type
        operator[](Else const & else_) const
        {
            return compose< Else >()(cond, then, else_);
        }

        Cond const & cond;
        Then const & then;
    };

    // We subclass actor so we can provide the member else_ (which is an
    // else_gen responsible for the .else_[ expr ] branch).
    template<typename Expr>
    struct if_actor : actor< Expr >
    {
        typedef actor< Expr > base_type;

        if_actor(base_type const & base)
            : base_type( base )
            , else_(element_at_c<0>(*this), element_at_c<1>(*this))
        {}

        typedef typename boost::phoenix::result_of::element_value_at_c<Expr, 0>::type cond_type;
        typedef typename boost::phoenix::result_of::element_value_at_c<Expr, 1>::type then_type;

        else_gen<cond_type, then_type> else_;
    };

    // Generator for if( cond )[ then ] branch.
    template<typename Cond>
    struct if_gen
    {
        template<typename Then>
        struct compose : phoenix::compose_ex<if_eval, if_actor, Cond, Then>
        {};

        if_gen(Cond const & cond)
            : cond( cond ) {}

        template<typename Then>
        typename compose<Then>::result_type
        operator[](Then const & then) const
        {
            return compose<Then>()(cond, then);
        }

        Cond const & cond;
    };

    template<typename Cond>
    if_gen<Cond>
    if_(Cond const & cond)
    {
        return if_gen<Cond>(cond);
    }
 
}}

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

#endif
