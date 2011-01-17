/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
    
    
    
    
    
    
    
        template <typename This, typename A0>
        struct result<This(A0)>
            : result_of::actor<Expr, A0>
        {};
        template <typename A0> typename result_of::actor<Expr, A0 &>::type operator()(A0 & a0) const { typedef typename fusion::result_of::make_vector<A0 &>::type args_type; args_type args(a0); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0> typename result_of::actor<Expr, A0 &>::type operator()(A0 & a0) { typedef typename fusion::result_of::make_vector<A0 &>::type args_type; args_type args(a0); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0> typename result_of::actor<Expr, A0 const&>::type operator()(A0 const& a0) const { typedef typename fusion::result_of::make_vector<A0 const&>::type args_type; args_type args(a0); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0> typename result_of::actor<Expr, A0 const&>::type operator()(A0 const& a0) { typedef typename fusion::result_of::make_vector<A0 const&>::type args_type; args_type args(a0); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1>
        struct result<This(A0 , A1)>
            : result_of::actor<Expr, A0 , A1>
        {};
        template <typename A0 , typename A1> typename result_of::actor<Expr, A0 & , A1 &>::type operator()(A0 & a0 , A1 & a1) const { typedef typename fusion::result_of::make_vector<A0 & , A1 &>::type args_type; args_type args(a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 & , A1 &>::type operator()(A0 & a0 , A1 & a1) { typedef typename fusion::result_of::make_vector<A0 & , A1 &>::type args_type; args_type args(a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 & , A1 const&>::type operator()(A0 & a0 , A1 const& a1) const { typedef typename fusion::result_of::make_vector<A0 & , A1 const&>::type args_type; args_type args(a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 & , A1 const&>::type operator()(A0 & a0 , A1 const& a1) { typedef typename fusion::result_of::make_vector<A0 & , A1 const&>::type args_type; args_type args(a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 const& , A1 &>::type operator()(A0 const& a0 , A1 & a1) const { typedef typename fusion::result_of::make_vector<A0 const& , A1 &>::type args_type; args_type args(a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 const& , A1 &>::type operator()(A0 const& a0 , A1 & a1) { typedef typename fusion::result_of::make_vector<A0 const& , A1 &>::type args_type; args_type args(a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 const& , A1 const&>::type operator()(A0 const& a0 , A1 const& a1) const { typedef typename fusion::result_of::make_vector<A0 const& , A1 const&>::type args_type; args_type args(a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 const& , A1 const&>::type operator()(A0 const& a0 , A1 const& a1) { typedef typename fusion::result_of::make_vector<A0 const& , A1 const&>::type args_type; args_type args(a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2>
        struct result<This(A0 , A1 , A2)>
            : result_of::actor<Expr, A0 , A1 , A2>
        {};
        template <typename A0 , typename A1 , typename A2>
        typename result_of::actor<Expr, A0 & , A1 & , A2 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2)
        {
            typedef
                fusion::vector3<
                    A0 & , A1 & , A2 &
                >
                args_type;
            args_type args(a0 , a1 , a2);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2>
        typename result_of::actor<Expr, A0 & , A1 & , A2 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2) const
        {
            typedef
                fusion::vector3<
                    A0 & , A1 & , A2 &
                >
                args_type;
            args_type args(a0 , a1 , a2);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2)
        {
            typedef
                fusion::vector3<
                    A0 const& , A1 const& , A2 const&
                >
                args_type;
            args_type args(a0 , a1 , a2);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2) const
        {
            typedef
                fusion::vector3<
                    A0 const& , A1 const& , A2 const&
                >
                args_type;
            args_type args(a0 , a1 , a2);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3>
        struct result<This(A0 , A1 , A2 , A3)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3)
        {
            typedef
                fusion::vector4<
                    A0 & , A1 & , A2 & , A3 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3) const
        {
            typedef
                fusion::vector4<
                    A0 & , A1 & , A2 & , A3 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3)
        {
            typedef
                fusion::vector4<
                    A0 const& , A1 const& , A2 const& , A3 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3) const
        {
            typedef
                fusion::vector4<
                    A0 const& , A1 const& , A2 const& , A3 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        struct result<This(A0 , A1 , A2 , A3 , A4)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4)
        {
            typedef
                fusion::vector5<
                    A0 & , A1 & , A2 & , A3 & , A4 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4) const
        {
            typedef
                fusion::vector5<
                    A0 & , A1 & , A2 & , A3 & , A4 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4)
        {
            typedef
                fusion::vector5<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4) const
        {
            typedef
                fusion::vector5<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5)
        {
            typedef
                fusion::vector6<
                    A0 & , A1 & , A2 & , A3 & , A4 & , A5 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5) const
        {
            typedef
                fusion::vector6<
                    A0 & , A1 & , A2 & , A3 & , A4 & , A5 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5)
        {
            typedef
                fusion::vector6<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5) const
        {
            typedef
                fusion::vector6<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6)
        {
            typedef
                fusion::vector7<
                    A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6) const
        {
            typedef
                fusion::vector7<
                    A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6)
        {
            typedef
                fusion::vector7<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6) const
        {
            typedef
                fusion::vector7<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7)
        {
            typedef
                fusion::vector8<
                    A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7) const
        {
            typedef
                fusion::vector8<
                    A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7)
        {
            typedef
                fusion::vector8<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7) const
        {
            typedef
                fusion::vector8<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8)
        {
            typedef
                fusion::vector9<
                    A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8) const
        {
            typedef
                fusion::vector9<
                    A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8)
        {
            typedef
                fusion::vector9<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8) const
        {
            typedef
                fusion::vector9<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9)
        {
            typedef
                fusion::vector10<
                    A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9) const
        {
            typedef
                fusion::vector10<
                    A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 &
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9)
        {
            typedef
                fusion::vector10<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9) const
        {
            typedef
                fusion::vector10<
                    A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const&
                >
                args_type;
            args_type args(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
