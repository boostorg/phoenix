/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_ARGUMENT_HPP_EAN_2008_05_10
#define BOOST_PHOENIX_ARGUMENT_HPP_EAN_2008_05_10

#include <iosfwd>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/config.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/next_prior.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/proto/proto.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/actor.hpp>

namespace boost { namespace phoenix
{
    namespace detail
    {
        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Int>
        struct argument
        {
            typedef typename Int::tag tag;
            typedef typename Int::value_type value_type;
            typedef argument<Int> type;
            typedef argument<typename Int::next> next;
            typedef argument<typename Int::prior> prior;
            BOOST_STATIC_CONSTANT(value_type, value = Int::value);

            friend std::ostream &operator<<(std::ostream &sout, argument<Int>)
            {
                return sout << "boost::phoenix::arg_names::arg" << (Int::value+1);
            }
        };

        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Int, typename Callable = proto::callable>
        struct at : proto::callable
        {
            template<class Sig>
            struct result;

            template<class This, class Cont>
            struct result<This(Cont)>
              : fusion::result_of::at<typename remove_reference<Cont>::type, Int>
            {};

            template<typename Cont>
            typename fusion::result_of::at<Cont, Int>::type
            operator ()(Cont &cont) const
            {
                return fusion::at<Int>(cont);
            }
        };
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<int I, typename _ = proto::is_proto_expr>
    struct argument
    {
        typedef
            typename proto::terminal<detail::argument<mpl::int_<I> > >::type
        base_type;

        BOOST_PROTO_BASIC_EXTENDS(base_type, argument<I>, detail::domain)

        // For backwards compatibility
        operator actor<argument<I> > const &() const
        {
            return argument<I,_>::argI;
        }

        static actor<argument<I> > const argI;
    };

    template<int I, typename _>
    actor<argument<I> > const argument<I,_>::argI = {{{{}}}};

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename Value, typename SubGrammar>
    struct is_terminal_nullary;

    template<typename Int, typename SubGrammar>
    struct is_terminal_nullary<detail::argument<Int>, SubGrammar>
      : mpl::false_
    {};

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename Value, typename SubGrammar>
    struct terminal_extension;

    template<typename Int, typename SubGrammar>
    struct terminal_extension<detail::argument<Int>, SubGrammar>
      : proto::otherwise<detail::at<Int>(proto::_data)>
    {};

    ////////////////////////////////////////////////////////////////////////////////////////////
    namespace arg_names
    {
    //  Phoenix style names    
        actor<argument<0> > const arg1  = {{{{}}}};
        actor<argument<1> > const arg2  = {{{{}}}};
        actor<argument<2> > const arg3  = {{{{}}}};

    //  BLL style names
        actor<argument<0> > const _1    = {{{{}}}};
        actor<argument<1> > const _2    = {{{{}}}};
        actor<argument<2> > const _3    = {{{{}}}};

    //  Bring in the rest or the Phoenix style arguments (arg4 .. argN+1)
    //  and BLL style arguments (_4 .. _N+1), using PP
        #define PHOENIX_DECLARE_ARG(Z, N, DATA)                                                     \
        actor<argument<N> > const BOOST_PP_CAT(arg, BOOST_PP_INC(N))  = {{{{}}}};                   \
        actor<argument<N> > const BOOST_PP_CAT(_, BOOST_PP_INC(N))  = {{{{}}}};                     \
        /**/
            
        BOOST_PP_REPEAT_FROM_TO(3, PHOENIX_ARG_LIMIT, PHOENIX_DECLARE_ARG, _)
        
        #undef PHOENIX_DECLARE_ARG
    }

}}

#endif
