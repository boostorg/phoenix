/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OPERATOR_MEMBER_HPP_EAN_2008_05_28
#define PHOENIX_OPERATOR_MEMBER_HPP_EAN_2008_05_28

#include <boost/ref.hpp>
#include <boost/type_traits/is_member_object_pointer.hpp>
#include <boost/type_traits/is_member_function_pointer.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/fusion/include/push_front.hpp>
#include <boost/fusion/include/as_vector.hpp>
#include <boost/proto/proto.hpp>

namespace boost { namespace phoenix
{
    namespace detail
    {
        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename SubGrammar, typename Callable = proto::callable>
        struct bind_mem_ptr
          : proto::transform<bind_mem_ptr<SubGrammar> >
        {
            template<typename Expr, typename State, typename Data>
            struct impl
              : proto::transform_impl<Expr, State, Data>
            {
                typedef typename
                    proto::result_of::unpack_expr<
                        proto::tag::function
                      , domain
                      , typename fusion::result_of::as_vector<
                            typename fusion::result_of::push_front<
                                typename fusion::result_of::push_front<
                                    typename impl::data
                                  , typename proto::result_of::left<Expr>::type
                                >::type
                              , typename proto::result_of::right<Expr>::type
                            >::type
                        >::type
                    >::type
                result_type;

                result_type operator()(
                    typename impl::expr_param expr
                  , typename impl::state_param
                  , typename impl::data_param data
                ) const
                {
                    return proto::unpack_expr<proto::tag::function, domain>(
                        fusion::as_vector(
                            fusion::push_front(
                                fusion::push_front(
                                    data
                                  , boost::ref(proto::left(expr))
                                )
                              , boost::ref(proto::right(expr))
                            )
                        )
                    );
                }
            };
        };
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    template<typename SubGrammar>
    struct extension<proto::tag::mem_ptr, SubGrammar>
      : proto::when<
            proto::mem_ptr<evaluator<SubGrammar>, proto::terminal<proto::_> >
          , proto::if_<
                is_member_function_pointer<proto::_value(proto::_right)>()
              , detail::bind_mem_ptr<SubGrammar>
              , proto::_default<evaluator<SubGrammar> >
            >
        >
    {};

}}

#endif
