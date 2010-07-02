/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_IF_ELSE_HPP
#define PHOENIX_OBJECT_IF_ELSE_HPP

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Env, typename Cond, typename Then, typename Else>
        struct if_else
        {
            typedef typename boost::result_of<eval_grammar(Then const&, Env&)>::type then_type;
            typedef typename boost::result_of<eval_grammar(Else const&, Env&)>::type else_type;

            typedef typename
                mpl::if_<
                    mpl::and_<
                        is_same<then_type, else_type>
                      , is_reference<then_type>
                    >
                  , then_type
                  , typename remove_reference<then_type>::type
                >::type
                type;
        };
    }

    struct if_else_
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename Cond, typename Then, typename Else>
        struct result<This(Env&, Cond const&, Then const&, Else const&)>
            : result_of::if_else<Env, Cond, Then, Else>
        {};


        template <typename Env, typename Cond, typename Then, typename Else>
        typename result_of::if_else<Env, Cond, Then, Else>::type
        operator()(Env& env, Cond const& cond, Then const& then, Else const& else_) const
        {
            return eval(cond, env) ? eval(then, env) : eval(else_, env);
        }
    };


    template <typename Cond, typename Then, typename Else>
    struct make_if_else : compose<if_else_, Cond, Then, Else> {};

    template <typename Cond, typename Then, typename Else>
    typename make_if_else<Cond, Then, Else>::type
    if_else(Cond const & cond, Then const & then, Else const& else_)
    {
        return make_if_else<Cond, Then, Else>()(cond, then, else_);
    }


}}

#endif
