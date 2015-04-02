////////////////////////////////////////////////////////////////////////////
// lazy prelude.hpp
//
// Build lazy operations for Phoenix equivalents for FC++
//
// These are equivalents of the Boost FC++ functoids in prelude.hpp
//
// Usage:  All of these are functors which need various numbers of arguments.
//         Those can be supplied as real arguments or as Phoenix arguments.
//         Execution will happen when all the arguments are supplied.
// e.g.
//         take(2,list)()  or  take(2,arg1)(list)
//
// Implemented so far:
//
// id (moved back to operators.hpp)
//
// A lot of what comes here uses the list type, so that will be needed first.
//
// Now that list<T> is available I can start to build things here.
//
// pow(n,x)      x^n
// apply(n,f,x)  f^n(x)
//
/////////////////////////////////////////////
// compose is Haskell's operator (.)       //
// compose(f,g)(x)        = f( g(x) )      //
// compose(f,g)(x,y)      = f( g(x,y) )    //
// compose(f,g)(x,y,z)    = f( g(x,y,z) )  //
//////////////////////////////////////////////////////
// compose also applies f(a,b) to the results of    //
// 2 functions g and h to the same argument(s).     //
// e.g. a = g(x,y) and b = h(x,y)                   //
//////////////////////////////////////////////////////
// compose(f,g,h)(x)     = f( g(x),     h(x) )      //
// compose(f,g,h)(x,y)   = f( g(x,y),   h(x,y) )    //
// compose(f,g,h)(x,y,z) = f( g(x,y,z), h(x,y,z) )  //
//////////////////////////////////////////////////////
//
// until(pred,f,start)         - if pred(start) is true, return start
//                               apply value = f(start)
//                               apply value = f(value)
//                               until pred(value) is true
//                               return value
//
// The predicate argument pred must be a lazy function taking one argument
// and returning bool.
// This can be a lazy function with an argument already.
// This has to be declared before the call to until.
// The type can be declated using Predicate as in this example:
//
//    Predicate<int>::type f(greater(arg1,10));
//    std::cout << until(f, inc, 1)() << std::endl;
//
// until2(pred,f,start,value2) - if pred(start,value2) is true, return start
//                               apply value1 = f(start)
//                               apply value1 = f(value1)
//                               until pred(value1,value2) is true
//                               return value1
//
// NOTE: until2 has been defined because this code does not support
//       FC++ currying, so that a partial function cannot be passed
//       as an argument. This provides a way of passing a second parameter.
//       There is now the option to use Predicate<T> as shown above.
//
// odd(n)     true if n is odd
// even(n)    true if n is even
//
// last(list)
// all_but_last(list)
// at_(list,n) (renamed from at because of at in stl/container/container.hpp)
// length(list)
// filter(pred,list)
// iterate(function,value)
// repeat(value)
// take(n,list)
// drop(n,list)
// enum_from(x)
// enum_from_to(x,y)
// foldr fold_right (synonyms)
// foldl fold_left  (synonyms)
// scanr scan_right (synonyms)
// scanl scan_left  (synonyms)
// foldr1 fold_right_one (synonyms)
// foldl1 fold_left_one  (synonyms)
// scanr1 scan_right_one (synonyms)
// scanl1 scan_left_one  (synonyms)
// iterate
//
// Things to build lazy functors from non-lazy code.
//
// ptr_to_fun  for 1, 2 3 or 4 arguments
// ptr_to_fun0 for nullary functions
// ptr_to_mem_fun for member functions with 0 to 3 arguments.
//
// NOTE: ptr_to_fun0 is not needed in FC++. Here the nullary case is handled
//       separately, as is the case in phoenix/function. The internal structure
//       is quite different.
//       Also, ptr_to_mem_fun is not separate in FC++ but is needed here.
//
// These bind all the arguments to create an object of
// type boost::function0<void>
//
// thunk1 - thunk1(function,argument1)
// thunk2 - thunk2(function,argument1,argument2)
// thunk3 - thunk3(function,argument1,argument2,argument3)
//
// The function can be ptr_to_fun or ptr_to_mem_fun.
//
// See examples of usage where the code is located at the end of the file.
//
////////////////////////////////////////////////////////////////////////////
//                         Change of policy:
// I am going to follow FC++ practice and give all structs
// inside namespace impl a leading X to the name for clarity.
// This is not in 3.2.0 (Boost 1.58.0) and will go into the next release.
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
// lazy_smart.hpp     (If needed)*
// lazy_curry.hpp     (If needed)*
// lazy_full.hpp      (If needed)*
// lazy_operator.hpp  (absorb definition of RefCountType)
// lazy_function.hpp  (may not now be needed)
// lazy_reuse.hpp     (implemented without use of FC++ functions)
// lazy_list.hpp
// lazy_signature.hpp (hold structs for return types)
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
// John Fletcher  February to April 2015.
////////////////////////////////////////////////////////////////////////////
/*=============================================================================
    Copyright (c) 2000-2003 Brian McNamara and Yannis Smaragdakis
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2015 John Fletcher

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/


#ifndef BOOST_PHOENIX_FUNCTION_LAZY_PRELUDE
#define BOOST_PHOENIX_FUNCTION_LAZY_PRELUDE

#include <exception>
#include <vector>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/function.hpp>
#include <boost/phoenix/scope.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/function/lazy_smart.hpp>
#include <boost/phoenix/function/lazy_operator.hpp>
#include <boost/phoenix/function/lazy_reuse.hpp>
#include <boost/phoenix/function/lazy_list.hpp>
#include <boost/phoenix/function/lazy_signature.hpp>

////////////////////////////////////////////////////////////////////////////
// To come here, the Haskell Prelude things which need list<T>.
// Things which do not need list<T> are in lazy_operator.hpp.
////////////////////////////////////////////////////////////////////////////

namespace boost {

  namespace phoenix {

    // These are in fcpp namespace as they introduce an FC++ style.
    namespace fcpp {

    template <typename T>
    struct Predicate {
        typedef typename boost::function1<bool,T> fun1_bool_T;
        typedef typename boost::phoenix::function<fun1_bool_T> bool_F_T;
        typedef bool_F_T type;
    };

    template <typename R>
    struct Function0 {
        typedef typename boost::function0<R> fun0_R;
        typedef typename boost::phoenix::function<fun0_R> R_F;
        typedef R_F type;
    };

    template <typename R,typename A0>
    struct Function1 {
        typedef typename boost::function1<R,A0> fun1_R_A0;
        typedef typename boost::phoenix::function<fun1_R_A0> R_F_A0;
        typedef R_F_A0 type;
    };

    template <typename R, typename A0, typename A1>
    struct Function2 {
      typedef typename boost::function2<R,A0,A1> fun2_R_A0_A1;
        typedef typename boost::phoenix::function<fun2_R_A0_A1> R_F_A0_A1;
        typedef R_F_A0_A1 type;
    };

    }

    namespace impl {
      using fcpp::INV;
      using fcpp::VAR;
      using fcpp::reuser1;
      using fcpp::reuser2;
      using fcpp::reuser3;
      using fcpp::reuser4;
      using boost::phoenix::arg_names::arg1;

         struct XPow {

            template <typename Sig>
            struct result;

            template <typename This, typename N, typename A0>
            struct result<This(N,A0)>
               : boost::remove_reference<A0>
            {};

            template <typename N, typename A0>
            A0 operator()(N n, const A0 & a0,
            reuser2<INV,VAR,INV,XPow,N,A0> r = NIL ) const {
              if ( n <= 0 )
                 return A0(1);
              else if ( n==1 )
                 return a0;
              else {
                A0 a1 = r( XPow(), n-1, a0)();
                return a0*a1;
              }
            }

         };

         struct XApply {

            template <typename Sig>
            struct result;

            template <typename This, typename N, typename F,typename A0>
            struct result<This(N,F,A0)>
               : boost::remove_reference<A0>
            {};

            template <typename N, typename F, typename A0>
            A0 operator()(N n, const F &f, const A0 & a0,
            reuser3<INV,VAR,INV,INV,XApply,N,F,A0> r = NIL ) const {
              if ( n <= 0 )
                 return a0;
              else if ( n==1 )
                 return f(arg1)(a0);
              else {
                A0 a1 = r( XApply(), n-1, f, a0)();
                return f(a1)();
              }
            }

         };

         struct XOdd {
            template <typename Sig>
            struct result;

            template <typename This, typename T>
            struct result<This(T)>
            {
              typedef bool type;
            };

            template <class T>
            typename result<XOdd(T)>::type operator()( const T& x ) const {
               return x%2==1;
            }
         };

         struct XEven {
            template <typename Sig>
            struct result;

            template <typename This, typename T>
            struct result<This(T)>
            {
              typedef bool type;
            };

            template <class T>
            typename result<XEven(T)>::type operator()( const T& x ) const {
               return x%2==0;
            }
         };

    }
    typedef boost::phoenix::function<impl::XPow>   Pow;
    typedef boost::phoenix::function<impl::XApply> Apply;
    typedef boost::phoenix::function<impl::XOdd>   Odd;
    typedef boost::phoenix::function<impl::XEven>  Even;
    Pow   pow;
    Apply apply;
    Odd   odd;
    Even  even;

    namespace impl {
      using fcpp::INV;
      using fcpp::VAR;
      using fcpp::reuser1;
      using fcpp::reuser2;
      using fcpp::reuser3;
      using boost::phoenix::arg_names::arg1;
      using boost::phoenix::arg_names::arg2;
      using boost::phoenix::arg_names::arg3;

      ///////////////////////////////////////////////
      //// COMPOSE IS NOW IN OPERATION           ////
      ///////////////////////////////////////////////
      // compose is Haskell's operator (.)         //
      // compose(f,g)(x)     = f( g(x) )           //
      // compose(f,g)(x,y)   = f( g(x,y) )         //
      // compose(f,g)(x,y,z) = f( g(x,y,z) )       //
      //////////////////////////////////////////////////////
      // compose also applies f(a,b) to the results of    //
      // 2 functions g and h to the same argument(s).     //
      // e.g. a = g(x,y) and b = h(x,y)                   //
      //////////////////////////////////////////////////////
      // compose(f,g,h)(x)     = f( g(x),     h(x) )      //
      // compose(f,g,h)(x,y)   = f( g(x,y),   h(x,y) )    //
      // compose(f,g,h)(x,y,z) = f( g(x,y,z), h(x,y,z) )  //
      //////////////////////////////////////////////////////
      // The structure can be simpler than in FC++ //
      // because the number of arguments can be    //
      // dealt with by overloading in this helper. //
      // It is not then needed to know how many    //
      // arguments there are for function g().     //
      ///////////////////////////////////////////////
      template <class F, class G>
      class XComposeHelper
      {
         F f;
         G g;
      public:
         XComposeHelper( const F& a, const G& b ) : f(a), g(b) {}
        template <typename Sig> struct result;

        template <typename This, typename X>
        struct result<This(X)>
        {
          typedef typename RTFGX<F,G,X>::type type;
        };

        template <typename This, typename X, typename Y>
        struct result<This(X,Y)>
        {
          typedef typename RTFGXY<F,G,X,Y>::type type;
        };

        template <typename This, typename X, typename Y, typename Z>
        struct result<This(X,Y,Z)>
        {
          typedef typename RTFGXYZ<F,G,X,Y,Z>::type type;
        };

        template <class X>
        typename result<XComposeHelper(X)>::type
        operator()(const X & x) const {
          return f( g(x) )();
        }

        template <class X, class Y>
        typename result<XComposeHelper(X,Y)>::type
        operator()(const X & x,const Y & y) const {
          return f( g(x,y) )();
        }

        template <class X, class Y, class Z>
        typename result<XComposeHelper(X,Y,Z)>::type
        operator()(const X & x,const Y & y,const Z & z) const {
          return f( g(x,y,z) )();
        }
     };

      template <class F, class G, class H>
      class XCompose2Helper
      {
         F f;
         G g;
         H h;
      public:
         XCompose2Helper( const F& a, const G& b, const H& c ) :
             f(a), g(b), h(c) {}
         template <typename Sig> struct result;

         template <typename This, typename X>
         struct result<This(X)>
         {
           typedef typename RTFGHX<F,G,H,X>::type type;
         };

         template <typename This, typename X, typename Y>
         struct result<This(X,Y)>
         {
           typedef typename RTFGHXY<F,G,H,X,Y>::type type;
         };

         template <typename This, typename X, typename Y, typename Z>
         struct result<This(X,Y,Z)>
         {
           typedef typename RTFGHXYZ<F,G,H,X,Y,Z>::type type;
         };

         template <class X>
         typename result<XCompose2Helper(X)>::type
         operator()(const X & x) const {
           return f( g(x), h(x) )();
         }

         template <class X, class Y>
         typename result<XCompose2Helper(X,Y)>::type
         operator()(const X & x,const Y & y) const {
           return f( g(x,y), h(x,y) )();
         }

         template <class X, class Y, class Z>
         typename result<XCompose2Helper(X,Y,Z)>::type
         operator()(const X & x,const Y & y,const Z & z) const {
           return f( g(x,y,z), h(x,y,z) )();
         }
     };

     /////////////////////////////////////////////////////////////
     // As an exception, this class does not need to be wrapped //
     // in boost::phoenix::function as the object returned      //
     // by the Helper is already wrapped.                       //
     /////////////////////////////////////////////////////////////
     class XCompose {

      template <class F, class G> struct Helper
      {
        typedef typename remove_RC<F>::type FType;
        typedef typename remove_RC<G>::type GType;
        typedef XComposeHelper<FType,GType> CType;
        typedef typename boost::phoenix::function<CType> F_C_F_G;
        typedef F_C_F_G Result;
        static Result go( const F& f, const G& g )
        {
          F_C_F_G f_c_f_g(CType(f,g));
          //std::cout << "Helper<F,G>" << std::endl;
          return f_c_f_g;
        }
      };

       template <class F, class G, class H> struct Helper2
      {
        typedef typename remove_RC<F>::type FType;
        typedef typename remove_RC<G>::type GType;
        typedef typename remove_RC<H>::type HType;
        typedef XCompose2Helper<FType,GType,HType> CType;
        typedef typename boost::phoenix::function<CType> F_C_F_G_H;
        typedef F_C_F_G_H Result;
        static Result go( const F& f, const G& g, const H& h )
        {
          F_C_F_G_H f_c_f_g_h(CType(f,g,h));
          //std::cout << "Helper<F,G>" << std::endl;
          return f_c_f_g_h;
        }
      };

      public:
        template <typename Sig> struct result;

        template <typename This, typename FF,typename GG>
        struct result<This(FF,GG)>
        {
          typedef typename remove_RC<FF>::type FType;
          typedef typename remove_RC<GG>::type GType;
          typedef typename Helper<FType,GType>::Result type;
        };

        template <typename This, typename FF,typename GG, typename HH>
        struct result<This(FF,GG,HH)>
        {
          typedef typename remove_RC<FF>::type FType;
          typedef typename remove_RC<GG>::type GType;
          typedef typename remove_RC<HH>::type HType;
          typedef typename Helper2<FType,GType,HType>::Result type;
        };

        template <class F, class G>
        typename result<XCompose(F,G)>::type operator()
                 ( const F& f, const G& g ) const
        {
          typedef typename remove_RC<F>::type FType;
          typedef typename remove_RC<G>::type GType;
          return Helper<FType,GType>::go( f, g );
        }

        template <class F, class G, class H>
        typename result<XCompose(F,G,H)>::type operator()
                 ( const F& f, const G& g, const H& h ) const
        {
          typedef typename remove_RC<F>::type FType;
          typedef typename remove_RC<G>::type GType;
          typedef typename remove_RC<H>::type HType;
          return Helper2<FType,GType,HType>::go( f, g, h );
        }

     };

      // I cannot yet do currying to pass e.g. greater(9,arg1)
      // as a function. This can be done using Predicate<T>::type.
         struct XUntil {

             template <typename Sig> struct result;

             template <typename This, typename Pred, typename Unary, typename T>
             struct result<This(Pred,Unary,T)>
                : boost::remove_reference<T> {};

             template <class Pred, class Unary, class T>
             T operator()( const Pred& p,const Unary& op,const T &start) const
             {
               T tmp = start;
               while( !p(tmp)() ) {
                 tmp = apply(1,op,tmp)();
               }
                return tmp;
             }

          };

          struct XUntil2 {

             template <typename Sig> struct result;

             template <typename This, typename Binary, typename Unary,
                       typename T, typename X>
             struct result<This(Binary,Unary,T,X)>
                : boost::remove_reference<T> {};

             template <class Binary, class Unary, class T, class X>
             typename result<XUntil2(Binary,Unary,T,X)>::type
             operator()( const Binary& p, const Unary& op, const T & start,
                        const X & check ) const
             {
               T tmp1 = start;
               T tmp2;
               while( !p(tmp1,check)() ) {
                 tmp2 = apply(1,op,tmp1)();
                 tmp1 = tmp2;
                 
               }
               return tmp1;
             }
          };

          struct XLast {
             template <typename Sig> struct result;

             template <typename This, typename L>
             struct result<This(L)>
             {
               typedef typename result_of::ListType<L>::value_type type;
             };

             template <class L>
             typename result<XLast(L)>::type
             operator()( const L& ll ) const {
               size_t x = 0;
               typename result_of::ListType<L>::delay_result_type l = delay(ll);
               while( !null( tail(l)() )() ) {
                 l = tail(l)();
                 ++x;
#ifndef BOOST_PHOENIX_NO_LAZY_EXCEPTIONS
                 if (x > BOOST_PHOENIX_FUNCTION_MAX_LAZY_LIST_LENGTH)
                   break;
#endif
               }
#ifndef BOOST_PHOENIX_NO_LAZY_EXCEPTIONS
                 if (x > BOOST_PHOENIX_FUNCTION_MAX_LAZY_LIST_LENGTH)
                     throw lazy_exception("Your list is too long!!");
#endif
                 return head(l)();
             }
          };

          struct XInit {

             template <typename Sig> struct result;

             template <typename This, typename L>
             struct result<This(L)>
             {
               typedef typename result_of::ListType<L>::force_result_type type;
             };

             template <class L>
             typename result<XInit(L)>::type
             operator()( const L& l,
                         reuser1<INV,VAR,XInit,
                         typename result_of::ListType<L>::delay_result_type>
                         r = NIL ) const {
               if( null( tail( l )() )() )
                   return NIL;
               else
                   return cons( head(l)(), r( XInit(), tail(l)() )() )();
               }
          };

          struct XLength {
            template <typename Sig> struct result;

            template <typename This, typename L>
            struct result<This(L)>
            {
               typedef size_t type;
            };

            template <class L>
            size_t operator()( const L& ll ) const {
              typename L::delay_result_type l = delay(ll);
              size_t x = 0;
              while( !null(l)() ) {
                  l = tail(l);
                  ++x;
                  if (x > BOOST_PHOENIX_FUNCTION_MAX_LAZY_LIST_LENGTH)
                     break;
              }
#ifndef BOOST_PHOENIX_NO_LAZY_EXCEPTIONS
              if (x > BOOST_PHOENIX_FUNCTION_MAX_LAZY_LIST_LENGTH)
                   throw lazy_exception("Your list is too long!!");
#endif
              return x;
            }
          };

          // at is Haskell's operator (!!)
          // This is zero indexed.  at(l,0)() returns the first element.
          struct XAt {
            template <typename Sig> struct result;

            template <typename This, typename L, typename N>
            struct result<This(L,N)>
            {
               typedef typename result_of::ListType<L>::value_type type;
            };

              template <class L>
              typename result<XAt(L,size_t)>::type
              operator()( L l, size_t n ) const {
                  while( n!=0 ) {
                      l = tail(l);
                      --n;
                  }
                  return head(l)();
              }
          };

         template <class P,class L>
         struct FilterH
          {
              P p;
              L l;
              FilterH( const P& pp, const L& ll) : p(pp), l(ll) {}
              template <typename Sig> struct result;

              template <typename This, class PP, class LL>
              struct result<This(PP,LL)>
              {
                typedef typename boost::phoenix::result_of::
                        ListType<LL>::delay_result_type type;
              };
                typename result<FilterH(P,L)>::type operator()() const {
                typedef typename result_of::ListType<L>::
                        delay_result_type result_type;
                typedef boost::function0<result_type> Fun2_R_P_L;
                typedef boost::phoenix::function<Fun2_R_P_L> FilterH_R_P_L;
                if (null(l)() )
                   return NIL;
                Fun2_R_P_L fun2_R_P_L = FilterH<P,L>(p,tail(l));
                FilterH_R_P_L filterh_R_P_L(fun2_R_P_L);
                if( p(head(l))() )
                   return cons( head(l)(), filterh_R_P_L() );
                else
                   return filterh_R_P_L();
              }
          };
      // Note: this isn't lazy (even if 'op' is 'cons').
      // That is because it works from the end backwards.
          struct XFoldr {
              template <typename Sig> struct result;
 
              template <typename This, typename Op, typename E,typename L>
              struct result<This(Op,E,L)> : boost::remove_reference<E>
              {
              };

              template <class Op, class E, class L>
              typename result<XFoldr(Op,E,L)>::type
              operator()( const Op& op, const E& e, const L& l ) const {
                  if ( null(l)() )
                      return e;
                  else
                      return op( head(l), XFoldr()( op, e, tail(l)() ) )();
              }
          };

          struct XFoldl {
              template <typename Sig> struct result;

              template <typename This, typename Op, typename E,typename L>
              struct result<This(Op,E,L)> : boost::remove_reference<E>
              {
              };

              template <class Op, class E, class L>
              typename result<XFoldl(Op,E,L)>::type
              operator()( const Op& op, const E & e, const L& ll ) const {
                  typename result_of::ListType<L>::delay_result_type
                       l = delay(ll);
                  E tmp = e;
                  while( !null(l)() ) {
                     tmp = op(tmp,head(l))();
                     l = tail(l);
                  }
                  return tmp;
              }
          };

          struct XScanr {
              template <typename Sig> struct result;

              template <typename This, typename Op, typename E,typename L>
              struct result<This(Op,E,L)>
              {
                  typedef typename boost::remove_reference<E>::type EE;
                  typedef typename boost::remove_const<EE>::type EEE;
                  typedef typename boost::remove_reference<L>::type LL;
                  typedef typename LL::template cons_rebind<EEE>::type type;
              };

               template <class Op, class E, class L>
               typename result<XScanr(Op,E,L)>::type
               operator()( const Op& op, const E& e, const L& l ) const {
                   typedef typename boost::remove_reference<E>::type EE;
                   typedef typename boost::remove_const<EE>::type EEE;
                   typedef typename boost::remove_reference<L>::type LL;
                   typedef typename LL::template cons_rebind<EEE>::type EL;
                   if( null(l)() ) {
                       EL empty;
                       return cons( e, empty )();
                   }
                   else {
                       EL temp = XScanr()( op, e, tail(l)() );
                       return cons( op( head(l)(), head(temp)() ), temp )();
                   }
               }
          };

          struct XScanl {
              template <typename Sig> struct result;

              template <typename This, typename Op, typename E,typename L>
              struct result<This(Op,E,L)>
              {
                  typedef typename boost::remove_reference<E>::type EE;
                  typedef typename boost::remove_const<EE>::type EEE;
                  typedef typename boost::remove_reference<L>::type LL;
                  typedef typename LL::template cons_rebind<EEE>::type type;
              };

              template <class Op, class E, class L>
              typename result<XScanl(Op,E,L)>::type
              operator()( const Op& op, const E& e, const L& l,
                          reuser3<INV,INV,VAR,VAR,XScanl,Op,
                          typename boost::remove_const<E>::type,
               typename result_of::ListType<L>::delay_result_type> r = NIL )
              const {
                 typedef typename result_of::ListType<L>::force_result_type OL;
                 if( null(l)() ) {
                     OL empty;
                     return cons( e, empty )();
                 }
                 else
                     return cons( e, r( XScanl(), op,
                            op(e,head(l)())(), tail(l)() )() )();
              }
          };

          struct XFilter {
            template <typename Sig> struct result;

                template <typename This, typename P, typename L>
                struct result<This(P,L)>
                {
                  typedef typename result_of::ListType<L>::delay_result_type
                          type;
                };

                template <class P, class L>
                typename result<XFilter(P,L)>::type
                operator()( const P& p, const L& ll) const
                {
                     typename  result_of::ListType<L>::delay_result_type
                     l = delay(ll);
                     typedef typename result_of::ListType<L>::
                           delay_result_type result_type;
                     typedef boost::function0<result_type> Fun2_R_P_L;
                     typedef boost::phoenix::function<Fun2_R_P_L> FilterH_R_P_L;
                     Fun2_R_P_L fun2_R_P_L = FilterH<P,L>(p,l);
                     FilterH_R_P_L filterh_R_P_L(fun2_R_P_L);
                     return filterh_R_P_L();
                }
          };

         template <class F,class T>
         struct IterateH
          {
              F f;
              T t;
              IterateH( const F& ff, const T& tt) : f(ff), t(tt) {}
              template <typename Sig> struct result;

              template <typename This,class FF,class TT>
              struct result<This(FF,TT)>
              {
                typedef typename remove_RC<TT>::type TTT;
                typedef typename UseList::template List<TTT>::type LType;
                typedef typename result_of::ListType<LType>::
                        delay_result_type type;
              };

                typename result<IterateH(F,T)>::type operator()() const {
                typedef typename UseList::template List<T>::type LType;
                typedef typename result_of::ListType<LType>::
                        delay_result_type result_type;
                typedef boost::function0<result_type> Fun2_R_F_T;
                typedef boost::phoenix::function<Fun2_R_F_T> IterateH_R_F_T;
                Fun2_R_F_T fun2_R_F_T = IterateH<F,T>(f,f(t)());
                IterateH_R_F_T iterateh_R_F_T(fun2_R_F_T);
                   return cons( t, iterateh_R_F_T() );
              }
          };


          struct XIterate {
   // Note: this does always return an odd_list; iterate() takes no ListLike
   // parameter, and it requires that its result be lazy.
              template <typename Sig> struct result;

              template <typename This, typename F, typename T>
              struct result<This(F,T)>
              {
                typedef typename boost::remove_reference<T>::type TT;
                typedef typename boost::remove_const<TT>::type TTT;
                typedef typename UseList::template List<TTT>::type LType;
                typedef typename result_of::ListType<LType>::
                        delay_result_type type;
              };

              template <class F, class T>
                typename result<XIterate(F,T)>::type operator()
                (const F& f, const T& t) const {
                typedef typename UseList::template List<T>::type LType;
                typedef typename result_of::ListType<LType>::
                        delay_result_type result_type;
                typedef boost::function0<result_type> Fun2_R_F_T;
                typedef boost::phoenix::function<Fun2_R_F_T> IterateH_R_F_T;
                Fun2_R_F_T fun2_R_F_T = IterateH<F,T>(f,f(t)());
                IterateH_R_F_T iterateh_R_F_T(fun2_R_F_T);
                   return iterateh_R_F_T();
              }
          };

    }

    typedef impl::XCompose  Compose;  // This does not need to be wrapped.
    typedef boost::phoenix::function<impl::XUntil>  Until;
    typedef boost::phoenix::function<impl::XUntil2> Until2;
    typedef boost::phoenix::function<impl::XLast>   Last;
    typedef boost::phoenix::function<impl::XInit>   Init;
    typedef boost::phoenix::function<impl::XLength> Length;
    typedef boost::phoenix::function<impl::XAt>     At;
    typedef boost::phoenix::function<impl::XFilter> Filter;
    typedef boost::phoenix::function<impl::XFoldr>  Foldr;
    typedef boost::phoenix::function<impl::XFoldl>  Foldl;
    typedef boost::phoenix::function<impl::XScanr>  Scanr;
    typedef boost::phoenix::function<impl::XScanl>  Scanl;
    typedef boost::phoenix::function<impl::XIterate> Iterate;
    Compose  compose;
    Until until;
    Until2 until2;
    Last  last;
    Init  all_but_last;  // renamed from init which is not available.
    Length length;
    At at_; // renamed from at because of name clash.
    Filter filter;
    Foldr   foldr, fold_right;
    Foldl   foldl, fold_left;
    Scanr   scanr, scan_right;
    Scanl   scanl, scan_left;
    Iterate iterate;

    namespace impl {
          // These use earlier items so come here.
         struct XFoldr1 {
              template <typename Sig> struct result;

              template <typename This, typename Op, typename L>
              struct result<This(Op,L)>
              {
                  typedef typename result_of::ListType<L>::value_type type;
              };

              template <class Op, class L>
              typename result<XFoldr1(Op,L)>::type
              operator()( const Op& op, const L& l ) const
              {
                  return foldr( op, head(l)(), tail(l)() )();
              }
          };

          struct XFoldl1 {
              template <typename Sig> struct result;

              template <typename This, typename Op, typename L>
              struct result<This(Op,L)>
              {
                  typedef typename result_of::ListType<L>::value_type type;
              };

              template <class Op, class L>
              typename result<XFoldl1(Op,L)>::type
              operator()( const Op& op, const L& l ) const
              {
                  return foldl( op, head(l)(), tail(l)() )();
              }
          };

          struct XScanr1 {
              template <typename Sig> struct result;

              template <typename This, typename Op, typename L>
              struct result<This(Op,L)>
              {
                  typedef typename result_of::ListType<L>::force_result_type
                                   type;
              };

             template <class Op, class L>
             typename result<XScanr1(Op,L)>::type
             operator()( const Op& op, const L& l ) const {
                 if( null( tail(l)() )() )
                     return l.force();
                 else {
                     typename result<XScanr1(Op,L)>::type temp = XScanr1()
                              ( op, tail(l)() );
                     return cons( op( head(l)(), head(temp)() )(), temp )();
                }
             }
          };

          struct XScanl1 {
              template <typename Sig> struct result;

              template <typename This, typename Op, typename L>
              struct result<This(Op,L)>
              {
                  typedef typename result_of::ListType<L>::force_result_type
                                   type;
              };

              template <class Op, class L>
              typename result<XScanl1(Op,L)>::type
              operator()( const Op& op, const L& l ) const {
                  return scanl( op, head(l)(), tail(l)() )();
              }
          };

          struct XRepeat {
         // See note for iterate()
              template <typename Sig> struct result;

              template <typename This, typename T>
              struct result<This(T)>
              {
                typedef typename boost::remove_reference<T>::type TT;
                typedef typename boost::remove_const<TT>::type TTT;
                typedef typename UseList::template List<TTT>::type LType;
                typedef typename result_of::ListType<LType>::
                        delay_result_type type;
              };

              template <class T>
              typename result<XRepeat(T)>::type operator()( const T& x) const
              {
                return iterate(id,x);
              }
          };


      template <class F,class L>
      struct MapH
      {
            F f;
            L l;
            MapH( const F& ff, const L& ll) : f(ff), l(ll) {}
            template <typename Sig> struct result;

	template <typename This, typename FF, typename LL>
            struct result<This(FF,LL)>
            {
                typedef typename RTFL<FF,LL>::type type;
            };

            typename result<MapH(F,L)>::type operator()() const {
                  typedef typename RTFL<F,L>::type result_type;
                  typedef boost::function0<result_type> Fun2_R_F_L;
                  typedef boost::phoenix::function<Fun2_R_F_L> MapH_R_F_L;
                  if (null(l)() )
                     return NIL;
                  Fun2_R_F_L fun2_R_F_L = MapH<F,L>(f,tail(l));
                  MapH_R_F_L maph_R_F_L(fun2_R_F_L);
                  if( null(l)() )
                      return NIL;
                  else
                      return cons( f(head(l))(), maph_R_F_L() );
             }
      };

      struct XMap {
           template <typename Sig> struct result;

           template <typename This, typename F, typename L>
           struct result<This(F,L)>
           {
               typedef typename RTFL<F,L>::type type;
           };
               template <class F, class L>
                typename result<XMap(F,L)>::type
                operator()( const F& f, const L& ll) const
                {
                    typedef typename RTFL<F,L>::type result_type;
                    typename  result_of::ListType<L>::delay_result_type
                        l = delay(ll);
                    typedef boost::function0<result_type> Fun2_R_F_L;
                    typedef boost::phoenix::function<Fun2_R_F_L> MapH_R_F_L;
                    Fun2_R_F_L fun2_R_F_L = MapH<F,L>(f,l);
                    MapH_R_F_L maph_R_F_L(fun2_R_F_L);
                    return maph_R_F_L();
                }
          };

          struct XZipWith {
              template <typename Sig> struct result;

              template <typename This, typename Z, typename LA, typename LB>
              struct result<This(Z,LA,LB)>
              {
                  typedef typename RTZAB<Z,LA,LB>::type type;
              };

              template <class Z, class LA, class LB>
              typename result<XZipWith(Z,LA,LB)>::type
              operator()( const Z& z, const LA& a, const LB& b,
               reuser3<INV,INV,VAR,VAR,XZipWith,Z,
                  typename result_of::ListType<LA>::tail_result_type,
                  typename result_of::ListType<LB>::tail_result_type >
                  r = NIL ) const
              {
                  if( null(a)() || null(b)() )
                       return NIL;
                   else
                       return cons( z(head(a)(),head(b)()),
                       r( XZipWith(), z, tail(a)(), tail(b)() )() )();
              }
          };

          struct XTake {

             template <typename Sig> struct result;

             template <typename This, typename N, typename L>
             struct result<This(N,L)>
             {
               typedef typename result_of::ListType<L>::force_result_type type;
             };

             template <class N,class L>
             typename result<XTake(N,L)>::type
             operator()( N n, const L& l,
               reuser2<INV,VAR,VAR,XTake,N,
               typename result_of::ListType<L>::force_result_type>
               r = NIL
             ) const {
               if( n <= 0 || null(l)() )
                 return NIL;
               else {
                 return cons( head(l)(), r( XTake(), n-1, tail(l)() )() )();
               }
             }
          };

          struct XDrop {
             template <typename Sig> struct result;

             template <typename This, typename Dummy, typename L>
             struct result<This(Dummy,L)>
             {
               typedef typename result_of::ListType<L>::delay_result_type type;
             };
   
             template <class L>
             typename result<XDrop(size_t,L)>::type
             operator()( size_t n, const L& ll ) const {
               typename L::delay_result_type l = delay(ll);
               while( n!=0 && !null(l)() ) {
                 --n;
                 l = tail(l)();
               }
               return l;
             }
          };
 
          template <class T>
          struct EFH
          {
              mutable T x;
              EFH( const T& xx) : x(xx) {}
              template <typename Sig> struct result;

              template <typename This, class TT>
              struct result<This(TT)>
              {
                typedef typename boost::phoenix::UseList::template
                        List<TT>::type LType;
                typedef typename boost::phoenix::result_of::
                        ListType<LType>::delay_result_type type;
              };
              typename result<EFH(T)>::type operator()() const {
                typedef typename UseList::template List<T>::type LType;
                typedef typename result_of::ListType<LType>::
                        delay_result_type result_type;
                typedef boost::function0<result_type> fun1_R_TTT;
                //std::cout << "EFH (" << x << ")" << std::endl;
                ++x;
                fun1_R_TTT efh_R_TTT = EFH<T>(x);
                typedef boost::phoenix::function<fun1_R_TTT> EFH_R_T;
                EFH_R_T efh_R_T(efh_R_TTT);
#ifndef BOOST_PHOENIX_NO_LAZY_EXCEPTIONS
                if (x > BOOST_PHOENIX_FUNCTION_MAX_LAZY_LIST_LENGTH)
                     throw lazy_exception("Running away in EFH!!");
#endif
                return cons( x-1, efh_R_T() );
              }
          };

          struct XEnum_from {
             template <typename Sig> struct result;

             template <typename This, typename T>
             struct result<This(T)>
             {
               typedef typename remove_RC<T>::type TTT;
               typedef typename UseList::template List<TTT>::type LType;
               typedef typename result_of::ListType<LType>::
                       delay_result_type type;
             };

             template <class T>
             typename result<XEnum_from(T)>::type operator()
                (const T & x) const
              {
                typedef typename remove_RC<T>::type TTT;
                typedef typename UseList::template List<T>::type LType;
                typedef typename result_of::ListType<LType>::
                        delay_result_type result_type;
                typedef boost::function0<result_type> fun1_R_TTT;
                fun1_R_TTT efh_R_TTT = EFH<TTT>(x);
                typedef boost::phoenix::function<fun1_R_TTT> EFH_R_T;
                EFH_R_T efh_R_T(efh_R_TTT);
                return efh_R_T();
              }
          };

       template <class T>
         struct EFTH
          {
              mutable T x;
              T y;
              EFTH( const T& xx, const T& yy) : x(xx), y(yy) {}
              template <typename Sig> struct result;

              template <typename This, class TT>
              struct result<This(TT)>
              {
                typedef typename boost::phoenix::UseList::template
                        List<TT>::type LType;
                typedef typename boost::phoenix::result_of::
                        ListType<LType>::delay_result_type type;
              };
              typename result<EFTH(T)>::type operator()() const {
                typedef typename UseList::template List<T>::type LType;
                typedef typename result_of::ListType<LType>::
                        delay_result_type result_type;
                typedef boost::function0<result_type> fun1_R_TTT;
                if (x > y ) return NIL;
                ++x;
                fun1_R_TTT efth_R_TTT = EFTH<T>(x,y);
                typedef boost::phoenix::function<fun1_R_TTT> EFTH_R_T;
                EFTH_R_T efth_R_T(efth_R_TTT);
#ifndef BOOST_PHOENIX_NO_LAZY_EXCEPTIONS
                if (x > BOOST_PHOENIX_FUNCTION_MAX_LAZY_LIST_LENGTH)
                     throw lazy_exception("Running away in EFTH!!");
#endif
                return cons( x-1, efth_R_T() );
              }
          };

          struct XEnum_from_to {
             template <typename Sig> struct result;

             template <typename This, typename T>
             struct result<This(T,T)>
             {
               typedef typename remove_RC<T>::type TTT;
               typedef typename UseList::template List<TTT>::type LType;
               typedef typename result_of::ListType<LType>::
                       delay_result_type type;
             };

             template <class T>
             typename result<XEnum_from(T,T)>::type operator()
             (const T & x, const T & y) const
              {
                typedef typename remove_RC<T>::type TTT;
                typedef typename UseList::template List<T>::type LType;
                typedef typename result_of::ListType<LType>::
                        delay_result_type result_type;
                typedef boost::function0<result_type> fun1_R_TTT;
                fun1_R_TTT efth_R_TTT = EFTH<TTT>(x,y);
                typedef boost::phoenix::function<fun1_R_TTT> EFTH_R_T;
                EFTH_R_T efth_R_T(efth_R_TTT);
                //std::cout << "enum_from (" << x << ")" << std::endl;
                return efth_R_T();
              }
          };

    }


    //BOOST_PHOENIX_ADAPT_CALLABLE(apply, impl::apply, 3)
    // Functors to be used in reuser will have to be defined
    // using boost::phoenix::function directly
    // in order to be able to be used as arguments.
    typedef boost::phoenix::function<impl::XFoldr1> Foldr1;
    typedef boost::phoenix::function<impl::XFoldl1> Foldl1;
    typedef boost::phoenix::function<impl::XScanr1> Scanr1;
    typedef boost::phoenix::function<impl::XScanl1> Scanl1;
    typedef boost::phoenix::function<impl::XRepeat> Repeat;
    typedef boost::phoenix::function<impl::XMap>    Map;
    typedef boost::phoenix::function<impl::XZipWith> ZipWith;
    typedef boost::phoenix::function<impl::XTake>   Take;
    typedef boost::phoenix::function<impl::XDrop>   Drop;
    typedef boost::phoenix::function<impl::XEnum_from>     Enum_from;
    typedef boost::phoenix::function<impl::XEnum_from_to>  Enum_from_to;
    Foldr1 foldr1;
    Foldl1 foldl1;
    Scanr1 scanr1;
    Scanl1 scanl1;
    Repeat repeat;
    Map   map;
    ZipWith zip_with;
    Take  take;
    Drop  drop;
    Enum_from enum_from;
    Enum_from_to enum_from_to;
    namespace impl {

          struct XZip {
               template <typename Sig> struct result;

               template <typename This, typename LA, typename LB>
               struct result<This(LA,LB)>
               {
                  typedef typename RTAB<LA,LB>::type type;
               };

               template <class LA, class LB>
               typename result<XZip(LA,LB)>::type
               operator()( const LA& a, const LB& b ) const {
                   return zip_with(make_pair, a, b )();
               }
          };

    }
    typedef boost::phoenix::function<impl::XZip> Zip;
    Zip zip;

    ///////////////////////////////////////////////////////////////////
    // These operators must come after definition of zip_with
    ///////////////////////////////////////////////////////////////////
    template <class T>
    list<T> operator+(const list<T>& x, const list<T>& y)
    {
      return zip_with(plus,x,y);
    }

    template <class T>
    list<T> operator-(const list<T>& x, const list<T>& y)
    {
      return zip_with(minus,x,y);
    }

    namespace fcpp {


    }

  }

}


#endif
