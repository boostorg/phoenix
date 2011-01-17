/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
    
    
    
    
    
    
    
        template <typename Env, typename A0>
        result_type
        operator()(Env& env, A0 const& a0) const
        {
            return
                new construct_type(
                    eval(a0, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env)
                );
        }
    
    
    
    
    
    
    
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19) const
        {
            return
                new construct_type(
                    eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env)
                );
        }
