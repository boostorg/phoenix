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
