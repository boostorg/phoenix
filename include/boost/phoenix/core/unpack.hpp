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
        template <
            typename Expr
          , typename State
          , typename Data
          , typename Seq
          , typename Fun
          , typename R
          , long Arity = fusion::result_of::size<
                typename proto::detail::uncvref<typename proto::when<proto::_, Seq>::template impl<Expr, State, Data>::result_type>::type
            >::value>
        struct unpack_impl;
        
        template <typename Expr, typename State, typename Data, typename Seq, typename Fun, typename R>
        struct unpack_impl<Expr, State, Data, Seq, Fun, R(), 1>
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

		template <typename Expr, typename State, typename Data, typename Seq, typename Fun, typename R>
		struct unpack_impl<Expr, State, Data, Seq, Fun, R(), 2>
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

        template <typename Expr, typename State, typename Data, typename Seq, typename Fun, typename R>
        struct unpack_impl<Expr, State, Data, Seq, Fun, R(), 3>
            : proto::transform_impl<Expr, State, Data>
        {
            //typedef proto::when<proto::_, Fun> fun_type;
            struct fun_type : proto::when<proto::_, Fun> {};
            
            // OK to evaluate is_callable<R> here. R should be compete by now.
            typedef
                typename mpl::if_c<
                    proto::is_callable<R>::value
                  , proto::call<R(fun_type(proto::_child_c<0>(Seq)), fun_type(proto::_child_c<1>(Seq)), fun_type(proto::_child_c<2>(Seq)))> // "R" is a function to call
                  , proto::make<R(fun_type(proto::_child_c<0>(Seq)), fun_type(proto::_child_c<1>(Seq)), fun_type(proto::_child_c<2>(Seq)))> // "R" is an object to constructa
                >::type
                which;
            
            typedef typename which::template impl<Expr, State, Data>::result_type result_type;
            
            result_type
            operator()(
                typename unpack_impl::expr_param e
              , typename unpack_impl::state_param s
              , typename unpack_impl::data_param d
            ) const
            {
                return typename which::template impl<Expr, State, Data>()(e, s, d);
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
			: phoenix::detail::unpack_impl<Expr, State, Data, Expr, proto::_, R()>//R(phoenix::unpack(Expr, proto::_))>
		{};
	};
	
	template <typename R, typename Seq>
	struct call<R(phoenix::unpack(Seq))>
		: proto::transform<call<R(phoenix::unpack(Seq))> >
	{

		template <typename Expr, typename State, typename Data>
		struct impl
			: phoenix::detail::unpack_impl<Expr, State, Data, Seq, proto::_, R()>//R(phoenix::unpack(Expr, proto::_))>
		{
        };
	};
	
	template <typename R, typename Seq, typename Fun>
	struct call<R(phoenix::unpack(Seq, Fun))>
		: proto::transform<call<R(phoenix::unpack(Seq, Fun))> >
	{
		template <typename Expr, typename State, typename Data>
		struct impl
			: phoenix::detail::unpack_impl<Expr, State, Data, Seq, Fun, R()>//R(phoenix::unpack(Expr, proto::_))>
		{};
	};

}}

#endif
