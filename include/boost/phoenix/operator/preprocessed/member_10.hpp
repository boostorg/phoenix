/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
namespace boost { namespace phoenix
{
    namespace rule { struct mem_ptr : proto::binary_expr<proto::tag::mem_ptr, proto::_, proto::_> {}; } template <typename Dummy> struct meta_grammar::case_<proto::tag::mem_ptr, Dummy> : proto::when<rule::mem_ptr, proto::external_transform> {};
    namespace tag { struct mem_fun_ptr {}; } namespace expression { template < typename A0 = void , typename A1 = void , typename A2 = void , typename A3 = void , typename A4 = void , typename A5 = void , typename A6 = void , typename A7 = void , typename A8 = void , typename A9 = void , typename Dummy = void > struct mem_fun_ptr; template < typename A0 > struct mem_fun_ptr< A0 > : expr< tag:: mem_fun_ptr , A0 > {}; template < typename A0 , typename A1 > struct mem_fun_ptr< A0 , A1 > : expr< tag:: mem_fun_ptr , A0 , A1 > {}; template < typename A0 , typename A1 , typename A2 > struct mem_fun_ptr< A0 , A1 , A2 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 > struct mem_fun_ptr< A0 , A1 , A2 , A3 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 > {}; } namespace rule { struct mem_fun_ptr : expression:: mem_fun_ptr < proto::vararg< meta_grammar > > {}; } template <typename Dummy> struct meta_grammar::case_<tag:: mem_fun_ptr, Dummy> : proto::when<rule:: mem_fun_ptr, proto::external_transform> {};
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
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 2>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1;
            typedef
                typename boost::result_of<
                    child1(
                        child1
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 3>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 4>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 5>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 6>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 7>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 8>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 9>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 10>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9
                    )
                >::type
                type;
        };
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
        private:
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<2>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<3>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<4>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<5>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<6>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<7>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<8>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<9>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<10>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env)
                );
        }
        
    };
    template <typename Dummy>
    struct default_actions::when<rule::mem_fun_ptr, Dummy>
        : proto::call<mem_fun_ptr_eval(_context, proto::_)>
    {};
}}
