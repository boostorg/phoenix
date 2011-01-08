/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_MEM_OBJ_PTR_HPP
#define PHOENIX_CORE_MEM_OBJ_PTR_HPP

#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/type_traits/remove_reference.hpp>

#include <boost/type_traits/remove_reference.hpp>


namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // mem_obj_ptr
    //
    //         Function to evaluate member object pointers
    //         To be used in bind and operator->*
    //
    ////////////////////////////////////////////////////////////////////////////
    
    /* FIXME
    namespace meta
    {
        template <typename T>
        struct member_type;
        
        template <typename Class, typename MemberType>
        struct member_type<MemberType (Class::*)>
        {
            typedef MemberType type;
        };
        
        template <typename Class, typename MemberType>
        struct member_type<MemberType (Class::*&)>
        {
            typedef MemberType type;
        };
        
        template <typename Class, typename MemberType>
        struct member_type<MemberType (Class::* const&)>
        {
            typedef MemberType type;
        };

        template <typename T> 
        struct object_type;
        
        template <typename T>
        struct object_type<T*>
        {
            typedef T type;
        };
    }

    namespace result_of
    {
        template <typename Env, typename Object, typename MemPtr>
        struct mem_obj_ptr
        {
            typedef typename meta::object_type<
                typename remove_const<
                    typename remove_reference<
                        typename boost::result_of<
                            eval_grammar(Object const&, Env&)
                        >::type
                    >::type
                >::type
            >::type object_type;

            typedef typename meta::member_type<
                typename boost::result_of<
                    eval_grammar(MemPtr const&, Env&)
                >::type
            >::type member_type;

            typedef typename add_reference<
                typename mpl::eval_if<
                    is_const<object_type>
                  , add_const<member_type>
                  , mpl::identity<member_type>
                >::type
            >::type type;
        };
    }

    struct mem_obj_ptr
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename Object, typename MemPtr>
        struct result<This(Env&, Object const&, MemPtr const&)>
            : result_of::mem_obj_ptr<Env, Object, MemPtr>
        {};

        template <typename Env, typename Object, typename MemPtr>
        typename result_of::mem_obj_ptr<Env, Object, MemPtr>::type
        operator()(Env& env, Object const& obj, MemPtr const& ptr) const
        {
            return get_pointer(eval(obj, env))->*eval(ptr, env);
        }
    };

    template <typename Object, typename MemPtr>
    struct make_mem_obj_ptr : compose<mem_obj_ptr, Object, MemPtr> {};

    namespace detail
    {
        template <typename RT, typename MP>
        struct member_variable
        {
            template <typename Sig>
            struct result;

            template <typename This, typename Class>
            struct result<This(Class)>
            {
                typedef typename boost::mpl::if_<
                    boost::is_const<
                        typename boost::remove_pointer<
                            typename boost::remove_reference<Class>::type
                        >::type
                    >
                  , const RT&
                  , RT&
                >::type type;
            };

            member_variable(MP mp)
                : mp(mp) {}

            template <typename Class>
            RT& operator()(Class& obj) const
            {
                return obj.*mp;
            };

            template <typename Class>
            RT& operator()(Class* obj) const
            {
                return obj->*mp;
            };

            template <typename Class>
            RT const& operator()(Class const& obj) const
            {
                return obj.*mp;
            };

            template <typename Class>
            RT const& operator()(Class const* obj) const
            {
                return obj->*mp;
            };

            MP mp;

        };
    }
    */

}}

#endif
