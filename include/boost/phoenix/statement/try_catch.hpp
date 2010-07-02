/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_STATEMENT_TRY_CATCH_HPP
#define PHOENIX_STATEMENT_TRY_CATCH_HPP

#include <boost/phoenix/support/element_at.hpp>
#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Env, PHOENIX_typename_A_void(PHOENIX_CATCH_LIMIT)>
        struct try_catch
        {
            typedef void type;
        };
    }

    template <PHOENIX_typename_A_void(PHOENIX_CATCH_LIMIT), typename Dummy = void>
    struct try_catch_eval;

    template<>
    struct try_catch_eval<>
    {
        typedef void result_type;

        template <typename Env, typename Try, typename CatchAll>
        result_type
        operator()(Env& env, Try const& try_block, CatchAll const& catch_all) const
        {
            try
            {
                eval(try_block, env);
            }
            catch(...)
            {
                eval(catch_all, env);
            }
        }
    };

#define CATCH_EXCEPTION(_, n, __) \
    BOOST_PP_COMMA_IF(n) typename CatchBlock ## n = void, typename Exception ## n = void
    template <
        typename Try
      , BOOST_PP_REPEAT(PHOENIX_CATCH_LIMIT, CATCH_EXCEPTION, _)
      , typename Dummy = void>
    struct make_try_catch;

    template <
        typename Exception
      , typename Try
      , BOOST_PP_REPEAT(BOOST_PP_DEC(PHOENIX_CATCH_LIMIT), CATCH_EXCEPTION, _)
      , typename Dummy = void>
    struct catch_gen;
#undef CATCH_EXCEPTION

    template<typename Expr>
    struct try_catch_actor0;

    template <typename Try>
    struct make_try_catch<Try> : compose_ex<try_catch_eval<>, try_catch_actor0, Try> {};

    template <typename Try, typename CatchAll>
    struct make_try_catch<Try, CatchAll> : compose<try_catch_eval<>, Try, CatchAll> {};

    template <typename Exception, typename Try>
    struct catch_gen<Exception, Try>
    {
        catch_gen(Try const& try_block) : try_block(try_block) {}

        template <typename CatchBlock>
        typename make_try_catch<Try, CatchBlock, Exception>::type const
        operator[](CatchBlock const& catch_block) const
        {
            return make_try_catch<Try, CatchBlock, Exception>()(try_block, catch_block);
        };

        Try const& try_block;
    };

    template <typename Try>
    struct catch_all_gen
    {
        catch_all_gen(Try const& try_block) : try_block(try_block) {}

        template <typename CatchAll>
        typename make_try_catch<Try, CatchAll>::type const
        operator[](CatchAll const& catch_all) const
        {
            return make_try_catch<Try, CatchAll>()(try_block, catch_all);
        }
        
        Try const& try_block;
    };

#define PHOENIX_ITERATION_PARAMS                                                \
        (3, (1, PHOENIX_CATCH_LIMIT,                                            \
        <boost/phoenix/statement/try_catch.hpp>))
#include PHOENIX_ITERATE()

    template <typename Expr>
    struct try_catch_actor0
        : actor<Expr>
    {
        typedef actor<Expr> base_type;

        try_catch_actor0(base_type const& base)
            : base_type(base)
            , catch_all(element_at_c<0>(*this))
        {}
        
        typedef typename result_of::element_value_at_c<Expr, 0>::type try_type;

        template <typename Exception>
        catch_gen<Exception, try_type> const
        catch_() const
        {
            return catch_gen<Exception, try_type>(element_at_c<0>(*this));
        }

        const catch_all_gen<try_type> catch_all;
    };

    template <typename Expr>
    struct BOOST_PP_CAT(try_catch_actor, BOOST_PP_INC(PHOENIX_CATCH_LIMIT))
    {
        typedef actor<Expr> base_type;

        BOOST_PP_CAT(try_catch_actor, BOOST_PP_INC(PHOENIX_CATCH_LIMIT))(base_type const& base)
            : base_type(base)
            , catch_all(element_at_c<0>(*this))
        {}
        
        typedef typename result_of::element_value_at_c<Expr, 0>::type try_type;

        const catch_all_gen<try_type> catch_all;
    };

    struct try_gen
    {
        template <typename Try>
        typename make_try_catch<Try>::type const
        operator[](Try const& try_block) const
        {
            return make_try_catch<Try>()(try_block);
        }
    };

    try_gen const try_ = try_gen();

}}

#endif

#else

#define PHOENIX_typename_Exception BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, typename Exception)
#define PHOENIX_Exception BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, Exception)
#define PHOENIX_Exception_ref BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, Exception, & BOOST_PP_INTERCEPT)

    template <typename Exception, typename Try, PHOENIX_typename_A>
    struct catch_gen<Exception, Try, PHOENIX_A>
    {
#define INIT_a(_,n,__) BOOST_PP_COMMA_IF(n) BOOST_PP_CAT(a,n)(BOOST_PP_CAT(a,n))
        catch_gen(Try const& try_block, PHOENIX_A_const_ref_a)
            : try_block(try_block)
            , BOOST_PP_REPEAT(PHOENIX_ITERATION, INIT_a, _)
        {}

        template <typename CatchBlock>
        typename make_try_catch<Try, PHOENIX_A, CatchBlock, Exception>::type const
        operator[](CatchBlock const& catch_block) const
        {
            return make_try_catch<Try, PHOENIX_A, CatchBlock, Exception>()(try_block, PHOENIX_a, catch_block);
        };

        Try const& try_block;
#define CATCH_BLOCK(_, n, __) A ## n const& a ## n;
        BOOST_PP_REPEAT(PHOENIX_ITERATION, CATCH_BLOCK, _)
#undef CATCH_BLOCK
    };

    template <PHOENIX_typename_Exception>
    struct try_catch_eval<PHOENIX_Exception>
    {
        typedef void result_type;

        template <typename Env, typename Try, PHOENIX_typename_A>
        result_type
        operator()(Env& env, Try const& try_, PHOENIX_A_const_ref_a) const
        {
            try
            {
                eval(try_, env);
            }
#define CATCH(_, n, __) \
            catch(Exception ## n &) \
            { \
                eval(a ## n, env); \
            }
            BOOST_PP_REPEAT(PHOENIX_ITERATION, CATCH, _)
#undef CATCH
        }
    };

    template <typename Expr> struct BOOST_PP_CAT(try_catch_actor, PHOENIX_ITERATION);

#define CATCH_EXCEPTION_typename(_, n, __) \
    BOOST_PP_COMMA_IF(n) typename CatchBlock ## n, typename Exception ## n

#define CATCH_EXCEPTION(_, n, __) \
    BOOST_PP_COMMA_IF(n) CatchBlock ## n, Exception ## n

    template <typename Try, BOOST_PP_REPEAT(PHOENIX_ITERATION, CATCH_EXCEPTION_typename, _)>
    struct make_try_catch<Try, BOOST_PP_REPEAT(PHOENIX_ITERATION, CATCH_EXCEPTION, _)>
        : compose_ex<
            try_catch_eval<BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, Exception)>
          , BOOST_PP_CAT(try_catch_actor, PHOENIX_ITERATION)
          , Try
          , BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, CatchBlock)
          > {};

    template <typename Expr>
    struct BOOST_PP_CAT(try_catch_actor, PHOENIX_ITERATION)
        : actor<Expr>
    {
        typedef actor<Expr> base_type;

        BOOST_PP_CAT(try_catch_actor, PHOENIX_ITERATION)(base_type const& base)
            : base_type(base)
            , catch_all(element_at_c<0>(*this))
        {}
        
        typedef typename result_of::element_value_at_c<Expr, 0>::type try_type;
#define CATCH_BLOCK_TYPES(_, n, __) \
        typedef typename result_of::element_value_at_c<Expr, n>::type catch_block_type ## n;
        BOOST_PP_REPEAT_FROM_TO(1, PHOENIX_ITERATION, CATCH_BLOCK_TYPES, _)
#undef CATCH_BLOCK_TYPES

        template <typename Exception>
        catch_gen<Exception, try_type> const
        catch_() const
        {
            return catch_gen<Exception, try_type>(element_at_c<0>(*this));
        }

        const catch_all_gen<try_type> catch_all;
    };

#undef PHOENIX_typename_Exception
#undef PHOENIX_Exception
#undef PHOENIX_Exception_ref

#endif
