/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2>
        struct make_locals<A0 , A1 , A2>
        {
            typedef
                typename make_locals<
                    A0 , A1
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A2
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2)
            {
                return
                    expression::sequence<
                        type0
                      , A2
                    >::make(
                        make_locals<
                            A0 , A1
                        >::make(
                            a0 , a1
                        )
                      , a2
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3>
        struct make_locals<A0 , A1 , A2 , A3>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A3
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3)
            {
                return
                    expression::sequence<
                        type0
                      , A3
                    >::make(
                        make_locals<
                            A0 , A1 , A2
                        >::make(
                            a0 , a1 , a2
                        )
                      , a3
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        struct make_locals<A0 , A1 , A2 , A3 , A4>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A4
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4)
            {
                return
                    expression::sequence<
                        type0
                      , A4
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3
                        >::make(
                            a0 , a1 , a2 , a3
                        )
                      , a4
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A5
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5)
            {
                return
                    expression::sequence<
                        type0
                      , A5
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4
                        >::make(
                            a0 , a1 , a2 , a3 , a4
                        )
                      , a5
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A6
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6)
            {
                return
                    expression::sequence<
                        type0
                      , A6
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5
                        )
                      , a6
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A7
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7)
            {
                return
                    expression::sequence<
                        type0
                      , A7
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6
                        )
                      , a7
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A8
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8)
            {
                return
                    expression::sequence<
                        type0
                      , A8
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7
                        )
                      , a8
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A9
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9)
            {
                return
                    expression::sequence<
                        type0
                      , A9
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8
                        )
                      , a9
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A10
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10)
            {
                return
                    expression::sequence<
                        type0
                      , A10
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9
                        )
                      , a10
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A11
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11)
            {
                return
                    expression::sequence<
                        type0
                      , A11
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10
                        )
                      , a11
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A12
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12)
            {
                return
                    expression::sequence<
                        type0
                      , A12
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11
                        )
                      , a12
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A13
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13)
            {
                return
                    expression::sequence<
                        type0
                      , A13
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12
                        )
                      , a13
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A14
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14)
            {
                return
                    expression::sequence<
                        type0
                      , A14
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13
                        )
                      , a14
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A15
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15)
            {
                return
                    expression::sequence<
                        type0
                      , A15
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14
                        )
                      , a15
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A16
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16)
            {
                return
                    expression::sequence<
                        type0
                      , A16
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15
                        )
                      , a16
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A17
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17)
            {
                return
                    expression::sequence<
                        type0
                      , A17
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16
                        )
                      , a17
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A18
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18)
            {
                return
                    expression::sequence<
                        type0
                      , A18
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17
                        )
                      , a18
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A19
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19)
            {
                return
                    expression::sequence<
                        type0
                      , A19
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18
                        )
                      , a19
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A20
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20)
            {
                return
                    expression::sequence<
                        type0
                      , A20
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19
                        )
                      , a20
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A21
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21)
            {
                return
                    expression::sequence<
                        type0
                      , A21
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20
                        )
                      , a21
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A22
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22)
            {
                return
                    expression::sequence<
                        type0
                      , A22
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21
                        )
                      , a22
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A23
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23)
            {
                return
                    expression::sequence<
                        type0
                      , A23
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22
                        )
                      , a23
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A24
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24)
            {
                return
                    expression::sequence<
                        type0
                      , A24
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23
                        )
                      , a24
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A25
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25)
            {
                return
                    expression::sequence<
                        type0
                      , A25
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24
                        )
                      , a25
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A26
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26)
            {
                return
                    expression::sequence<
                        type0
                      , A26
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25
                        )
                      , a26
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A27
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27)
            {
                return
                    expression::sequence<
                        type0
                      , A27
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26
                        )
                      , a27
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A28
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28)
            {
                return
                    expression::sequence<
                        type0
                      , A28
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27
                        )
                      , a28
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A29
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29)
            {
                return
                    expression::sequence<
                        type0
                      , A29
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28
                        )
                      , a29
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A30
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30)
            {
                return
                    expression::sequence<
                        type0
                      , A30
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29
                        )
                      , a30
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A31
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31)
            {
                return
                    expression::sequence<
                        type0
                      , A31
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30
                        )
                      , a31
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A32
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32)
            {
                return
                    expression::sequence<
                        type0
                      , A32
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31
                        )
                      , a32
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A33
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33)
            {
                return
                    expression::sequence<
                        type0
                      , A33
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32
                        )
                      , a33
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A34
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34)
            {
                return
                    expression::sequence<
                        type0
                      , A34
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33
                        )
                      , a34
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A35
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35)
            {
                return
                    expression::sequence<
                        type0
                      , A35
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34
                        )
                      , a35
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A36
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36)
            {
                return
                    expression::sequence<
                        type0
                      , A36
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35
                        )
                      , a36
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A37
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37)
            {
                return
                    expression::sequence<
                        type0
                      , A37
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36
                        )
                      , a37
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A38
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38)
            {
                return
                    expression::sequence<
                        type0
                      , A38
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37
                        )
                      , a38
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A39
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38 , A39 a39)
            {
                return
                    expression::sequence<
                        type0
                      , A39
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37 , a38
                        )
                      , a39
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A40
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38 , A39 a39 , A40 a40)
            {
                return
                    expression::sequence<
                        type0
                      , A40
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37 , a38 , a39
                        )
                      , a40
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A41
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38 , A39 a39 , A40 a40 , A41 a41)
            {
                return
                    expression::sequence<
                        type0
                      , A41
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37 , a38 , a39 , a40
                        )
                      , a41
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A42
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38 , A39 a39 , A40 a40 , A41 a41 , A42 a42)
            {
                return
                    expression::sequence<
                        type0
                      , A42
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37 , a38 , a39 , a40 , a41
                        )
                      , a42
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A43
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38 , A39 a39 , A40 a40 , A41 a41 , A42 a42 , A43 a43)
            {
                return
                    expression::sequence<
                        type0
                      , A43
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37 , a38 , a39 , a40 , a41 , a42
                        )
                      , a43
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A44
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38 , A39 a39 , A40 a40 , A41 a41 , A42 a42 , A43 a43 , A44 a44)
            {
                return
                    expression::sequence<
                        type0
                      , A44
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37 , a38 , a39 , a40 , a41 , a42 , a43
                        )
                      , a44
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A45
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38 , A39 a39 , A40 a40 , A41 a41 , A42 a42 , A43 a43 , A44 a44 , A45 a45)
            {
                return
                    expression::sequence<
                        type0
                      , A45
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37 , a38 , a39 , a40 , a41 , a42 , a43 , a44
                        )
                      , a45
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A46
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38 , A39 a39 , A40 a40 , A41 a41 , A42 a42 , A43 a43 , A44 a44 , A45 a45 , A46 a46)
            {
                return
                    expression::sequence<
                        type0
                      , A46
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37 , a38 , a39 , a40 , a41 , a42 , a43 , a44 , a45
                        )
                      , a46
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A47
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38 , A39 a39 , A40 a40 , A41 a41 , A42 a42 , A43 a43 , A44 a44 , A45 a45 , A46 a46 , A47 a47)
            {
                return
                    expression::sequence<
                        type0
                      , A47
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37 , a38 , a39 , a40 , a41 , a42 , a43 , a44 , a45 , a46
                        )
                      , a47
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47 , typename A48>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A48
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38 , A39 a39 , A40 a40 , A41 a41 , A42 a42 , A43 a43 , A44 a44 , A45 a45 , A46 a46 , A47 a47 , A48 a48)
            {
                return
                    expression::sequence<
                        type0
                      , A48
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37 , a38 , a39 , a40 , a41 , a42 , a43 , a44 , a45 , a46 , a47
                        )
                      , a48
                    );
            }
        };
    
    
    
    
    
    
    
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47 , typename A48 , typename A49>
        struct make_locals<A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 , A49>
        {
            typedef
                typename make_locals<
                    A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48
                >::type const
                type0;
            typedef
                typename expression::sequence<
                    type0
                  , A49
                >::type
                type;
            static type const make(A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12 , A13 a13 , A14 a14 , A15 a15 , A16 a16 , A17 a17 , A18 a18 , A19 a19 , A20 a20 , A21 a21 , A22 a22 , A23 a23 , A24 a24 , A25 a25 , A26 a26 , A27 a27 , A28 a28 , A29 a29 , A30 a30 , A31 a31 , A32 a32 , A33 a33 , A34 a34 , A35 a35 , A36 a36 , A37 a37 , A38 a38 , A39 a39 , A40 a40 , A41 a41 , A42 a42 , A43 a43 , A44 a44 , A45 a45 , A46 a46 , A47 a47 , A48 a48 , A49 a49)
            {
                return
                    expression::sequence<
                        type0
                      , A49
                    >::make(
                        make_locals<
                            A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48
                        >::make(
                            a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29 , a30 , a31 , a32 , a33 , a34 , a35 , a36 , a37 , a38 , a39 , a40 , a41 , a42 , a43 , a44 , a45 , a46 , a47 , a48
                        )
                      , a49
                    );
            }
        };
