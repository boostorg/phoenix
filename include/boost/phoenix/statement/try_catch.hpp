/*==============================================================================
    Copyright (c) 2005-2007 Dan Marsden
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef PHOENIX_STATEMENT_TRY_CATCH_HPP
#define PHOENIX_STATEMENT_TRY_CATCH_HPP

#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/unpack.hpp>
#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
    template <typename Expr>
    struct try_catch_actor;

    template <typename Exception>
    struct catch_exception
    {
        typedef Exception type;
    };

    namespace tag
    {
        struct try_catch {};
        struct catch_ {};
        struct catch_all {};
    }

    namespace expression
    {
        template <
            typename Try
          , PHOENIX_typename_A_void(PHOENIX_CATCH_LIMIT)
          , typename Dummy = void
        >
        struct try_catch;

    #define PHOENIX_TRY_CATCH_EXPRESSION(Z, N, DATA)                        \
        template <typename Try BOOST_PP_COMMA_IF(N) PHOENIX_typename_A(N)>      \
        struct try_catch<Try BOOST_PP_COMMA_IF(N) PHOENIX_A(N)>                 \
            : expr_ext<                                                         \
                try_catch_actor                                                 \
              , tag::try_catch                                                  \
              , Try                                                             \
              BOOST_PP_COMMA_IF(N) PHOENIX_A(N)>                                \
        {};                                                                     \
        /**/

        BOOST_PP_REPEAT(PHOENIX_CATCH_LIMIT, PHOENIX_TRY_CATCH_EXPRESSION, _)
        #undef PHOENIX_TRY_CATCH_EXPRESSION

        template <typename A0, typename A1>
        struct catch_
            : proto::binary_expr<tag::catch_, A0, A1>
        {};
        
        template <typename A0>
        struct catch_all
            : proto::unary_expr<tag::catch_all, A0>
        {};
    }

    namespace rule
    {
        struct catch_
            : expression::catch_<
                proto::terminal<catch_exception<proto::_> >
              , meta_grammar
            >
        {};
        
        struct catch_all
            : expression::catch_all<
                meta_grammar
            >
        {};

        struct try_catch
            : proto::or_<
                expression::try_catch<
                     meta_grammar
                   , proto::vararg<rule::catch_>
                >
              , expression::try_catch<
                     meta_grammar
                   , rule::catch_all
                >
              , expression::try_catch<
                     meta_grammar
                   , proto::vararg<rule::catch_>
                   , rule::catch_all
                >
            >
        {};
    }

    template <typename Dummy>
    struct meta_grammar::case_<tag::try_catch, Dummy>
        : proto::when<rule::try_catch, proto::external_transform>
    {};

    struct try_catch_eval
    {
        typedef void result_type;

    #define PHOENIX_TRY_CATCH_EVAL_R(Z, N, DATA)                                \
            catch(                                                              \
                typename proto::result_of::value<                               \
                    typename proto::result_of::child_c<                         \
                        BOOST_PP_CAT(A, N)                                      \
                      , 0                                                       \
                    >::type                                                     \
                >::type::type &                                                 \
            )                                                                   \
            {                                                                   \
                eval(proto::child_c<1>(BOOST_PP_CAT(a, N)), env);               \
            }                                                                   \
        /**/

    #define PHOENIX_TRY_CATCH_EVAL(Z, N, DATA)                                  \
        template <typename Env, typename Try, PHOENIX_typename_A(N)>            \
        typename boost::enable_if<                                              \
            proto::matches<BOOST_PP_CAT(A, BOOST_PP_DEC(N)), rule::catch_>      \
          , result_type                                                         \
        >::type                                                                 \
        operator()(Env & env, Try const & try_, PHOENIX_A_const_ref_a(N)) const \
        {                                                                       \
            try                                                                 \
            {                                                                   \
                eval(proto::child_c<0>(try_), env);                             \
            }                                                                   \
            BOOST_PP_REPEAT(N, PHOENIX_TRY_CATCH_EVAL_R, _)                     \
        }                                                                       \
                                                                                \
        template <typename Env, typename Try, PHOENIX_typename_A(N)>            \
        typename boost::disable_if<                                             \
            proto::matches<BOOST_PP_CAT(A, BOOST_PP_DEC(N)), rule::catch_>      \
          , result_type                                                         \
        >::type                                                                 \
        operator()(Env & env, Try const & try_, PHOENIX_A_const_ref_a(N)) const \
        {                                                                       \
            try                                                                 \
            {                                                                   \
                eval(proto::child_c<0>(try_), env);                             \
            }                                                                   \
            BOOST_PP_REPEAT(BOOST_PP_DEC(N), PHOENIX_TRY_CATCH_EVAL_R, _)       \
            catch(...)                                                          \
            {                                                                   \
                eval(proto::child_c<0>(BOOST_PP_CAT(a, BOOST_PP_DEC(N))), env); \
            }                                                                   \
        }                                                                       \
        /**/

        BOOST_PP_REPEAT_FROM_TO(
            1
          , PHOENIX_CATCH_LIMIT
          , PHOENIX_TRY_CATCH_EVAL
          , _
        )
        #undef PHOENIX_TRY_CATCH_EVAL
        #undef PHOENIX_TRY_CATCH_EVAL_R
    };

    template <typename Dummy>
    struct default_actions::when<rule::try_catch, Dummy>
        : proto::call<try_catch_eval(_env, unpack(proto::_))>
    {};

    namespace detail
    {
        struct try_catch_is_nullary
            : proto::or_<
                proto::when<
                    rule::catch_all
                  , evaluator(proto::_child_c<0>, proto::_data)
                >
              , proto::when<
                    rule::catch_
                  , evaluator(proto::_child_c<1>, proto::_data)
                >
              , proto::when<
                    rule::try_catch
                  , mpl::and_<
                        evaluator(proto::_child_c<0>, proto::_data)
                      , proto::fold<
                            proto::functional::pop_front(proto::_)
                          , mpl::true_()
                          , mpl::and_<
                                proto::_state
                              , try_catch_is_nullary(
                                    proto::_
                                  , int()
                                  , proto::_data
                                )
                            >()
                        >
                    >()
                >
            >
        {};

        template <typename Dummy>
        struct is_nullary_::when<rule::try_catch, Dummy>
            : proto::call<try_catch_is_nullary(proto::_, int(), _env)>
        {};

        template <
            typename TryCatch
          , typename Exception
          , typename Expr
          , long Arity = proto::arity_of<TryCatch>::value
        >
        struct catch_push_back;

        template <typename TryCatch, typename Exception, typename Expr>
        struct catch_push_back<TryCatch, Exception, Expr, 1>
        {
            typedef
                typename proto::result_of::make_expr<
                    tag::catch_
                  , default_domain_with_basic_expr
                  , catch_exception<Exception>
                  , Expr
                >::type
                catch_expr;
            
            typedef
                expression::try_catch<
                    TryCatch
                  , catch_expr
                >
                gen_type;
            typedef typename gen_type::type type;

            static type make(TryCatch const & try_catch, Expr const & catch_)
            {
                return
                    gen_type::make(
                        try_catch
                      , proto::make_expr<
                            tag::catch_
                          , default_domain_with_basic_expr
                        >(catch_exception<Exception>(), catch_)
                    );
            }
        };

    #define PHOENIX_CATCH_PUSH_BACK_R0(Z, N, DATA)                              \
        BOOST_PP_COMMA_IF(N)                                                    \
        typename proto::result_of::child_c<TryCatch, N>::type                   \
        /**/

    #define PHOENIX_CATCH_PUSH_BACK_R1(Z, N, DATA)                              \
        BOOST_PP_COMMA_IF(N) proto::child_c<N>(try_catch)                       \
        /**/

    #define PHOENIX_CATCH_PUSH_BACK(Z, N, DATA)                                 \
        template <typename TryCatch, typename Exception, typename Expr>         \
        struct catch_push_back<TryCatch, Exception, Expr, N>                    \
        {                                                                       \
            typedef                                                             \
                typename proto::result_of::make_expr<                           \
                    tag::catch_                                                 \
                  , default_domain_with_basic_expr                              \
                  , catch_exception<Exception>                                  \
                  , Expr                                                        \
                >::type                                                         \
                catch_expr;                                                     \
                                                                                \
            typedef expression::try_catch<                                      \
                BOOST_PP_REPEAT(N, PHOENIX_CATCH_PUSH_BACK_R0, _)               \
              , catch_expr> gen_type;                                           \
            typedef typename gen_type::type type;                               \
                                                                                \
            static type                                                         \
            make(                                                               \
                TryCatch const& try_catch                                       \
              , Expr const& catch_                                              \
            )                                                                   \
            {                                                                   \
                return                                                          \
                    gen_type::make(                                             \
                        BOOST_PP_REPEAT(N, PHOENIX_CATCH_PUSH_BACK_R1, _)       \
                      , proto::make_expr<                                       \
                            tag::catch_                                         \
                          , default_domain_with_basic_expr                      \
                        >(catch_exception<Exception>(), catch_)                 \
                    );                                                          \
            }                                                                   \
        };                                                                      \
        /**/

        BOOST_PP_REPEAT_FROM_TO(
            2
          , PHOENIX_CATCH_LIMIT
          , PHOENIX_CATCH_PUSH_BACK
          , _
        )
        #undef PHOENIX_CATCH_PUSH_BACK
        
        template <
            typename TryCatch
          , typename Expr
          , long Arity = proto::arity_of<TryCatch>::value
        >
        struct catch_all_push_back;

        template <typename TryCatch, typename Expr>
        struct catch_all_push_back<TryCatch, Expr, 1>
        {
            typedef
                typename proto::result_of::make_expr<
                    tag::catch_all
                  , default_domain_with_basic_expr
                  , Expr
                >::type
                catch_expr;
            
            typedef
                expression::try_catch<
                    TryCatch
                  , catch_expr
                >
                gen_type;
            typedef typename gen_type::type type;

            static type make(TryCatch const& try_catch, Expr const& catch_)
            {
                return
                    gen_type::make(
                        try_catch
                      , proto::make_expr<
                            tag::catch_all
                          , default_domain_with_basic_expr
                        >(catch_)
                    );
            }
        };

    #define PHOENIX_CATCH_ALL_PUSH_BACK(Z, N, DATA)                             \
        template <typename TryCatch, typename Expr>                             \
        struct catch_all_push_back<TryCatch, Expr, N>                           \
        {                                                                       \
            typedef                                                             \
                typename proto::result_of::make_expr<                           \
                    tag::catch_all                                              \
                  , default_domain_with_basic_expr                              \
                  , Expr                                                        \
                >::type                                                         \
                catch_expr;                                                     \
                                                                                \
            typedef expression::try_catch<                                      \
                BOOST_PP_REPEAT(N, PHOENIX_CATCH_PUSH_BACK_R0, _)               \
              , catch_expr> gen_type;                                           \
            typedef typename gen_type::type type;                               \
                                                                                \
            static type                                                         \
            make(                                                               \
                TryCatch const& try_catch                                       \
              , Expr const& catch_                                              \
            )                                                                   \
            {                                                                   \
                return                                                          \
                    gen_type::make(                                             \
                        BOOST_PP_REPEAT(N, PHOENIX_CATCH_PUSH_BACK_R1, _)       \
                      , proto::make_expr<                                       \
                            tag::catch_all                                      \
                          , default_domain_with_basic_expr                      \
                        >(catch_)                                               \
                    );                                                          \
            }                                                                   \
        };                                                                      \
        /**/
        
        BOOST_PP_REPEAT_FROM_TO(
            2
          , PHOENIX_CATCH_LIMIT
          , PHOENIX_CATCH_ALL_PUSH_BACK
          , _
        )
        #undef PHOENIX_CATCH_ALL_PUSH_BACK
        #undef PHOENIX_CATCH_PUSH_BACK_R0
        #undef PHOENIX_CATCH_PUSH_BACK_R1
    }

    template <typename TryCatch, typename Exception>
    struct catch_gen
    {
        catch_gen(TryCatch const& try_catch) : try_catch(try_catch) {}

        template <typename Expr>
        typename boost::disable_if<
            proto::matches<
                typename proto::result_of::child_c<
                    TryCatch
                  , proto::arity_of<TryCatch>::value - 1
                >::type
              , rule::catch_all
            >
          , typename detail::catch_push_back<TryCatch, Exception, Expr>::type
        >::type
        operator[](Expr const& expr) const
        {
            return
                detail::catch_push_back<TryCatch, Exception, Expr>::make(
                    try_catch, expr
                );
        }

        TryCatch const & try_catch;
    };

    template <typename TryCatch>
    struct catch_all_gen
    {
        catch_all_gen(TryCatch const& try_catch) : try_catch(try_catch) {}

        template <typename Expr>
        typename boost::disable_if<
            proto::matches<
                typename proto::result_of::child_c<
                    TryCatch
                  , proto::arity_of<TryCatch>::value - 1
                >::type
              , rule::catch_all
            >
          , typename detail::catch_all_push_back<TryCatch, Expr>::type
        >::type
        operator[](Expr const& expr) const
        {
            return detail::catch_all_push_back<TryCatch, Expr>::make(
                try_catch, expr
            );
        }

        TryCatch const & try_catch;
    };

    template <
        typename Expr
    >
    struct try_catch_actor;

    template <typename Expr>
    struct try_catch_actor
        : actor<Expr>
    {
        typedef try_catch_actor<Expr> that_type;
        typedef actor<Expr> base_type;

        try_catch_actor(base_type const& expr)
            : base_type(expr)
            , catch_all(*this)
        {
        }

        template <typename Exception>
        catch_gen<that_type, Exception> const
        catch_() const
        {
            return catch_gen<that_type, Exception>(*this);
        }

        catch_all_gen<that_type> const catch_all;
    };

    struct try_gen
    {
        template <typename Try>
        typename expression::try_catch<Try>::type const
        operator[](Try const & try_) const
        {
            return expression::try_catch<Try>::make(try_);
        }
    };

    try_gen const try_ = {};
}}

#endif
