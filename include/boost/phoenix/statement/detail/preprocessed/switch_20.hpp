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
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<11> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<11> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<11> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<11> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<11> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<11> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<11> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<11> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<11> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<11> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<11> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<11> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<11> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<11> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<11> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<11> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<11> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<11> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<11> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<11> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<11> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<11> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<11> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9;
                mpl::int_<10>
                    idx10;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx10
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
              , mpl::int_<12> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<12> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<12> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<12> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<12> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<12> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<12> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<12> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<12> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<12> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<12> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<12> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<12> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<12> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<12> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<12> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<12> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<12> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<12> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<12> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<12> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<12> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<12> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<12> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<12> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10;
                mpl::int_<11>
                    idx11;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx11
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
              , mpl::int_<13> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<13> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<13> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<13> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<13> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<13> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<13> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<13> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<13> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<13> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<13> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<13> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<13> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<13> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<13> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<13> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<13> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<13> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<13> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<13> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<13> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<13> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<13> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<13> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<13> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<13> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<13> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11;
                mpl::int_<12>
                    idx12;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx12
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
              , mpl::int_<14> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<14> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<14> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<14> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<14> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<14> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<14> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<14> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<14> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<14> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<14> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<14> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<14> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<14> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<14> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<14> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<14> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<14> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<14> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<14> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<14> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<14> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<14> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<14> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<14> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<14> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<14> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<14> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<14> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12;
                mpl::int_<13>
                    idx13;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx13
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
              , mpl::int_<15> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<15> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<15> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<15> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<15> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<15> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<15> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<15> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<15> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<15> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<15> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<15> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<15> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<15> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<15> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<14> , mpl::int_<15> ) >::type case14; typedef typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type case_label14; mpl::int_<14> idx14;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break; case case_label14::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx14, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<15> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<15> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<15> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<15> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<15> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<15> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<15> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<15> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<15> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<15> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<15> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<15> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<15> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<15> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<15> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13;
                mpl::int_<14>
                    idx14;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx14
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
              , mpl::int_<16> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<16> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<16> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<16> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<16> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<16> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<16> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<16> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<16> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<16> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<16> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<16> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<16> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<16> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<16> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<14> , mpl::int_<16> ) >::type case14; typedef typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type case_label14; mpl::int_<14> idx14; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<15> , mpl::int_<16> ) >::type case15; typedef typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type case_label15; mpl::int_<15> idx15;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break; case case_label14::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx14, size ) ) , ctx ); break; case case_label15::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx15, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<16> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<16> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<16> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<16> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<16> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<16> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<16> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<16> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<16> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<16> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<16> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<16> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<16> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<16> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<16> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<14> , mpl::int_<16> ) >::type case14; typedef typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type case_label14; mpl::int_<14> idx14;
                mpl::int_<15>
                    idx15;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break; case case_label14::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx14, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx15
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
              , mpl::int_<17> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<17> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<17> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<17> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<17> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<17> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<17> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<17> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<17> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<17> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<17> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<17> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<17> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<17> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<17> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<14> , mpl::int_<17> ) >::type case14; typedef typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type case_label14; mpl::int_<14> idx14; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<15> , mpl::int_<17> ) >::type case15; typedef typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type case_label15; mpl::int_<15> idx15; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<16> , mpl::int_<17> ) >::type case16; typedef typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type case_label16; mpl::int_<16> idx16;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break; case case_label14::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx14, size ) ) , ctx ); break; case case_label15::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx15, size ) ) , ctx ); break; case case_label16::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx16, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<17> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<17> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<17> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<17> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<17> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<17> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<17> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<17> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<17> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<17> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<17> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<17> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<17> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<17> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<17> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<14> , mpl::int_<17> ) >::type case14; typedef typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type case_label14; mpl::int_<14> idx14; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<15> , mpl::int_<17> ) >::type case15; typedef typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type case_label15; mpl::int_<15> idx15;
                mpl::int_<16>
                    idx16;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break; case case_label14::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx14, size ) ) , ctx ); break; case case_label15::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx15, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx16
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
              , mpl::int_<18> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<18> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<18> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<18> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<18> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<18> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<18> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<18> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<18> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<18> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<18> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<18> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<18> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<18> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<18> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<14> , mpl::int_<18> ) >::type case14; typedef typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type case_label14; mpl::int_<14> idx14; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<15> , mpl::int_<18> ) >::type case15; typedef typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type case_label15; mpl::int_<15> idx15; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<16> , mpl::int_<18> ) >::type case16; typedef typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type case_label16; mpl::int_<16> idx16; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<17> , mpl::int_<18> ) >::type case17; typedef typename proto::result_of::value< typename proto::result_of::child_c< case17 , 0 >::type >::type case_label17; mpl::int_<17> idx17;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break; case case_label14::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx14, size ) ) , ctx ); break; case case_label15::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx15, size ) ) , ctx ); break; case case_label16::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx16, size ) ) , ctx ); break; case case_label17::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx17, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<18> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<18> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<18> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<18> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<18> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<18> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<18> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<18> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<18> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<18> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<18> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<18> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<18> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<18> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<18> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<14> , mpl::int_<18> ) >::type case14; typedef typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type case_label14; mpl::int_<14> idx14; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<15> , mpl::int_<18> ) >::type case15; typedef typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type case_label15; mpl::int_<15> idx15; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<16> , mpl::int_<18> ) >::type case16; typedef typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type case_label16; mpl::int_<16> idx16;
                mpl::int_<17>
                    idx17;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break; case case_label14::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx14, size ) ) , ctx ); break; case case_label15::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx15, size ) ) , ctx ); break; case case_label16::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx16, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx17
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
              , mpl::int_<19> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<19> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<19> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<19> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<19> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<19> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<19> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<19> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<19> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<19> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<19> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<19> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<19> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<19> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<19> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<14> , mpl::int_<19> ) >::type case14; typedef typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type case_label14; mpl::int_<14> idx14; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<15> , mpl::int_<19> ) >::type case15; typedef typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type case_label15; mpl::int_<15> idx15; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<16> , mpl::int_<19> ) >::type case16; typedef typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type case_label16; mpl::int_<16> idx16; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<17> , mpl::int_<19> ) >::type case17; typedef typename proto::result_of::value< typename proto::result_of::child_c< case17 , 0 >::type >::type case_label17; mpl::int_<17> idx17; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<18> , mpl::int_<19> ) >::type case18; typedef typename proto::result_of::value< typename proto::result_of::child_c< case18 , 0 >::type >::type case_label18; mpl::int_<18> idx18;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break; case case_label14::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx14, size ) ) , ctx ); break; case case_label15::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx15, size ) ) , ctx ); break; case case_label16::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx16, size ) ) , ctx ); break; case case_label17::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx17, size ) ) , ctx ); break; case case_label18::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx18, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<19> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<19> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<19> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<19> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<19> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<19> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<19> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<19> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<19> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<19> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<19> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<19> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<19> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<19> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<19> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<14> , mpl::int_<19> ) >::type case14; typedef typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type case_label14; mpl::int_<14> idx14; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<15> , mpl::int_<19> ) >::type case15; typedef typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type case_label15; mpl::int_<15> idx15; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<16> , mpl::int_<19> ) >::type case16; typedef typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type case_label16; mpl::int_<16> idx16; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<17> , mpl::int_<19> ) >::type case17; typedef typename proto::result_of::value< typename proto::result_of::child_c< case17 , 0 >::type >::type case_label17; mpl::int_<17> idx17;
                mpl::int_<18>
                    idx18;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break; case case_label14::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx14, size ) ) , ctx ); break; case case_label15::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx15, size ) ) , ctx ); break; case case_label16::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx16, size ) ) , ctx ); break; case case_label17::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx17, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx18
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
              , mpl::int_<20> size
              , mpl::false_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<20> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<20> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<20> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<20> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<20> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<20> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<20> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<20> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<20> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<20> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<20> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<20> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<20> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<20> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<14> , mpl::int_<20> ) >::type case14; typedef typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type case_label14; mpl::int_<14> idx14; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<15> , mpl::int_<20> ) >::type case15; typedef typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type case_label15; mpl::int_<15> idx15; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<16> , mpl::int_<20> ) >::type case16; typedef typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type case_label16; mpl::int_<16> idx16; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<17> , mpl::int_<20> ) >::type case17; typedef typename proto::result_of::value< typename proto::result_of::child_c< case17 , 0 >::type >::type case_label17; mpl::int_<17> idx17; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<18> , mpl::int_<20> ) >::type case18; typedef typename proto::result_of::value< typename proto::result_of::child_c< case18 , 0 >::type >::type case_label18; mpl::int_<18> idx18; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<19> , mpl::int_<20> ) >::type case19; typedef typename proto::result_of::value< typename proto::result_of::child_c< case19 , 0 >::type >::type case_label19; mpl::int_<19> idx19;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break; case case_label14::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx14, size ) ) , ctx ); break; case case_label15::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx15, size ) ) , ctx ); break; case case_label16::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx16, size ) ) , ctx ); break; case case_label17::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx17, size ) ) , ctx ); break; case case_label18::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx18, size ) ) , ctx ); break; case case_label19::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx19, size ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<20> size
              , mpl::true_
            ) const
            {
                typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<0> , mpl::int_<20> ) >::type case0; typedef typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type case_label0; mpl::int_<0> idx0; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<1> , mpl::int_<20> ) >::type case1; typedef typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type case_label1; mpl::int_<1> idx1; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<2> , mpl::int_<20> ) >::type case2; typedef typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type case_label2; mpl::int_<2> idx2; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<3> , mpl::int_<20> ) >::type case3; typedef typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type case_label3; mpl::int_<3> idx3; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<4> , mpl::int_<20> ) >::type case4; typedef typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type case_label4; mpl::int_<4> idx4; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<5> , mpl::int_<20> ) >::type case5; typedef typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type case_label5; mpl::int_<5> idx5; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<6> , mpl::int_<20> ) >::type case6; typedef typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type case_label6; mpl::int_<6> idx6; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<7> , mpl::int_<20> ) >::type case7; typedef typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type case_label7; mpl::int_<7> idx7; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<8> , mpl::int_<20> ) >::type case8; typedef typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type case_label8; mpl::int_<8> idx8; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<9> , mpl::int_<20> ) >::type case9; typedef typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type case_label9; mpl::int_<9> idx9; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<10> , mpl::int_<20> ) >::type case10; typedef typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type case_label10; mpl::int_<10> idx10; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<11> , mpl::int_<20> ) >::type case11; typedef typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type case_label11; mpl::int_<11> idx11; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<12> , mpl::int_<20> ) >::type case12; typedef typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type case_label12; mpl::int_<12> idx12; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<13> , mpl::int_<20> ) >::type case13; typedef typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type case_label13; mpl::int_<13> idx13; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<14> , mpl::int_<20> ) >::type case14; typedef typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type case_label14; mpl::int_<14> idx14; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<15> , mpl::int_<20> ) >::type case15; typedef typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type case_label15; mpl::int_<15> idx15; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<16> , mpl::int_<20> ) >::type case16; typedef typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type case_label16; mpl::int_<16> idx16; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<17> , mpl::int_<20> ) >::type case17; typedef typename proto::result_of::value< typename proto::result_of::child_c< case17 , 0 >::type >::type case_label17; mpl::int_<17> idx17; typedef typename boost::result_of< detail::switch_grammar( Cases , mpl::int_<18> , mpl::int_<20> ) >::type case18; typedef typename proto::result_of::value< typename proto::result_of::child_c< case18 , 0 >::type >::type case_label18; mpl::int_<18> idx18;
                mpl::int_<19>
                    idx19;
                switch(eval(cond, ctx))
                {
                    case case_label0::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx0, size ) ) , ctx ); break; case case_label1::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx1, size ) ) , ctx ); break; case case_label2::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx2, size ) ) , ctx ); break; case case_label3::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx3, size ) ) , ctx ); break; case case_label4::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx4, size ) ) , ctx ); break; case case_label5::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx5, size ) ) , ctx ); break; case case_label6::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx6, size ) ) , ctx ); break; case case_label7::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx7, size ) ) , ctx ); break; case case_label8::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx8, size ) ) , ctx ); break; case case_label9::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx9, size ) ) , ctx ); break; case case_label10::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx10, size ) ) , ctx ); break; case case_label11::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx11, size ) ) , ctx ); break; case case_label12::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx12, size ) ) , ctx ); break; case case_label13::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx13, size ) ) , ctx ); break; case case_label14::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx14, size ) ) , ctx ); break; case case_label15::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx15, size ) ) , ctx ); break; case case_label16::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx16, size ) ) , ctx ); break; case case_label17::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx17, size ) ) , ctx ); break; case case_label18::value : eval( proto::child_c<1>( detail::switch_grammar()( cases, idx18, size ) ) , ctx ); break;
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , idx19
                                  , size
                                )
                            )
                            , ctx
                        );
                }
            }
