#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OPERATOR_MEMBER_HPP
#define PHOENIX_OPERATOR_MEMBER_HPP

#include <boost/get_pointer.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/unpack.hpp>
#include <boost/phoenix/operator/detail/mem_fun_ptr_gen.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/type_traits/is_member_function_pointer.hpp>

namespace boost { namespace phoenix
{
	PHOENIX_BINARY_OPERATORS(
		(mem_ptr)
	)

    PHOENIX_DEFINE_EXPRESSION_VARARG(mem_fun_ptr, (meta_grammar), PHOENIX_LIMIT)

	template <typename Object, typename MemPtr>
    typename enable_if<
        is_member_function_pointer<MemPtr>
      , detail::mem_fun_ptr_gen<actor<Object>, MemPtr> const
      >::type
    operator->*(actor<Object> const& obj, MemPtr ptr)
    {
        return detail::mem_fun_ptr_gen<actor<Object>, MemPtr>(obj, ptr);
    }

	struct mem_fun_ptr_eval
		: proto::callable
	{
        template<typename Sig>
        struct result;

        #define PHOENIX_MEMBER_RESULT_OF(_, N, __) \
                  typename boost::result_of<evaluator(BOOST_PP_CAT(A, N) const&, Env&)>::type
        #define PHOENIX_MEMBER_EVAL(_, N, __) \
                  eval(BOOST_PP_CAT(a, N), env)

        #define PHOENIX_ITERATION_PARAMS                                                \
            (4, (0, PHOENIX_LIMIT,                                                  \
            <boost/phoenix/operator/member.hpp>,                                    \
            PHOENIX_ITERATE_OPERATOR))
        #include PHOENIX_ITERATE()
        #undef PHOENIX_MEMBER_RESULT_OF
        #undef PHOENIX_MEMBER_EVAL
	};

    template <typename Dummy>
    struct default_actions::when<rule::mem_fun_ptr, Dummy>
        : proto::call<mem_fun_ptr_eval(_env, unpack)>
    {};
}}

#endif

#else // PHOENIX_IS_ITERATING
        
        
        template<typename This, typename Env, typename T1, typename T2 BOOST_PP_COMMA_IF(PHOENIX_ITERATION) PHOENIX_typename_A>
        struct result<
            This(
                Env
              , T1 const&
              , T2 const&
              BOOST_PP_COMMA_IF(PHOENIX_ITERATION) PHOENIX_A_const_ref
            )
        >
            : result<
                This(
                    Env const &
                  , T1 const&
                  , T2 const&
                  BOOST_PP_COMMA_IF(PHOENIX_ITERATION) PHOENIX_A_const_ref
                )
            >
        {};
        
        template<typename This, typename Env, typename T1, typename T2 BOOST_PP_COMMA_IF(PHOENIX_ITERATION) PHOENIX_typename_A>
        struct result<
            This(
                Env &
              , T1 const&
              , T2 const&
              BOOST_PP_COMMA_IF(PHOENIX_ITERATION) PHOENIX_A_const_ref)
        >
            : boost::result_of<
                typename boost::remove_reference<
                    typename boost::result_of<
                        evaluator(T2 const &, Env&)>::type
                >::type(
                    typename boost::result_of<
                        evaluator(T1 const&, Env&)
                    >::type
                    BOOST_PP_ENUM_TRAILING(PHOENIX_ITERATION, PHOENIX_MEMBER_RESULT_OF, _)
                )
            >
        {};
		
        template <typename Env, typename T1, typename T2 BOOST_PP_ENUM_TRAILING_PARAMS(PHOENIX_ITERATION, typename A)>
		typename result<mem_fun_ptr_eval(Env &, T1 const&, T2 const&  BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(PHOENIX_ITERATION, A, const & BOOST_PP_INTERCEPT))>::type
		operator()(Env & env, T1 const& t1, T2 const& t2 BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(PHOENIX_ITERATION, A, const & a)) const
		{
			return (get_pointer(eval(t1, env))->*eval(t2, env))(BOOST_PP_ENUM(PHOENIX_ITERATION, PHOENIX_MEMBER_EVAL, _));
		}

#endif

