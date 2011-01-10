#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OPERATOR_MEMBER_HPP
#define PHOENIX_OPERATOR_MEMBER_HPP

#include <boost/get_pointer.hpp>
#include <boost/phoenix/core/expression.hpp>
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

    namespace result_of
    {
        template <
            typename Env
          , typename Expr
          , long Arity = proto::arity_of<Expr>::value
        >
        struct mem_fun_ptr_eval;

        #include <boost/phoenix/operator/detail/mem_fun_ptr_eval_result_of.hpp>
    }

	struct mem_fun_ptr_eval
		: proto::callable
	{
        template<typename Sig>
        struct result;
        
        template <typename This, typename Env, typename Expr>
        struct result<This(Env, Expr const &)>
            : result<This(Env const &, Expr const &)>
        {};

        template <typename This, typename Env, typename Expr>
        struct result<This(Env &, Expr const &)>
            : result_of::mem_fun_ptr_eval<Env, Expr>
        {};

        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        operator()(Env & env, Expr const & expr) const
        {
            return
                this->evaluate(
                    env
                  , expr
                  , typename proto::arity_of<Expr>::type()
                );
        }

    #define PHOENIX_MEMBER_EVAL(Z, N, D)                                        \
        BOOST_PP_COMMA_IF(BOOST_PP_NOT(BOOST_PP_EQUAL(N, 2)))                   \
        eval(proto::child_c< N >(expr), env)                                    \
    /**/
        private:
    #define PHOENIX_ITERATION_PARAMS                                            \
        (4, (2, PHOENIX_LIMIT,                                                  \
        <boost/phoenix/operator/member.hpp>,                                    \
        PHOENIX_ITERATE_OPERATOR))                                              \
    /**/
        #include PHOENIX_ITERATE()
    #undef PHOENIX_MEMBER_EVAL
	};

    template <typename Dummy>
    struct default_actions::when<rule::mem_fun_ptr, Dummy>
        : proto::call<mem_fun_ptr_eval(_env, proto::_)>
    {};
}}

#endif

#else // PHOENIX_IS_ITERATING
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<PHOENIX_ITERATION>
        ) const
        {
			return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    BOOST_PP_REPEAT_FROM_TO(
                        2
                      , PHOENIX_ITERATION
                      , PHOENIX_MEMBER_EVAL
                      , PHOENIX_ITERATION
                    )
                );
        }
        

#endif

