#if !PHOENIX_IS_ITERATING

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
#include <boost/fusion/container/vector.hpp>
#include <boost/proto/proto.hpp>
#include <boost/type_traits/remove_pointer.hpp>

#define M3(_, N, MAX)                                                       \
    BOOST_PP_COMMA_IF(BOOST_PP_SUB(MAX, N))                                 \
    BOOST_PP_CAT(A, N)                                                      \
/**/

#define M2(UNPACK, N, ARITY)                                                \
    BOOST_PP_ENUM_PARAMS(N, A)                                              \
    BOOST_PP_COMMA_IF(N)                                                    \
    UNPACK BOOST_PP_REPEAT_FROM_TO(N, ARITY, M3, ARITY)                     \
/**/

#define M0(Z, N, __) BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(BOOST_PP_INC(N), M1, N)

namespace boost { namespace phoenix
{
    struct unpack {};
    
    namespace detail
    {
        template <unsigned N>
        struct fusion_at_c
            : proto::callable
        {
            template <typename Sig>
            struct result;

            template <typename This, typename Seq>
            struct result<This(Seq)>
                : result<This(Seq const &)>
            {};

            template <typename This, typename Seq>
            struct result<This(Seq &)>
                : fusion::result_of::at_c<Seq, N>
            {};

            template <typename Seq>
            typename fusion::result_of::at_c<Seq, N>::type
            operator()(Seq & seq) const
            {
                return fusion::at_c<N>(seq);
            }

            template <typename Seq>
            typename fusion::result_of::at_c<Seq const, N>::type
            operator()(Seq const & seq) const
            {
                return fusion::at_c<N>(seq);
            }
        };

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
        struct unpack_impl<Expr, State, Data, Seq, Fun, R(), 0>
            : proto::transform_impl<Expr, State, Data>
        {
            struct fun_type : proto::when<proto::_, Fun> {};
            
            typedef proto::call<R()> which;

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
        
        template <typename Expr, typename State, typename Data, typename Seq, typename Fun, typename R>
        struct unpack_impl<Expr, State, Data, Seq, Fun, R(unpack), 0>
            : proto::transform_impl<Expr, State, Data>
        {
            struct fun_type : proto::when<proto::_, Fun> {};
            
            typedef proto::call<R()> which;

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
        
        template <typename Expr, typename State, typename Data, typename Seq, typename Fun, typename R, typename A0>
        struct unpack_impl<Expr, State, Data, Seq, Fun, R(A0, unpack), 0>
            : proto::transform_impl<Expr, State, Data>
        {
            struct fun_type : proto::when<proto::_, Fun> {};
            
            typedef proto::call<R(A0)> which;

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

#define M5(_, N, __) fun_type(fusion_at_c< N >(Seq))
        
        #define M1(Z, N, ARITY) \
        template <typename Expr, typename State, typename Data, typename Seq, typename Fun, typename R BOOST_PP_ENUM_TRAILING_PARAMS(ARITY, typename A)> \
        struct unpack_impl<Expr, State, Data, Seq, Fun, R(M2(unpack, N, ARITY)), EXPR_N> \
            : proto::transform_impl<Expr, State, Data> \
        { \
            struct fun_type : proto::when<proto::_, Fun> {}; \
            \
            typedef proto::call<R(M2(BOOST_PP_ENUM(EXPR_N, M5, EXPR_N), N, ARITY))> \
                which; \
            \
            typedef typename which::template impl<Expr, State, Data>::result_type result_type; \
            \
            result_type \
            operator()( \
                typename unpack_impl::expr_param e \
              , typename unpack_impl::state_param s \
              , typename unpack_impl::data_param d \
            ) const \
            { \
                return typename which::template impl<Expr, State, Data>()(e, s, d); \
            } \
            \
        }; \
        /**/
        
        #define PHOENIX_ITERATION_PARAMS                                        \
            (3, (1, BOOST_PROTO_MAX_ARITY,                                      \
            <boost/phoenix/core/unpack.hpp>))
#include PHOENIX_ITERATE()

        #undef M1

	}
}}


namespace boost { namespace proto
{
    template <unsigned N>
    struct is_callable<phoenix::detail::fusion_at_c<N> > : mpl::true_ {};

    #define M1(Z, N, ARITY)                                                     \
    template <typename R BOOST_PP_ENUM_TRAILING_PARAMS(ARITY, typename A)>      \
    struct call<R(M2(phoenix::unpack(), N, ARITY))>                             \
		: proto::transform<call<R(M2(phoenix::unpack(), N, ARITY))> >           \
	{                                                                           \
		template <typename Expr, typename State, typename Data>                 \
		struct impl                                                             \
			: phoenix::detail::unpack_impl<                                     \
                Expr, State, Data, proto::_, proto::_, R(M2(phoenix::unpack, N, ARITY))> \
		{};                                                                     \
	};                                                                          \
	                                                                            \
    template <typename R BOOST_PP_ENUM_TRAILING_PARAMS(ARITY, typename A)>      \
    struct call<R(M2(phoenix::unpack, N, ARITY))>                               \
		: proto::transform<call<R(M2(phoenix::unpack, N, ARITY))> >             \
	{                                                                           \
		template <typename Expr, typename State, typename Data>                 \
		struct impl                                                             \
			: phoenix::detail::unpack_impl<                                     \
                Expr, State, Data, proto::_, proto::_, R(M2(phoenix::unpack, N, ARITY))>                     \
		{};                                                                     \
	};                                                                          \
	                                                                            \
	template <typename R, typename Seq                                          \
        BOOST_PP_ENUM_TRAILING_PARAMS(ARITY, typename A)>                       \
	struct call<R(M2(phoenix::unpack(Seq), N, ARITY))>                          \
		: proto::transform<call<R(M2(phoenix::unpack(Seq), N, ARITY))> >        \
	{                                                                           \
		template <typename Expr, typename State, typename Data>                 \
		struct impl                                                             \
			: phoenix::detail::unpack_impl<                                     \
                Expr, State, Data, typename boost::remove_pointer<Seq>::type, proto::_, R(M2(phoenix::unpack, N, ARITY))>                          \
		{                                                                       \
        };                                                                      \
	};                                                                          \
                                                                                \
	template <typename R, typename Seq, typename Fun                            \
        BOOST_PP_ENUM_TRAILING_PARAMS(ARITY, typename A)>                       \
	struct call<R(M2(phoenix::unpack(Seq, Fun), N, ARITY))>                     \
		: proto::transform<call<R(M2(phoenix::unpack(Seq, Fun), N, ARITY))> >   \
	{                                                                           \
		template <typename Expr, typename State, typename Data>                 \
		struct impl                                                             \
			: phoenix::detail::unpack_impl<Expr, State, Data, typename boost::remove_pointer<Seq>::type, Fun, R(M2(phoenix::unpack, N, ARITY))>    \
		{};                                                                     \
	};                                                                          \
    /**/
    
    BOOST_PP_REPEAT(BOOST_PROTO_MAX_ARITY, M0, _)

    #undef M1

}}
    
#undef M3
#undef M2
#undef M0

#endif

#else // BOOST_PP_IS_ITERATING

#define EXPR_N BOOST_PP_ITERATION()
        
        BOOST_PP_REPEAT(BOOST_PROTO_MAX_ARITY, M0, _)

#endif
