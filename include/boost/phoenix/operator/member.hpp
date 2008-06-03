#ifndef BOOST_PP_IS_ITERATING
    /*=============================================================================
        Copyright (c) 2001-2007 Joel de Guzman
        Copyright (c) 2008      Eric Niebler

        Distributed under the Boost Software License, Version 1.0. (See accompanying
        file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
    ==============================================================================*/
    #ifndef PHOENIX_OPERATOR_MEMBER_HPP_EAN_2008_05_28
    #define PHOENIX_OPERATOR_MEMBER_HPP_EAN_2008_05_28

    #include <boost/ref.hpp>
    #include <boost/preprocessor.hpp>
    #include <boost/type_traits/is_member_function_pointer.hpp>
    #include <boost/phoenix/core/actor.hpp>
    #include <boost/proto/proto.hpp>

    #if !defined(PHOENIX_MEMBER_LIMIT)
    #define PHOENIX_MEMBER_LIMIT BOOST_PP_SUB(PHOENIX_LIMIT, 2)
    #endif

    namespace boost { namespace phoenix
    {
        namespace detail
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename Object, typename MemPtr>
            struct mem_ptr_gen
            {
                mem_ptr_gen(Object const &obj, MemPtr const &ptr)
                  : obj(obj)
                  , ptr(ptr)
                {}

                ////////////////////////////////////////////////////////////////////////////////////
                actor<typename proto::function<MemPtr, Object>::type> const
                operator()() const
                {
                    typedef
                        typename proto::function<MemPtr, Object>::type
                    expr_type;

                    return actor<expr_type>::make(
                        expr_type::make(
                            this->ptr
                          , this->obj
                        )
                    );
                }

                #define M0(Z, N, DATA)                                                              \
                    typename as_actor<BOOST_PP_CAT(A, N) const>::type                               \
                    /**/

                #define M1(Z, N, DATA)                                                              \
                    as_actor<BOOST_PP_CAT(A, N) const>::convert(BOOST_PP_CAT(a, N))                 \
                    /**/

                #define BOOST_PP_ITERATION_PARAMS_1                                                 \
                    (3, (1, PHOENIX_MEMBER_LIMIT, <boost/phoenix/operator/member.hpp>))             \
                    /**/

                #include BOOST_PP_ITERATE()

                #undef M0
                #undef M1

            private:
                Object obj;
                MemPtr ptr;
            };
        }

        namespace actorns_
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            // This operator overload is preferred to Proto's when the second parameter
            // is a member function pointer. If it is a member object pointer, Proto's
            // default handling will do the right thing.
            template<typename Object, typename MemPtr>
            typename enable_if<
                is_member_function_pointer<MemPtr>
              , detail::mem_ptr_gen<actor<Object>, typename proto::terminal<MemPtr>::type> const
            >::type
            operator->*(actor<Object> const &obj, MemPtr ptr)
            {
                typedef typename proto::terminal<MemPtr>::type mem_ptr_type;
                return detail::mem_ptr_gen<actor<Object>, mem_ptr_type>(obj, mem_ptr_type::make(ptr));
            }

        } // namespace actorns_

    }}

    #endif

#else

    #define N BOOST_PP_ITERATION()

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<BOOST_PP_ENUM_PARAMS(N, typename A)>
        actor<
            typename proto::function<
                MemPtr
              , Object
                BOOST_PP_ENUM_TRAILING(N, M0, ~)
            >::type
        > const
        operator()(BOOST_PP_ENUM_BINARY_PARAMS(N, A, const &a)) const
        {
            typedef
                typename proto::function<
                    MemPtr
                  , Object
                    BOOST_PP_ENUM_TRAILING(N, M0, ~)
                >::type
            expr_type;

            return actor<expr_type>::make(
                expr_type::make(
                    this->ptr
                  , this->obj
                    BOOST_PP_ENUM_TRAILING(N, M1, ~)
                )
            );
        }

    #undef N

#endif
