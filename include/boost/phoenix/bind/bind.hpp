/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_BIND_BIND_HPP
#define PHOENIX_BIND_BIND_HPP

//#include <boost/phoenix/core/expression.hpp>
//#include <boost/phoenix/core/unpack.hpp>
#include <boost/phoenix/function.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // Bind
    ////////////////////////////////////////////////////////////////////////////

#if 0
    PHOENIX_DEFINE_EXPRESSION_VARARG(bind, (meta_grammar), PHOENIX_ARG_LIMIT)

    struct bind_eval
        : proto::callable
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename F>
        struct result<This(Env &, F const &)>
            /*: boost::result_of<
                typename boost::result_of<evaluator(F const &, Env &)>::type()
            >*/
        {
            typedef int type;
        };
        typedef int result_type;

        template <typename Env, typename F>
        result_type//typename result<bind_eval(Env &, F const &)>::type
        operator()(Env & env, F const & f) const
        {
            eval(f, env);
            std::cout << typeid(detail::wrap<typename boost::result_of<evaluator(F const&, Env&)>::type>).name() << "\n";
            //std::cout << typeid(detail::wrap<typename boost::result_of<evaluator(F &, Env&)>::type>).name() << "\n";
            //std::cout << typeid(detail::wrap<typename proto::result_of::value<F>::type>).name() << "\n";
            //std::cout << typeid(detail::wrap<typename proto::result_of::value<F const &>::type>).name() << "\n";
            //std::cout << typeid(detail::wrap<typename proto::result_of::value<F &>::type>).name() << "\n";
            return 5;//typename result<bind_eval(Env &, F const &)>::type();
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::bind, Dummy>
        : proto::call<bind_eval(_env, unpack)>
    {};
#endif
    
    template <typename F>
    typename boost::result_of<function<F>()>::type const
    //typename expression::bind<F>::type
    bind(F f)
    {
        //return expression::bind<F>::make(f);
        return function<F>(f)();
    }

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_ARG_LIMIT,                                                  \
    <boost/phoenix/bind/bind.hpp>))
#include PHOENIX_ITERATE()

}}

#endif

#else
    
    template <typename F, PHOENIX_typename_A>
/*#if PHOENIX_ITERATION == 1
    typename disable_if<
        is_member_pointer<F>
      , typename boost::result_of<function<F>(A0 const&)>::type const
      >::type
#else*/
    //typename boost::result_of<function<F>(PHOENIX_A_const_ref)>::type const
    typename result_of::function<F, PHOENIX_A>::type const
//#endif
    bind(F f, PHOENIX_A_a)
    {
        return function<F>(f)(PHOENIX_a);
    }

#endif
