/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0>
        typename boost::enable_if<
            proto::matches<
                A0
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); }
        }
        template <typename Env, typename Try, typename A0>
        typename boost::disable_if<
            proto::matches<
                A0
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a0
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1>
        typename boost::enable_if<
            proto::matches<
                A1
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1>
        typename boost::disable_if<
            proto::matches<
                A1
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a1
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2>
        typename boost::enable_if<
            proto::matches<
                A2
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2>
        typename boost::disable_if<
            proto::matches<
                A2
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a2
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3>
        typename boost::enable_if<
            proto::matches<
                A3
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3>
        typename boost::disable_if<
            proto::matches<
                A3
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a3
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        typename boost::enable_if<
            proto::matches<
                A4
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
        typename boost::disable_if<
            proto::matches<
                A4
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a4
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        typename boost::enable_if<
            proto::matches<
                A5
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
        typename boost::disable_if<
            proto::matches<
                A5
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a5
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        typename boost::enable_if<
            proto::matches<
                A6
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
        typename boost::disable_if<
            proto::matches<
                A6
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a6
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        typename boost::enable_if<
            proto::matches<
                A7
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
        typename boost::disable_if<
            proto::matches<
                A7
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a7
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        typename boost::enable_if<
            proto::matches<
                A8
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
        typename boost::disable_if<
            proto::matches<
                A8
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a8
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        typename boost::enable_if<
            proto::matches<
                A9
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
        typename boost::disable_if<
            proto::matches<
                A9
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a9
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10>
        typename boost::enable_if<
            proto::matches<
                A10
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10>
        typename boost::disable_if<
            proto::matches<
                A10
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a10
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11>
        typename boost::enable_if<
            proto::matches<
                A11
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11>
        typename boost::disable_if<
            proto::matches<
                A11
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a11
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12>
        typename boost::enable_if<
            proto::matches<
                A12
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12>
        typename boost::disable_if<
            proto::matches<
                A12
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a12
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13>
        typename boost::enable_if<
            proto::matches<
                A13
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13>
        typename boost::disable_if<
            proto::matches<
                A13
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a13
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14>
        typename boost::enable_if<
            proto::matches<
                A14
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14>
        typename boost::disable_if<
            proto::matches<
                A14
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a14
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15>
        typename boost::enable_if<
            proto::matches<
                A15
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15>
        typename boost::disable_if<
            proto::matches<
                A15
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a15
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16>
        typename boost::enable_if<
            proto::matches<
                A16
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16>
        typename boost::disable_if<
            proto::matches<
                A16
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a16
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17>
        typename boost::enable_if<
            proto::matches<
                A17
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17>
        typename boost::disable_if<
            proto::matches<
                A17
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a17
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18>
        typename boost::enable_if<
            proto::matches<
                A18
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18>
        typename boost::disable_if<
            proto::matches<
                A18
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a18
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19>
        typename boost::enable_if<
            proto::matches<
                A19
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19>
        typename boost::disable_if<
            proto::matches<
                A19
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a19
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20>
        typename boost::enable_if<
            proto::matches<
                A20
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20>
        typename boost::disable_if<
            proto::matches<
                A20
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a20
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21>
        typename boost::enable_if<
            proto::matches<
                A21
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21>
        typename boost::disable_if<
            proto::matches<
                A21
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a21
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22>
        typename boost::enable_if<
            proto::matches<
                A22
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22>
        typename boost::disable_if<
            proto::matches<
                A22
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a22
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23>
        typename boost::enable_if<
            proto::matches<
                A23
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23>
        typename boost::disable_if<
            proto::matches<
                A23
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a23
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24>
        typename boost::enable_if<
            proto::matches<
                A24
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A24 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a24), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24>
        typename boost::disable_if<
            proto::matches<
                A24
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a24
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25>
        typename boost::enable_if<
            proto::matches<
                A25
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A24 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a24), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A25 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a25), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25>
        typename boost::disable_if<
            proto::matches<
                A25
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A24 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a24), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a25
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26>
        typename boost::enable_if<
            proto::matches<
                A26
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A24 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a24), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A25 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a25), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A26 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a26), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26>
        typename boost::disable_if<
            proto::matches<
                A26
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A24 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a24), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A25 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a25), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a26
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27>
        typename boost::enable_if<
            proto::matches<
                A27
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A24 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a24), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A25 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a25), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A26 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a26), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A27 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a27), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27>
        typename boost::disable_if<
            proto::matches<
                A27
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A24 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a24), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A25 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a25), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A26 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a26), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a27
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28>
        typename boost::enable_if<
            proto::matches<
                A28
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A24 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a24), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A25 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a25), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A26 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a26), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A27 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a27), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A28 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a28), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28>
        typename boost::disable_if<
            proto::matches<
                A28
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A24 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a24), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A25 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a25), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A26 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a26), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A27 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a27), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a28
                    )
                  , env);
            }
        }
    
    
    
    
    
    
    
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29>
        typename boost::enable_if<
            proto::matches<
                A29
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A24 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a24), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A25 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a25), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A26 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a26), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A27 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a27), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A28 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a28), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A29 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a29), env); }
        }
        template <typename Env, typename Try, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29>
        typename boost::disable_if<
            proto::matches<
                A29
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            catch( typename proto::result_of::value< typename proto::result_of::child_c< A0 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a0), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A1 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a1), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A2 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a2), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A3 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a3), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A4 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a4), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A5 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a5), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A6 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a6), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A7 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a7), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A8 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a8), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A9 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a9), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A10 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a10), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A11 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a11), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A12 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a12), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A13 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a13), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A14 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a14), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A15 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a15), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A16 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a16), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A17 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a17), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A18 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a18), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A19 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a19), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A20 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a20), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A21 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a21), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A22 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a22), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A23 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a23), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A24 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a24), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A25 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a25), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A26 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a26), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A27 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a27), env); } catch( typename proto::result_of::value< typename proto::result_of::child_c< A28 , 0 >::type >::type::type & ) { eval(proto::child_c<1>(a28), env); }
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        a29
                    )
                  , env);
            }
        }
