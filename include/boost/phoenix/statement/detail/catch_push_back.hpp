
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_STATEMENT_DETAIL_CATCH_PUSH_BACK_HPP
#define PHOENIX_STATEMENT_DETAIL_CATCH_PUSH_BACK_HPP

#include <boost/phoenix/support/iterate.hpp>

#include <boost/phoenix/statement/detail/preprocessed/catch_push_back.hpp>

#endif
#else

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_STATEMENT_DETAIL_CATCH_PUSH_BACK_HPP
#define PHOENIX_STATEMENT_DETAIL_CATCH_PUSH_BACK_HPP

#include <boost/phoenix/support/iterate.hpp>

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/catch_push_back_" PHOENIX_LIMIT_STR ".hpp")
#endif

/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

    #define PHOENIX_CATCH_PUSH_BACK_R0(Z, N, DATA)                              \
        BOOST_PP_COMMA_IF(N)                                                    \
        typename proto::result_of::child_c<TryCatch, N>::type                   \
    /**/

    #define PHOENIX_CATCH_PUSH_BACK_R1(Z, N, DATA)                              \
        BOOST_PP_COMMA_IF(N) proto::child_c<N>(try_catch)                       \
    /**/

#define PHOENIX_ITERATION_PARAMS                                                \
        (3, (2, PHOENIX_CATCH_LIMIT,                                            \
        <boost/phoenix/statement/detail/catch_push_back.hpp>))
#include PHOENIX_ITERATE()
    
    #undef PHOENIX_CATCH_PUSH_BACK_R0
    #undef PHOENIX_CATCH_PUSH_BACK_R1

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else
        template <typename TryCatch, typename Exception, typename Expr>
        struct catch_push_back<TryCatch, Exception, Expr, PHOENIX_ITERATION>
        {
            typedef
                typename proto::result_of::make_expr<
                    tag::catch_
                  , default_domain_with_basic_expr
                  , catch_exception<Exception>
                  , Expr
                >::type
                catch_expr;

            typedef expression::try_catch<
                BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_CATCH_PUSH_BACK_R0, _)
              , catch_expr> gen_type;
            typedef typename gen_type::type type;

            static type
            make(
                TryCatch const& try_catch
              , Expr const& catch_
            )
            {
                return
                    gen_type::make(
                        BOOST_PP_REPEAT(
                            PHOENIX_ITERATION
                          , PHOENIX_CATCH_PUSH_BACK_R1
                          , _
                        )
                      , proto::make_expr<
                            tag::catch_
                          , default_domain_with_basic_expr
                        >(catch_exception<Exception>(), catch_)
                    );
            }
        };
        
        template <typename TryCatch, typename Expr>
        struct catch_all_push_back<TryCatch, Expr, PHOENIX_ITERATION>
        {
            typedef
                typename proto::result_of::make_expr<
                    tag::catch_all
                  , default_domain_with_basic_expr
                  , Expr
                >::type
                catch_expr;

            typedef expression::try_catch<
                BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_CATCH_PUSH_BACK_R0, _)
              , catch_expr> gen_type;
            typedef typename gen_type::type type;

            static type
            make(
                TryCatch const& try_catch
              , Expr const& catch_
            )
            {
                return
                    gen_type::make(
                        BOOST_PP_REPEAT(
                            PHOENIX_ITERATION
                          , PHOENIX_CATCH_PUSH_BACK_R1
                          , _
                        )
                      , proto::make_expr<
                            tag::catch_all
                          , default_domain_with_basic_expr
                        >(catch_)
                    );
            }
        };

#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
