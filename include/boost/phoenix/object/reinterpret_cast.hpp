/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_REINTERPRET_CAST_HPP
#define PHOENIX_OBJECT_REINTERPRET_CAST_HPP

#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/object/detail/cast_target.hpp>

namespace boost { namespace phoenix
{
    namespace tag {
        struct reinterpret_cast_ {};
    }

    namespace expression
    {
        template <typename T, typename U>
        struct reinterpret_cast_
            : expr<tag::reinterpret_cast_, T, U>
        {};
    }

	namespace rule
	{
		struct reinterpret_cast_
            : expression::reinterpret_cast_<proto::terminal<detail::cast_target<proto::_> >, meta_grammar>
		{};
	}

	template <typename Dummy>
	struct meta_grammar::case_<tag::reinterpret_cast_, Dummy>
		: proto::when<rule::reinterpret_cast_, proto::external_transform>
	{};
    
    template <typename T>
    struct reinterpret_cast_eval
        : proto::callable
    {
        typedef typename T::type result_type;

        template <typename Env, typename U>
        result_type
        operator()(Env& env, U const& u) const
        {
            return reinterpret_cast<result_type>(eval(u, env));
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::reinterpret_cast_, Dummy>
        : proto::lazy<reinterpret_cast_eval<evaluator(proto::_child_c<0>, _env) >(_env, proto::_child_c<1>)>
    {};

    template <typename T, typename U>
    typename expression::reinterpret_cast_<detail::cast_target<T>, U>::type const
    reinterpret_cast_(U const& u)
    {
        return expression::reinterpret_cast_<detail::cast_target<T>, U>::make(detail::cast_target<T>(), u);
    }
    
    template <typename T, typename U>
    typename expression::reinterpret_cast_<detail::cast_target<T>, U>::type const
    reinterpret_cast_(U & u)
    {
        return expression::reinterpret_cast_<detail::cast_target<T>, U>::make(detail::cast_target<T>(), u);
    }

}}

#endif
