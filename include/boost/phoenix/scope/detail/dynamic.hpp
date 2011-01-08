/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !PHOENIX_IS_ITERATING

#define PHOENIX_SCOPE_DYNAMIC_MEMBER(_, N, __)                                  \
        typedef                                                                 \
            typename expression::dynamic_member<                                \
                mpl::int_<N>                                                    \
              , self_type *                                                     \
            >::type                                                             \
            BOOST_PP_CAT(member, BOOST_PP_INC(N));                              \
/**/

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_DYNAMIC_LIMIT,                                              \
    <boost/phoenix/scope/detail/dynamic.hpp>))
#include PHOENIX_ITERATE()

#undef PHOENIX_SCOPE_DYNAMIC_MEMBER

#else

    template <PHOENIX_typename_A>
    struct dynamic<PHOENIX_A> : noncopyable
    {
        typedef
            BOOST_PP_CAT(fusion::vector, PHOENIX_ITERATION)<PHOENIX_A>
            tuple_type;
        typedef
            dynamic<PHOENIX_A>
            self_type;
        typedef
            dynamic_frame<self_type>
            dynamic_frame_type;

        dynamic()
            : frame(0) {}

        template <int N>
        static
        typename expression::dynamic_member<mpl::int_<N>, self_type *>::type
        init(self_type * scope)
        {
            return
                expression::
                    dynamic_member<mpl::int_<N>, self_type *>::
                        make(mpl::int_<N>(), scope);
        }

        BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_SCOPE_DYNAMIC_MEMBER, _)

        mutable dynamic_frame_type* frame;
    };

#endif
