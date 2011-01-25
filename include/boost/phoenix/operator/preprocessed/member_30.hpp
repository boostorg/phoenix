/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
namespace boost { namespace phoenix
{
    namespace rule { struct mem_ptr : proto::binary_expr<proto::tag::mem_ptr, proto::_, proto::_> {}; } template <typename Dummy> struct meta_grammar::case_<proto::tag::mem_ptr, Dummy> : proto::when<rule::mem_ptr, proto::external_transform> {};
    namespace tag { struct mem_fun_ptr {}; } namespace expression { template < typename A0 = void , typename A1 = void , typename A2 = void , typename A3 = void , typename A4 = void , typename A5 = void , typename A6 = void , typename A7 = void , typename A8 = void , typename A9 = void , typename A10 = void , typename A11 = void , typename A12 = void , typename A13 = void , typename A14 = void , typename A15 = void , typename A16 = void , typename A17 = void , typename A18 = void , typename A19 = void , typename A20 = void , typename A21 = void , typename A22 = void , typename A23 = void , typename A24 = void , typename A25 = void , typename A26 = void , typename A27 = void , typename A28 = void , typename A29 = void , typename Dummy = void > struct mem_fun_ptr; template < typename A0 > struct mem_fun_ptr< A0 > : expr< tag:: mem_fun_ptr , A0 > {}; template < typename A0 , typename A1 > struct mem_fun_ptr< A0 , A1 > : expr< tag:: mem_fun_ptr , A0 , A1 > {}; template < typename A0 , typename A1 , typename A2 > struct mem_fun_ptr< A0 , A1 , A2 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 > struct mem_fun_ptr< A0 , A1 , A2 , A3 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 > struct mem_fun_ptr< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 > : expr< tag:: mem_fun_ptr , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 > {}; } namespace rule { struct mem_fun_ptr : expression:: mem_fun_ptr < proto::vararg< meta_grammar > > {}; } template <typename Dummy> struct meta_grammar::case_<tag:: mem_fun_ptr, Dummy> : proto::when<rule:: mem_fun_ptr, proto::external_transform> {};
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
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 11>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 12>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 13>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 14>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 15>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 16>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 17>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 18>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 19>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 20>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 19>::type , Env , int >::result_type child19;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18 , child19
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 21>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 19>::type , Env , int >::result_type child19; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 20>::type , Env , int >::result_type child20;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18 , child19 , child20
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 22>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 19>::type , Env , int >::result_type child19; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 20>::type , Env , int >::result_type child20; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 21>::type , Env , int >::result_type child21;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18 , child19 , child20 , child21
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 23>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 19>::type , Env , int >::result_type child19; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 20>::type , Env , int >::result_type child20; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 21>::type , Env , int >::result_type child21; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 22>::type , Env , int >::result_type child22;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18 , child19 , child20 , child21 , child22
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 24>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 19>::type , Env , int >::result_type child19; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 20>::type , Env , int >::result_type child20; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 21>::type , Env , int >::result_type child21; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 22>::type , Env , int >::result_type child22; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 23>::type , Env , int >::result_type child23;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18 , child19 , child20 , child21 , child22 , child23
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 25>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 19>::type , Env , int >::result_type child19; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 20>::type , Env , int >::result_type child20; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 21>::type , Env , int >::result_type child21; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 22>::type , Env , int >::result_type child22; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 23>::type , Env , int >::result_type child23; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 24>::type , Env , int >::result_type child24;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18 , child19 , child20 , child21 , child22 , child23 , child24
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 26>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 19>::type , Env , int >::result_type child19; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 20>::type , Env , int >::result_type child20; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 21>::type , Env , int >::result_type child21; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 22>::type , Env , int >::result_type child22; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 23>::type , Env , int >::result_type child23; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 24>::type , Env , int >::result_type child24; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 25>::type , Env , int >::result_type child25;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18 , child19 , child20 , child21 , child22 , child23 , child24 , child25
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 27>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 19>::type , Env , int >::result_type child19; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 20>::type , Env , int >::result_type child20; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 21>::type , Env , int >::result_type child21; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 22>::type , Env , int >::result_type child22; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 23>::type , Env , int >::result_type child23; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 24>::type , Env , int >::result_type child24; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 25>::type , Env , int >::result_type child25; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 26>::type , Env , int >::result_type child26;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18 , child19 , child20 , child21 , child22 , child23 , child24 , child25 , child26
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 28>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 19>::type , Env , int >::result_type child19; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 20>::type , Env , int >::result_type child20; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 21>::type , Env , int >::result_type child21; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 22>::type , Env , int >::result_type child22; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 23>::type , Env , int >::result_type child23; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 24>::type , Env , int >::result_type child24; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 25>::type , Env , int >::result_type child25; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 26>::type , Env , int >::result_type child26; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 27>::type , Env , int >::result_type child27;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18 , child19 , child20 , child21 , child22 , child23 , child24 , child25 , child26 , child27
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 29>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 19>::type , Env , int >::result_type child19; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 20>::type , Env , int >::result_type child20; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 21>::type , Env , int >::result_type child21; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 22>::type , Env , int >::result_type child22; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 23>::type , Env , int >::result_type child23; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 24>::type , Env , int >::result_type child24; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 25>::type , Env , int >::result_type child25; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 26>::type , Env , int >::result_type child26; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 27>::type , Env , int >::result_type child27; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 28>::type , Env , int >::result_type child28;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18 , child19 , child20 , child21 , child22 , child23 , child24 , child25 , child26 , child27 , child28
                    )
                >::type
                type;
        };
    
    
    
    
    
    
    
        template <typename Env, typename Expr>
        struct mem_fun_ptr_eval<Env, Expr, 30>
        {
            typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 0>::type , Env , int >::result_type child0; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 1>::type , Env , int >::result_type child1; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 2>::type , Env , int >::result_type child2; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 3>::type , Env , int >::result_type child3; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 4>::type , Env , int >::result_type child4; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 5>::type , Env , int >::result_type child5; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 6>::type , Env , int >::result_type child6; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 7>::type , Env , int >::result_type child7; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 8>::type , Env , int >::result_type child8; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 9>::type , Env , int >::result_type child9; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 10>::type , Env , int >::result_type child10; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 11>::type , Env , int >::result_type child11; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 12>::type , Env , int >::result_type child12; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 13>::type , Env , int >::result_type child13; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 14>::type , Env , int >::result_type child14; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 15>::type , Env , int >::result_type child15; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 16>::type , Env , int >::result_type child16; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 17>::type , Env , int >::result_type child17; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 18>::type , Env , int >::result_type child18; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 19>::type , Env , int >::result_type child19; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 20>::type , Env , int >::result_type child20; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 21>::type , Env , int >::result_type child21; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 22>::type , Env , int >::result_type child22; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 23>::type , Env , int >::result_type child23; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 24>::type , Env , int >::result_type child24; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 25>::type , Env , int >::result_type child25; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 26>::type , Env , int >::result_type child26; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 27>::type , Env , int >::result_type child27; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 28>::type , Env , int >::result_type child28; typedef typename evaluator::impl< typename proto::result_of::child_c<Expr, 29>::type , Env , int >::result_type child29;
            typedef
                typename boost::result_of<
                    child1(
                        child1 , child2 , child3 , child4 , child5 , child6 , child7 , child8 , child9 , child10 , child11 , child12 , child13 , child14 , child15 , child16 , child17 , child18 , child19 , child20 , child21 , child22 , child23 , child24 , child25 , child26 , child27 , child28 , child29
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
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<11>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<12>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<13>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<14>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<15>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<16>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<17>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<18>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<19>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<20>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env) , eval(proto::child_c< 19 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<21>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env) , eval(proto::child_c< 19 >(expr), env) , eval(proto::child_c< 20 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<22>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env) , eval(proto::child_c< 19 >(expr), env) , eval(proto::child_c< 20 >(expr), env) , eval(proto::child_c< 21 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<23>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env) , eval(proto::child_c< 19 >(expr), env) , eval(proto::child_c< 20 >(expr), env) , eval(proto::child_c< 21 >(expr), env) , eval(proto::child_c< 22 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<24>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env) , eval(proto::child_c< 19 >(expr), env) , eval(proto::child_c< 20 >(expr), env) , eval(proto::child_c< 21 >(expr), env) , eval(proto::child_c< 22 >(expr), env) , eval(proto::child_c< 23 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<25>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env) , eval(proto::child_c< 19 >(expr), env) , eval(proto::child_c< 20 >(expr), env) , eval(proto::child_c< 21 >(expr), env) , eval(proto::child_c< 22 >(expr), env) , eval(proto::child_c< 23 >(expr), env) , eval(proto::child_c< 24 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<26>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env) , eval(proto::child_c< 19 >(expr), env) , eval(proto::child_c< 20 >(expr), env) , eval(proto::child_c< 21 >(expr), env) , eval(proto::child_c< 22 >(expr), env) , eval(proto::child_c< 23 >(expr), env) , eval(proto::child_c< 24 >(expr), env) , eval(proto::child_c< 25 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<27>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env) , eval(proto::child_c< 19 >(expr), env) , eval(proto::child_c< 20 >(expr), env) , eval(proto::child_c< 21 >(expr), env) , eval(proto::child_c< 22 >(expr), env) , eval(proto::child_c< 23 >(expr), env) , eval(proto::child_c< 24 >(expr), env) , eval(proto::child_c< 25 >(expr), env) , eval(proto::child_c< 26 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<28>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env) , eval(proto::child_c< 19 >(expr), env) , eval(proto::child_c< 20 >(expr), env) , eval(proto::child_c< 21 >(expr), env) , eval(proto::child_c< 22 >(expr), env) , eval(proto::child_c< 23 >(expr), env) , eval(proto::child_c< 24 >(expr), env) , eval(proto::child_c< 25 >(expr), env) , eval(proto::child_c< 26 >(expr), env) , eval(proto::child_c< 27 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<29>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env) , eval(proto::child_c< 19 >(expr), env) , eval(proto::child_c< 20 >(expr), env) , eval(proto::child_c< 21 >(expr), env) , eval(proto::child_c< 22 >(expr), env) , eval(proto::child_c< 23 >(expr), env) , eval(proto::child_c< 24 >(expr), env) , eval(proto::child_c< 25 >(expr), env) , eval(proto::child_c< 26 >(expr), env) , eval(proto::child_c< 27 >(expr), env) , eval(proto::child_c< 28 >(expr), env)
                );
        }
        
    
    
    
    
    
    
    
            
        template <typename Env, typename Expr>
        typename result_of::mem_fun_ptr_eval<Env, Expr>::type
        evaluate(
            Env & env
          , Expr const & expr
          , mpl::long_<30>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), env))
                    ->*eval(proto::child_c<1>(expr), env)
                )(
                    eval(proto::child_c< 2 >(expr), env) , eval(proto::child_c< 3 >(expr), env) , eval(proto::child_c< 4 >(expr), env) , eval(proto::child_c< 5 >(expr), env) , eval(proto::child_c< 6 >(expr), env) , eval(proto::child_c< 7 >(expr), env) , eval(proto::child_c< 8 >(expr), env) , eval(proto::child_c< 9 >(expr), env) , eval(proto::child_c< 10 >(expr), env) , eval(proto::child_c< 11 >(expr), env) , eval(proto::child_c< 12 >(expr), env) , eval(proto::child_c< 13 >(expr), env) , eval(proto::child_c< 14 >(expr), env) , eval(proto::child_c< 15 >(expr), env) , eval(proto::child_c< 16 >(expr), env) , eval(proto::child_c< 17 >(expr), env) , eval(proto::child_c< 18 >(expr), env) , eval(proto::child_c< 19 >(expr), env) , eval(proto::child_c< 20 >(expr), env) , eval(proto::child_c< 21 >(expr), env) , eval(proto::child_c< 22 >(expr), env) , eval(proto::child_c< 23 >(expr), env) , eval(proto::child_c< 24 >(expr), env) , eval(proto::child_c< 25 >(expr), env) , eval(proto::child_c< 26 >(expr), env) , eval(proto::child_c< 27 >(expr), env) , eval(proto::child_c< 28 >(expr), env) , eval(proto::child_c< 29 >(expr), env)
                );
        }
        
    };
    template <typename Dummy>
    struct default_actions::when<rule::mem_fun_ptr, Dummy>
        : proto::call<mem_fun_ptr_eval(_context, proto::_)>
    {};
}}
