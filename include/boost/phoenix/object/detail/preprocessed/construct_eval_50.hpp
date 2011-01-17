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
            return result_type(eval(a0, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1) const
        {
            return result_type(eval(a0, env) , eval(a1, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env) , eval(a39, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env) , eval(a39, env) , eval(a40, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env) , eval(a39, env) , eval(a40, env) , eval(a41, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env) , eval(a39, env) , eval(a40, env) , eval(a41, env) , eval(a42, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env) , eval(a39, env) , eval(a40, env) , eval(a41, env) , eval(a42, env) , eval(a43, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env) , eval(a39, env) , eval(a40, env) , eval(a41, env) , eval(a42, env) , eval(a43, env) , eval(a44, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44 , A45 const& a45) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env) , eval(a39, env) , eval(a40, env) , eval(a41, env) , eval(a42, env) , eval(a43, env) , eval(a44, env) , eval(a45, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44 , A45 const& a45 , A46 const& a46) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env) , eval(a39, env) , eval(a40, env) , eval(a41, env) , eval(a42, env) , eval(a43, env) , eval(a44, env) , eval(a45, env) , eval(a46, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44 , A45 const& a45 , A46 const& a46 , A47 const& a47) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env) , eval(a39, env) , eval(a40, env) , eval(a41, env) , eval(a42, env) , eval(a43, env) , eval(a44, env) , eval(a45, env) , eval(a46, env) , eval(a47, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47 , typename A48>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44 , A45 const& a45 , A46 const& a46 , A47 const& a47 , A48 const& a48) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env) , eval(a39, env) , eval(a40, env) , eval(a41, env) , eval(a42, env) , eval(a43, env) , eval(a44, env) , eval(a45, env) , eval(a46, env) , eval(a47, env) , eval(a48, env));
        }
    
    
    
    
    
    
    
        
        template <typename Env, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47 , typename A48 , typename A49>
        result_type
        operator()(Env& env, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44 , A45 const& a45 , A46 const& a46 , A47 const& a47 , A48 const& a48 , A49 const& a49) const
        {
            return result_type(eval(a0, env) , eval(a1, env) , eval(a2, env) , eval(a3, env) , eval(a4, env) , eval(a5, env) , eval(a6, env) , eval(a7, env) , eval(a8, env) , eval(a9, env) , eval(a10, env) , eval(a11, env) , eval(a12, env) , eval(a13, env) , eval(a14, env) , eval(a15, env) , eval(a16, env) , eval(a17, env) , eval(a18, env) , eval(a19, env) , eval(a20, env) , eval(a21, env) , eval(a22, env) , eval(a23, env) , eval(a24, env) , eval(a25, env) , eval(a26, env) , eval(a27, env) , eval(a28, env) , eval(a29, env) , eval(a30, env) , eval(a31, env) , eval(a32, env) , eval(a33, env) , eval(a34, env) , eval(a35, env) , eval(a36, env) , eval(a37, env) , eval(a38, env) , eval(a39, env) , eval(a40, env) , eval(a41, env) , eval(a42, env) , eval(a43, env) , eval(a44, env) , eval(a45, env) , eval(a46, env) , eval(a47, env) , eval(a48, env) , eval(a49, env));
        }
