/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2004 Daniel Wallin
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_DYNAMIC_HPP
#define PHOENIX_SCOPE_DYNAMIC_HPP

#include <boost/assert.hpp>
#include <boost/noncopyable.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>

namespace boost { namespace phoenix
{

    template <typename DynamicScope>
    struct dynamic_frame : noncopyable
    {
        typedef typename DynamicScope::tuple_type tuple_type;

        dynamic_frame(DynamicScope const& scope)
            : tuple()
            , save(scope.frame)
            , scope(scope)
        {
            scope.frame = this;
        }

        template <typename Tuple>
        dynamic_frame(DynamicScope const& scope, Tuple const& init)
            : tuple(init)
            , save(scope.frame)
            , scope(scope)
        {
            scope.frame = this;
        }

        ~dynamic_frame()
        {
            scope.frame = save;
        }

        tuple_type& data() { return tuple; }
        tuple_type const& data() const { return tuple; }

        private:
            tuple_type tuple;
            dynamic_frame *save;
            DynamicScope const& scope;
    };

    namespace result_of
    {
        template <typename Env, typename Data>
        struct dynamic_member
        {
            typedef typename proto::result_of::value<Data>::type::result_type type;
        };
    }

    struct dynamic_member
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename Data>
        struct result<This(Env&, Data)>
            : result_of::dynamic_member<Env, typename remove_reference<Data>::type >
        {};

        template <typename This, typename Env, typename Data>
        struct result<This(Env&, Data const&)>
            : result_of::dynamic_member<Env, Data>
        {};

        template <typename Env, typename Data>
        typename result_of::dynamic_member<Env, Data>::type
        operator()(Env& env, Data const& data)
        {
            return proto::value(data)();
        }
    };

    template <int N, typename DynamicScope>
    struct dynamic_member_data
    {

        typedef typename fusion::result_of::at_c<typename DynamicScope::tuple_type, N>::type result_type;

        dynamic_member_data(DynamicScope const& scope) : scope(scope) {};

        result_type
        operator()() const
        {
            BOOST_ASSERT(scope.frame != 0);
            return fusion::at_c<N>(scope.frame->data());
        }

        DynamicScope const& scope;
    };

    template <int N, typename DynamicScope>
    struct make_dynamic_member: compose<dynamic_member, dynamic_member_data<N, DynamicScope> > {};

    template <PHOENIX_typename_A_void(PHOENIX_DYNAMIC_LIMIT), typename Dummy = void>
    struct dynamic;
    
    template <typename A0>
    struct dynamic<A0> : noncopyable
    {
        typedef fusion::vector1<A0> tuple_type;
        typedef dynamic<A0> self_type;
        typedef dynamic_frame<self_type> dynamic_frame_type;

        dynamic()
            : frame(0) {}

        template <int N>
        static typename make_dynamic_member<N, self_type>::type
        init(self_type& scope)
        {
            return make_dynamic_member<N, self_type>()(dynamic_member_data<N, self_type>(static_cast<self_type &>(scope)));
        }

        typedef typename make_dynamic_member<0, self_type>::type member1;

        mutable dynamic_frame_type* frame;
    };
    
    template <typename A0, typename A1>
    struct dynamic<A0, A1> : noncopyable
    {
        typedef fusion::vector2<A0, A1> tuple_type;
        typedef dynamic<A0, A1> self_type;
        typedef dynamic_frame<self_type> dynamic_frame_type;

        dynamic()
            : frame(0) {}

        template <int N>
        static typename make_dynamic_member<N, self_type>::type
        init(self_type& scope)
        {
            return make_dynamic_member<N, self_type>()(dynamic_member_data<N, self_type>(static_cast<self_type &>(scope)));
        }

        typedef typename make_dynamic_member<0, self_type>::type member1;
        typedef typename make_dynamic_member<1, self_type>::type member2;

        mutable dynamic_frame_type* frame;
    };
    
    template <typename A0, typename A1, typename A2>
    struct dynamic<A0, A1, A2> : noncopyable
    {
        typedef fusion::vector3<A0, A1, A2> tuple_type;
        typedef dynamic<A0, A1, A2> self_type;
        typedef dynamic_frame<self_type> dynamic_frame_type;

        dynamic()
            : frame(0) {}

        template <int N>
        static typename make_dynamic_member<N, self_type>::type
        init(self_type& scope)
        {
            return make_dynamic_member<N, self_type>()(dynamic_member_data<N, self_type>(static_cast<self_type &>(scope)));
        }

        typedef typename make_dynamic_member<0, self_type>::type member1;
        typedef typename make_dynamic_member<1, self_type>::type member2;
        typedef typename make_dynamic_member<2, self_type>::type member3;

        mutable dynamic_frame_type* frame;
    };

    // Bring in the rest ...
    #include <boost/phoenix/scope/detail/dynamic.hpp>
}}

#endif
