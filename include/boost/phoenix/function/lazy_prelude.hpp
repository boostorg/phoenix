////////////////////////////////////////////////////////////////////////////
// lazy prelude.hpp
//
// Build lazy operations for Phoenix equivalents for FC++
//
// These are equivalents of the Boost FC++ functoids in prelude.hpp
//
// Implemented so far:
//
// id (moved back to operators.hpp)
//
// A lot of what comes here uses the list type, so that will be needed first.
//
// Now that list<T> is available I can start to build things here.
//
// take(n,list)
//
////////////////////////////////////////////////////////////////////////////
// Interdependence:
// The old Boost FC++ has a set of headers which interelate and call each
// other in a complicated way. I am going to document the interdependence
// of the files here. I will then make sure that they are called correctly
// starting from this file. John Fletcher. February 2015.
////////////////////////////////////////////////////////////////////////////
// BoostFC++ header sequence:
// 
// prelude.hpp   -> list.hpp (optinally monad.hpp at end)
// list.hpp      -> reuse.hpp
// reuse.hpp     -> function.hpp
// function.hpp  -> ref_count.hpp operator.hpp
// ref_count.hpp -> config.hpp boost headers and RefCountType definition
// operator.hpp  -> lambda.hpp
// lambda.hpp    -> full.hpp (use of lambda internals is optional)
// full.hpp      -> smart.hpp curry.hpp pre_lambda.hpp (optionally full4.hpp)
// smart.hpp     -> signature.hpp
// curry.hpp     -> signature.hpp
// signature.hpp -> config.hpp
//
////////////////////////////////////////////////////////////////////////////
// Proposed order in lazy_prelude.hpp
// on the basis that files need what they call.
//
// lazy_config.hpp    (If needed)* probably not needed.
// lazy_signature.hpp (If needed)*
// lazy_smart.hpp     (If needed)*
// lazy_curry.hpp     (If needed)*
// lazy_full.hpp      (If needed)*
// lazy_operator.hpp  (absorb definition of RefCountType)
// lazy_function.hpp  (may not now be needed)
// lazy_reuse.hpp     (implemented without use of FC++ functions)
// lazy_list.hpp
//
// * file does not yet exist.
////////////////////////////////////////////////////////////////////////////
// This is implemented such that no other lazy_ file calls other lazy_ files.
// They do call their own external files, which may well be duplicates.
// That can be sorted out later.
////////////////////////////////////////////////////////////////////////////
// Notes: full and curry operations should be covered by Phoenix.
// The lambda operations are quite different from Phoenix lambda
// and will be omitted.
// The implementation monad can be postponed.
// Some of function and reuse are needed for the list type.
// I will review later whether they are part of the external interface.
//
// John Fletcher  February 2015.
////////////////////////////////////////////////////////////////////////////
/*=============================================================================
    Copyright (c) 2000-2003 Brian McNamara and Yannis Smaragdakis
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2015 John Fletcher

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/


#ifndef BOOST_PHOENIX_LAZY_PRELUDE
#define BOOST_PHOENIX_LAZY_PRELUDE

#include <exception>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/function.hpp>
#include "lazy_operator.hpp" //  (absorb definition of RefCountType)
//#include "lazy_function.hpp" // Not currently in use.
#include "lazy_reuse.hpp" // (implemented without use of FC++ functions)
#include "lazy_list.hpp"

////////////////////////////////////////////////////////////////////////////
// To come here, the Haskell Prelude things which need list<T>.
// Things which do not need list<T> can be in operator.hpp.
////////////////////////////////////////////////////////////////////////////

namespace boost {

  namespace phoenix {

    namespace impl {
      using fcpp::INV;
      using fcpp::VAR;
      using fcpp::reuser1;
      using fcpp::reuser2;
      using fcpp::reuser3;
      using boost::phoenix::arg_names::arg1;

        struct Pow {

            template <typename Sig>
            struct result;

            template <typename This, typename N, typename A0>
            struct result<This(N,A0)>
               : boost::remove_reference<A0>
            {};

            template <typename N, typename A0>
            A0 operator()(N n, const A0 & a0,
            reuser2<INV,VAR,INV,Pow,N,A0> r = NIL ) const {
              if ( n <= 0 )
                 return A0(1);
              else if ( n==1 )
                 return a0;
              else {
                A0 a1 = r( Pow(), n-1, a0)();
                return a0*a1;
              }
            }

         };

        struct Apply {

            template <typename Sig>
            struct result;

            template <typename This, typename N, typename F,typename A0>
            struct result<This(N,F,A0)>
               : boost::remove_reference<A0>
            {};

            template <typename N, typename F, typename A0>
            A0 operator()(N n, const F &f, const A0 & a0,
            reuser3<INV,VAR,INV,INV,Apply,N,F,A0> r = NIL ) const {
              if ( n <= 0 )
                 return a0;
              else if ( n==1 )
                 return f(arg1)(a0);
              else {
                A0 a1 = r( Apply(), n-1, f, a0)();
                return f(a1)();
              }
            }

         };


        struct Take {
          //template <class N,class L>
          //struct sig : public fun_type<typename L::force_result_type> {};
          template <typename Sig> struct result;

            template <typename This, typename N, typename L>
            struct result<This(N,L)>
          {
             typedef typename result_of::ListType<L>::force_result_type type;
          };

          template <class N,class L>
          typename result<Take(N,L)>::type
          operator()( N n, const L& l,
               reuser2<INV,VAR,VAR,Take,N,
               typename result_of::ListType<L>::force_result_type>
               r = NIL
           ) const {
            //std::cout << "Take ( " << n << " )" << std::endl;
            if( n <= 0 || null(l)() )
              return NIL;
            else {
            //std::cout << "Take ( " << n << " ) = " << head(l)() << std::endl;
              return cons( head(l)(), r( Take(), n-1, tail(l)() )() )();
            }
          }
        };

    }

    //BOOST_PHOENIX_ADAPT_CALLABLE(apply, impl::apply, 3)
    // Functors to be used in reuser will have to be defined
    // using boost::phoenix::function directly
    // in order to be able to be used as arguments.
    typedef boost::phoenix::function<impl::Pow> Pow;
    typedef boost::phoenix::function<impl::Apply> Apply;
    typedef boost::phoenix::function<impl::Take> Take;
    Pow pow;
    Apply apply;
    Take take;

    namespace fcpp {


    }

  }

}


#endif
