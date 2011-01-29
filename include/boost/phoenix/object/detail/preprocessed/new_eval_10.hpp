/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
    
    
    
    
    
    
    
        template <typename Context, typename A0>
        result_type
        operator()(Context& ctx, A0 const& a0) const
        {
            return
                new construct_type(
                    eval(a0, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename Context, typename A0 , typename A1>
        result_type
        operator()(Context& ctx, A0 const& a0 , A1 const& a1) const
        {
            return
                new construct_type(
                    eval(a0, ctx) , eval(a1, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename Context, typename A0 , typename A1 , typename A2>
        result_type
        operator()(Context& ctx, A0 const& a0 , A1 const& a1 , A2 const& a2) const
        {
            return
                new construct_type(
                    eval(a0, ctx) , eval(a1, ctx) , eval(a2, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename Context, typename A0 , typename A1 , typename A2 , typename A3>
        result_type
        operator()(Context& ctx, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3) const
        {
            return
                new construct_type(
                    eval(a0, ctx) , eval(a1, ctx) , eval(a2, ctx) , eval(a3, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename Context, typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        result_type
        operator()(Context& ctx, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4) const
        {
            return
                new construct_type(
                    eval(a0, ctx) , eval(a1, ctx) , eval(a2, ctx) , eval(a3, ctx) , eval(a4, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename Context, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        result_type
        operator()(Context& ctx, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5) const
        {
            return
                new construct_type(
                    eval(a0, ctx) , eval(a1, ctx) , eval(a2, ctx) , eval(a3, ctx) , eval(a4, ctx) , eval(a5, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename Context, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        result_type
        operator()(Context& ctx, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6) const
        {
            return
                new construct_type(
                    eval(a0, ctx) , eval(a1, ctx) , eval(a2, ctx) , eval(a3, ctx) , eval(a4, ctx) , eval(a5, ctx) , eval(a6, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename Context, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        result_type
        operator()(Context& ctx, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7) const
        {
            return
                new construct_type(
                    eval(a0, ctx) , eval(a1, ctx) , eval(a2, ctx) , eval(a3, ctx) , eval(a4, ctx) , eval(a5, ctx) , eval(a6, ctx) , eval(a7, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename Context, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        result_type
        operator()(Context& ctx, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8) const
        {
            return
                new construct_type(
                    eval(a0, ctx) , eval(a1, ctx) , eval(a2, ctx) , eval(a3, ctx) , eval(a4, ctx) , eval(a5, ctx) , eval(a6, ctx) , eval(a7, ctx) , eval(a8, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename Context, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        result_type
        operator()(Context& ctx, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9) const
        {
            return
                new construct_type(
                    eval(a0, ctx) , eval(a1, ctx) , eval(a2, ctx) , eval(a3, ctx) , eval(a4, ctx) , eval(a5, ctx) , eval(a6, ctx) , eval(a7, ctx) , eval(a8, ctx) , eval(a9, ctx)
                );
        }
