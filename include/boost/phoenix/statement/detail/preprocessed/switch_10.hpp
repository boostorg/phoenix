/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
     
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<0> size
              , mpl::false_
            ) const
            {
                
                switch(eval(cond, ctx))
                {
                    
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<0> size
              , mpl::true_
            ) const
            {
                
                mpl::int_<0>
                    idx0;
                switch(eval(cond, ctx))
                {
                    
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx0
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<1> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<1> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<1> size
              , mpl::true_
            ) const
            {
                
                mpl::int_<0>
                    idx0;
                switch(eval(cond, ctx))
                {
                    
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx0
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<2> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<2> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<2> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<2> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<2> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0;
                mpl::int_<1>
                    idx1;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx1
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<3> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<3> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<3> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<3> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<3> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<3> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<3> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1;
                mpl::int_<2>
                    idx2;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx2
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<4> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<4> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<4> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<4> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<4> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<4> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<4> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<4> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<4> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2;
                mpl::int_<3>
                    idx3;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx3
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<5> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<5> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<5> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<5> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<5> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<5> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<5> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<5> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<5> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<5> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<5> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3;
                mpl::int_<4>
                    idx4;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx4
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<6> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<6> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<6> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<6> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<6> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<6> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<6> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<6> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<6> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<6> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<6> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<6> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<6> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4;
                mpl::int_<5>
                    idx5;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx5
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<7> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<7> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<7> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<7> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<7> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<7> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<7> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<7> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<7> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<7> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<7> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<7> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<7> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<7> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<7> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5;
                mpl::int_<6>
                    idx6;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx6
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<8> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<8> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<8> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<8> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<8> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<8> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<8> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<8> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<8> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<8> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<8> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<8> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<8> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<8> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<8> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<8> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<8> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6;
                mpl::int_<7>
                    idx7;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx7
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<9> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<9> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<9> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<9> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<9> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<9> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<9> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<9> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<9> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<9> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<9> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<9> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<9> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<9> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<9> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<9> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<9> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<9> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<9> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7;
                mpl::int_<8>
                    idx8;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx8
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<10> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<10> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<10> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<10> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<10> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<10> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<10> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<10> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<10> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<10> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<10> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<10> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<10> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<10> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<10> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<10> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<10> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<10> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<10> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<10> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<10> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8;
                mpl::int_<9>
                    idx9;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx9
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
