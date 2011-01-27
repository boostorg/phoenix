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
        template <typename A0> typename result_of::actor<Expr, A0 &>::type operator()(A0 & a0) const { typedef typename fusion::result_of::make_vector<const actor<Expr> *, A0 &>::type args_type; args_type args(this, a0); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0> typename result_of::actor<Expr, A0 &>::type operator()(A0 & a0) { typedef typename fusion::result_of::make_vector<const actor<Expr> *,A0 &>::type args_type; args_type args(this, a0); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0> typename result_of::actor<Expr, A0 const&>::type operator()(A0 const& a0) const { typedef typename fusion::result_of::make_vector<const actor<Expr> *, A0 const&>::type args_type; args_type args(this, a0); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0> typename result_of::actor<Expr, A0 const&>::type operator()(A0 const& a0) { typedef typename fusion::result_of::make_vector<const actor<Expr> *,A0 const&>::type args_type; args_type args(this, a0); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1>
        struct result<This(A0 , A1)>
            : result_of::actor<Expr, A0 , A1>
        {};
        template <typename A0 , typename A1> typename result_of::actor<Expr, A0 & , A1 &>::type operator()(A0 & a0 , A1 & a1) const { typedef typename fusion::result_of::make_vector<const actor<Expr> *, A0 & , A1 &>::type args_type; args_type args(this, a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 & , A1 &>::type operator()(A0 & a0 , A1 & a1) { typedef typename fusion::result_of::make_vector<const actor<Expr> *,A0 & , A1 &>::type args_type; args_type args(this, a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 & , A1 const&>::type operator()(A0 & a0 , A1 const& a1) const { typedef typename fusion::result_of::make_vector<const actor<Expr> *, A0 & , A1 const&>::type args_type; args_type args(this, a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 & , A1 const&>::type operator()(A0 & a0 , A1 const& a1) { typedef typename fusion::result_of::make_vector<const actor<Expr> *,A0 & , A1 const&>::type args_type; args_type args(this, a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 const& , A1 &>::type operator()(A0 const& a0 , A1 & a1) const { typedef typename fusion::result_of::make_vector<const actor<Expr> *, A0 const& , A1 &>::type args_type; args_type args(this, a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 const& , A1 &>::type operator()(A0 const& a0 , A1 & a1) { typedef typename fusion::result_of::make_vector<const actor<Expr> *,A0 const& , A1 &>::type args_type; args_type args(this, a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 const& , A1 const&>::type operator()(A0 const& a0 , A1 const& a1) const { typedef typename fusion::result_of::make_vector<const actor<Expr> *, A0 const& , A1 const&>::type args_type; args_type args(this, a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); } template <typename A0 , typename A1> typename result_of::actor<Expr, A0 const& , A1 const&>::type operator()(A0 const& a0 , A1 const& a1) { typedef typename fusion::result_of::make_vector<const actor<Expr> *,A0 const& , A1 const&>::type args_type; args_type args(this, a0 , a1); fusion::vector2< args_type&, default_actions > env(args, default_actions()); return eval(*this, env); }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2>
        struct result<This(A0 , A1 , A2)>
            : result_of::actor<Expr, A0 , A1 , A2>
        {};
        template <typename A0 , typename A1 , typename A2>
        typename result_of::actor<Expr, A0 & , A1 & , A2 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2)
        {
            typedef
                fusion::vector4<
                    const actor<Expr> *, A0 & , A1 & , A2 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2>
        typename result_of::actor<Expr, A0 & , A1 & , A2 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2) const
        {
            typedef
                fusion::vector4<
                    const actor<Expr> *, A0 & , A1 & , A2 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2)
        {
            typedef
                fusion::vector4<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2) const
        {
            typedef
                fusion::vector4<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2);
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
                fusion::vector5<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3) const
        {
            typedef
                fusion::vector5<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3)
        {
            typedef
                fusion::vector5<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3) const
        {
            typedef
                fusion::vector5<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3);
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
                fusion::vector6<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4) const
        {
            typedef
                fusion::vector6<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4)
        {
            typedef
                fusion::vector6<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4) const
        {
            typedef
                fusion::vector6<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4);
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
                fusion::vector7<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5) const
        {
            typedef
                fusion::vector7<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5)
        {
            typedef
                fusion::vector7<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5) const
        {
            typedef
                fusion::vector7<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5);
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
                fusion::vector8<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6) const
        {
            typedef
                fusion::vector8<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6)
        {
            typedef
                fusion::vector8<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6) const
        {
            typedef
                fusion::vector8<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6);
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
                fusion::vector9<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7) const
        {
            typedef
                fusion::vector9<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7)
        {
            typedef
                fusion::vector9<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7) const
        {
            typedef
                fusion::vector9<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
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
                fusion::vector10<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8) const
        {
            typedef
                fusion::vector10<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8)
        {
            typedef
                fusion::vector10<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8) const
        {
            typedef
                fusion::vector10<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
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
                fusion::vector11<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9) const
        {
            typedef
                fusion::vector11<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9)
        {
            typedef
                fusion::vector11<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9) const
        {
            typedef
                fusion::vector11<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10)
        {
            typedef
                fusion::vector12<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10) const
        {
            typedef
                fusion::vector12<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10)
        {
            typedef
                fusion::vector12<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10) const
        {
            typedef
                fusion::vector12<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11)
        {
            typedef
                fusion::vector13<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11) const
        {
            typedef
                fusion::vector13<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11)
        {
            typedef
                fusion::vector13<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11) const
        {
            typedef
                fusion::vector13<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12)
        {
            typedef
                fusion::vector14<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12) const
        {
            typedef
                fusion::vector14<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12)
        {
            typedef
                fusion::vector14<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12) const
        {
            typedef
                fusion::vector14<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13)
        {
            typedef
                fusion::vector15<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13) const
        {
            typedef
                fusion::vector15<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13)
        {
            typedef
                fusion::vector15<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13) const
        {
            typedef
                fusion::vector15<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14)
        {
            typedef
                fusion::vector16<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14) const
        {
            typedef
                fusion::vector16<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14)
        {
            typedef
                fusion::vector16<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14) const
        {
            typedef
                fusion::vector16<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15)
        {
            typedef
                fusion::vector17<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15) const
        {
            typedef
                fusion::vector17<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15)
        {
            typedef
                fusion::vector17<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15) const
        {
            typedef
                fusion::vector17<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16)
        {
            typedef
                fusion::vector18<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16) const
        {
            typedef
                fusion::vector18<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16)
        {
            typedef
                fusion::vector18<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16) const
        {
            typedef
                fusion::vector18<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17)
        {
            typedef
                fusion::vector19<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17) const
        {
            typedef
                fusion::vector19<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17)
        {
            typedef
                fusion::vector19<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17) const
        {
            typedef
                fusion::vector19<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18)
        {
            typedef
                fusion::vector20<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18) const
        {
            typedef
                fusion::vector20<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const& , A18 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18)
        {
            typedef
                fusion::vector20<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const& , A18 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const& , A18 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18) const
        {
            typedef
                fusion::vector20<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const& , A18 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19)>
            : result_of::actor<Expr, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19>
        {};
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19)
        {
            typedef
                fusion::vector21<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19>
        typename result_of::actor<Expr, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 &>::type
        operator()(A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19) const
        {
            typedef
                fusion::vector21<
                    const actor<Expr> *, A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 &
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const& , A18 const& , A19 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19)
        {
            typedef
                fusion::vector21<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const& , A18 const& , A19 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            
            return eval(*this, env);
        }
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19>
        typename result_of::actor<Expr, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const& , A18 const& , A19 const&>::type
        operator()(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19) const
        {
            typedef
                fusion::vector21<
                    const actor<Expr> *, A0 const& , A1 const& , A2 const& , A3 const& , A4 const& , A5 const& , A6 const& , A7 const& , A8 const& , A9 const& , A10 const& , A11 const& , A12 const& , A13 const& , A14 const& , A15 const& , A16 const& , A17 const& , A18 const& , A19 const&
                >
                args_type;
            args_type args(this, a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19);
            fusion::vector2<args_type&, default_actions>
                env(args, default_actions());
            return eval(*this, env);
        }
