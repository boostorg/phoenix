/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_UNPACK_HPP
#define PHOENIX_CORE_UNPACK_HPP

#include <boost/fusion/include/size.hpp>
#include <boost/proto/proto.hpp>

namespace boost { namespace phoenix
{
	struct unpack {};

	namespace detail
	{
		template <typename Expr, typename State, typename Data, typename Transform, long Arity = fusion::result_of::size<Expr>::value>
		struct unpack_impl;
		
		template <typename Expr, typename State, typename Data, typename R>
		struct unpack_impl<Expr, State, Data, R(unpack), 1>
			: proto::transform_impl<Expr, State, Data>
		{
			typedef int result_type;

			result_type
			operator()(
				typename unpack_impl::expr_param e
			 , typename unpack_impl::state_param s
			 , typename unpack_impl::data_param d
			) const
			{
				std::cout << "yeha ... unpack without params 1\n";
				return 5;
			}
		};

		template <typename Expr, typename State, typename Data, typename R>
		struct unpack_impl<Expr, State, Data, R(unpack), 2>
			: proto::transform_impl<Expr, State, Data>
		{
			typedef int result_type;

			result_type
			operator()(
				typename unpack_impl::expr_param e
			 , typename unpack_impl::state_param s
			 , typename unpack_impl::data_param d
			) const
			{
				std::cout << "yeha ... unpack without params 2\n";
				return 5;
			}
		};

		template <typename Expr, typename State, typename Data, typename R, typename Seq>
		struct unpack_impl<Expr, State, Data, R(unpack(Seq)), 2>
			: proto::transform_impl<Expr, State, Data>
		{
			typedef int result_type;

			result_type
			operator()(
				typename unpack_impl::expr_param e
			 , typename unpack_impl::state_param s
			 , typename unpack_impl::data_param d
			) const
			{
				std::cout << "yeha ... unpack with Seq 2\n";
				return 5;
			}
		};

		template <typename Expr, typename State, typename Data, typename R>
		struct unpack_impl<Expr, State, Data, R(unpack), 3>
			: proto::transform_impl<Expr, State, Data>
		{
			typedef int result_type;

			result_type
			operator()(
				typename unpack_impl::expr_param e
			 , typename unpack_impl::state_param s
			 , typename unpack_impl::data_param d
			) const
			{
				std::cout << "yeha ... unpack without params 3\n";
				return 5;
			}
		};

		template <typename Expr, typename State, typename Data, typename R, typename Seq>
		struct unpack_impl<Expr, State, Data, R(unpack(Seq)), 3>
			: proto::transform_impl<Expr, State, Data>
		{
			typedef int result_type;

			result_type
			operator()(
				typename unpack_impl::expr_param e
			 , typename unpack_impl::state_param s
			 , typename unpack_impl::data_param d
			) const
			{
				typedef typename proto::when<proto::_, Seq>::template impl<Expr, State, Data>::result_type test_type;

				std::cout << "yeha ... unpack with Seq 3\n";
				std::cout << "Seq:\n";
				std::cout << typeid(Seq).name() << "\n";
				//std::cout << typeid(typename boost::result_of<proto::_child_c<0>(proto::when<proto::_, Seq>(Expr))>::type).name() << "\n";
				//std::cout << typeid(typename boost::result_of<Seq(Expr)>::type).name() << "\n";
				std::cout << typeid(test_type).name() << "\n";
				//std::cout << typeid(typename boost::result_of<proto::_child_c<0>(test_type)>::type).name() << "\n";
				std::cout << "Expr:\n";
				std::cout << typeid(Expr).name() << "\n";
				return 5;
			}
		};
	}
}}

namespace boost { namespace proto
{
	template <typename R>
	struct call<R(phoenix::unpack)>
		: proto::transform<call<R(phoenix::unpack)> >
	{
		template <typename Expr, typename State, typename Data>
		struct impl
			: phoenix::detail::unpack_impl<Expr, State, Data, R(phoenix::unpack)>
		{};
	};
	
	template <typename R, typename Seq>
	struct call<R(phoenix::unpack(Seq))>
		: proto::transform<call<R(phoenix::unpack(Seq))> >
	{
		template <typename Expr, typename State, typename Data>
		struct impl
			: phoenix::detail::unpack_impl<Expr, State, Data, R(phoenix::unpack(Seq))>
		{};
	};
	
	template <typename R, typename Seq, typename Fun>
	struct call<R(phoenix::unpack(Seq, Fun))>
		: proto::transform<call<R(phoenix::unpack(Seq, Fun))> >
	{
		template <typename Expr, typename State, typename Data>
		struct impl
			: proto::transform_impl<Expr, State, Data>
		{
			typedef int result_type;

			result_type
			operator()(
				typename impl::expr_param e
			 , typename impl::state_param s
			 , typename impl::data_param d
			) const
			{
				std::cout << "yeha ... unpack with Seq and Fun param\n";
				return 5;
			}
		};
	};

}}

#endif
