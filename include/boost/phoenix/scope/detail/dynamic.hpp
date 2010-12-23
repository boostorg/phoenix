/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (4, PHOENIX_DYNAMIC_LIMIT,                                              \
    <boost/phoenix/scope/detail/dynamic.hpp>))
#include PHOENIX_ITERATE()

#else

#define PHOENIX_SCOPE_DYNAMIC_MEMBER_I(_, n, __) \
        typedef typename expression::dynamic_member<mpl::int_<n>, self_type>::type BOOST_PP_CAT(member, BOOST_PP_INC(n));
    

//typedef typename make_dynamic_member<n, self_type>::type BOOST_PP_CAT(member, BOOST_PP_INC(n));

#define PHOENIX_SCOPE_DYNAMIC_MEMBER BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_SCOPE_DYNAMIC_MEMBER_I, _)

    template <PHOENIX_typename_A>
    struct dynamic<PHOENIX_A> : noncopyable
    {
        typedef BOOST_PP_CAT(fusion::vector, PHOENIX_ITERATION)<PHOENIX_A> tuple_type;
        typedef dynamic<PHOENIX_A> self_type;
        typedef dynamic_frame<self_type> dynamic_frame_type;

        dynamic()
            : frame(0) {}

        template <int N>
        static
        void //typename make_dynamic_member<N, self_type>::type
        init(self_type& scope)
        {
            //return make_dynamic_member<N, self_type>()(dynamic_member_data<N, self_type>(static_cast<self_type &>(scope)));
        }

        PHOENIX_SCOPE_DYNAMIC_MEMBER

        mutable dynamic_frame_type* frame;
    };

#endif
