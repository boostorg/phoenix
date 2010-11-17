#ifndef PHOENIX_OPERATOR_MEMBER_HPP
#define PHOENIX_OPERATOR_MEMBER_HPP

/*#include <boost/get_pointer.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/compose.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/core/mem_obj_ptr.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/proto/make_expr.hpp>
#include <boost/proto/tags.hpp>
#include <boost/type_traits/is_member_object_pointer.hpp>*/
#include <boost/phoenix/core/unpack.hpp>
#include <boost/phoenix/operator/detail/mem_fun_ptr_gen.hpp>
#include <boost/type_traits/is_member_function_pointer.hpp>

namespace boost { namespace phoenix
{
	PHOENIX_BINARY_OPERATORS(
		(mem_ptr)
	)

	namespace rule
	{
		struct mem_fun_ptr
			: proto::nary_expr<tag::mem_fun_ptr, proto::vararg<meta_grammar> >
		{};
	}

	template <typename Dummy>
	struct meta_grammar::case_<tag::mem_fun_ptr, Dummy>
		: proto::when<rule::mem_fun_ptr, proto::external_transform>
	{};

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
		typedef int result_type;
		
		result_type
		operator()() const
		{
			std::cout << "ok ... evaluate ... \n";
			return 5;
		}

		template <typename T1>
		result_type
		operator()(T1 const& t1) const
		{
			std::cout << "ok ... evaluate ... \n";
			return 5;
		}

		template <typename T1, typename T2>
		result_type
		operator()(T1 const& t1, T2 const& t2) const
		{
			std::cout << "ok ... evaluate ... \n";
			return 5;
		}

		template <typename T1, typename T2, typename T3>
		result_type
		operator()(T1 const& t1, T2 const& t2, T3 const& t3) const
		{
			std::cout << "ok ... evaluate ... \n";
            std::cout << typeid(T1).name() << "\n";
            std::cout << typeid(T2).name() << "\n";
            std::cout << typeid(T3).name() << "\n";
			return 5;
		}

		template <typename Env, typename T1, typename T2, typename T3>
		result_type
		operator()(Env & env, T1 const& t1, T2 const& t2, T3 const& t3) const
		{
			std::cout << "ok ... evaluate ... \n";
            std::cout << typeid(T1).name() << "\n";
            std::cout << typeid(T2).name() << "\n";
            std::cout << typeid(T3).name() << "\n";
			return 5;
		}
	};

    template <typename Dummy>
    struct default_actions::when<rule::mem_fun_ptr, Dummy>
        : proto::call<mem_fun_ptr_eval(unpack(proto::_, evaluator(proto::_, _env)))>
    {};
}}

#endif

