/*=============================================================================
    Copyright (c) 2004 Angus Leeming
    Copyright (c) 2004 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STL_CONTAINER_CONTAINER_HPP
#define PHOENIX_STL_CONTAINER_CONTAINER_HPP

#include <boost/config.hpp>
#include <boost/detail/workaround.hpp>
#include <boost/phoenix/core/limits.hpp>

#if (PHOENIX_LIMIT < 5)
# error "PHOENIX_LIMIT is set too low"
#endif

#include <boost/phoenix/stl/container/detail/container.hpp>
#include <boost/phoenix/function/function.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/or.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace boost { namespace phoenix
{
///////////////////////////////////////////////////////////////////////////////
//
//  STL container member functions
//
//      Lazy functions for STL container member functions
//
//      These functions provide a mechanism for the lazy evaluation of the
//      public member functions of the STL containers. For an overview of
//      what is meant by 'lazy evaluation', see the comments in operators.hpp
//      and functions.hpp.
//
//      Lazy functions are provided for all of the member functions of the
//      following containers:
//
//      deque · list · map · multimap · vector.
//
//      Indeed, should *your* class have member functions with the same names
//      and signatures as those listed below, then it will automatically be
//      supported. To summarize, lazy functions are provided for member
//      functions:
//
//          assign · at · back · begin · capacity · clear · empty · end ·
//          erase · front · get_allocator · insert · key_comp · max_size ·
//          pop_back · pop_front · push_back · push_front · rbegin · rend ·
//          reserve · resize . size · splice · value_comp.
//
//      The lazy functions' names are the same as the corresponding member
//      function. Sample usage:
//
//      "Normal" version                 "Lazy" version
//      ----------------                 --------------
//      my_vector.at(5)                  phoenix::at(arg1, 5)
//      my_list.size()                   phoenix::size(arg1)
//      my_vector1.swap(my_vector2)      phoenix::swap(arg1, arg2)
//
//      Notice that member functions with names that clash with a
//      function in stl algorithms are absent. This will be provided
//      in Phoenix's algorithm module.
//
//      No support is provided here for lazy versions of operator+=,
//      operator[] etc. Such operators are not specific to STL containers and
//      lazy versions can therefore be found in operators.hpp.
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Lazy member function implementaions.
//
//      The structs below provide the guts of the implementation. Thereafter,
//      the corresponding lazy function itself is simply:
//
//          function<stl::assign> const assign = {};
//
//      The structs provide a nested "result" class template whose
//      "type" typedef enables the lazy function to ascertain the type
//      to be returned when it is invoked.
//
//      They also provide operator() member functions with signatures
//      corresponding to those of the underlying member function of
//      the STL container.
//
///////////////////////////////////////////////////////////////////////////////
    namespace stl
    {
        struct assign
        {
            template<typename Sig>
            struct result;
            
            template <typename This, typename C, typename Arg1>
            struct result<This(C, Arg1)>
            {
                typedef typename add_reference<C>::type type;
            };

            template <typename This, typename C, typename Arg1, typename Arg2>
            struct result<This(C, Arg1, Arg2)>
            {
                typedef typename add_reference<C>::type type;
            };

            template <typename This, typename C, typename Arg1, typename Arg2, typename Arg3>
            struct result<This(C, Arg1, Arg2, Arg3)>
            {
                typedef typename add_reference<C>::type type;
            };

            template <typename C, typename Arg1>
            C& operator()(C& c, Arg1 const& arg1) const
            {
                c.assign(arg1);
                return c;
            }

            template <typename C, typename Arg1, typename Arg2>
            C& operator()(C& c, Arg1 const& arg1, Arg2 const& arg2) const
            {
                c.assign(arg1, arg2);
                return c;
            }

            template <typename C, typename Arg1, typename Arg2, typename Arg3>
            C& operator()(C& c, Arg1 const& arg1, Arg2 const& arg2, Arg3 const& arg3) const
            {
                return c.assign(arg1, arg2, arg3);
            }
        };

        struct at
        {
            template <typename Sig>
            struct result;
            
            template <typename This, typename C, typename Index>
            struct result<This(C, Index)>
            {
                typedef
                    typename const_qualified_reference_of<
                        typename remove_reference<C>::type
                    >::type
                type;
            };

            template <typename C, typename Index>
            typename const_qualified_reference_of<C>::type
            operator()(C& c, Index const& i) const
            {
                return c.at(i);
            }
        };

        struct front
        {
            template <typename Sig>
            struct result;
            
            template <typename This, typename C>
            struct result<This(C)>
            {
                typedef
                    typename const_qualified_reference_of<
                        typename remove_reference<C>::type
                    >::type
                type;
            };

            template <typename C>
            typename const_qualified_reference_of<C>::type
            operator()(C& c) const
            {
                return c.front();
            }
        };

        struct back
        {
            template <typename Sig>
            struct result;
            
            template <typename This, typename C>
            struct result<This(C)>
            {
                typedef
                    typename const_qualified_reference_of<
                        typename remove_reference<C>::type
                    >::type
                type;
            };

            template <typename C>
            typename const_qualified_reference_of<C>::type
            operator()(C& c) const
            {
                return c.back();
            }
        };

        struct begin
        {
            template <typename Sig>
            struct result;
            
            template <typename This, typename C>
            struct result<This(C)>
            {
                typedef
                    typename const_qualified_iterator_of<
                        typename remove_reference<C>::type
                    >::type
                type;
            };

            template <typename C>
            typename const_qualified_iterator_of<C>::type
            operator()(C& c) const
            {
                return c.begin();
            }
        };

        struct end
        {
            template <typename Sig>
            struct result;
            
            template <typename This, typename C>
            struct result<This(C)>
            {
                typedef
                    typename const_qualified_iterator_of<
                        typename remove_reference<C>::type
                    >::type
                type;
            };

            template <typename C>
            typename const_qualified_iterator_of<C>::type
            operator()(C& c) const
            {
                return c.end();
            }
        };

        struct capacity
        {
            template <typename Sig>
            struct result;
            
            template <typename This, typename C>
            struct result<This(C)>
            {
                typedef
                    typename size_type_of<
                        typename remove_reference<C>::type
                    >::type
                type;
            };

            template <typename C>
            typename size_type_of<C>::type
            operator()(C const& c) const
            {
                return c.capacity();
            }
        };

        struct clear
        {
            typedef void result_type;

            template <typename C>
            void operator()(C& c) const
            {
                return c.clear();
            }
        };

        struct empty
        {
            typedef bool result_type;

            template <typename C>
            bool operator()(C const& c) const
            {
                return c.empty();
            }
        };

        struct erase
        {
            //  This mouthful can differentiate between the generic erase
            //  functions (Container == std::deque, std::list, std::vector) and
            //  that specific to the two map-types, std::map and std::multimap.
            //
            //  where C is a std::deque, std::list, std::vector:
            //
            //      1) iterator C::erase(iterator where);
            //      2) iterator C::erase(iterator first, iterator last);
            //
            //  where M is a std::map or std::multimap:
            //
            //      3) size_type M::erase(const Key& keyval);
            //      4) void M::erase(iterator where);
            //      5) void M::erase(iterator first, iterator last);
            template<typename Sig>
            struct result;
            
            template <typename This, typename C, typename Arg1>
            struct result<This(C, Arg1)>
            {
                //  BOOST_MSVC #if branch here in map_erase_result non-
                //  standard behavior. The return type should be void but
                //  VC7.1 prefers to return iterator_of<C>. As a result,
                //  VC7.1 complains of error C2562:
                //  boost::phoenix::stl::erase::operator() 'void' function
                //  returning a value. Oh well... :*
                
                typedef typename remove_reference<C>::type container;
                typedef typename remove_const<typename remove_reference<Arg1>::type>::type arg1;

                typedef
                    boost::mpl::eval_if<
                        boost::is_same<arg1, typename iterator_of<container>::type>
#if BOOST_WORKAROUND(BOOST_DINKUMWARE_STDLIB, <= 313) || (0 == _HAS_STRICT_CONFORMANCE)
                      , iterator_of<container>
#else
                      , boost::mpl::identity<void>
#endif
                      , size_type_of<container>
                    >
                map_erase_result;

                typedef typename
                    boost::mpl::eval_if<
                        has_mapped_type<container>
                      , map_erase_result
                      , iterator_of<container>
                    >::type
                type;
            };

            template <typename This, typename C, typename Arg1, typename Arg2>
            struct result<This(C, Arg1, Arg2)>
              : result<This(C, Arg1)>
            {};

            template <typename C, typename Arg1>
            typename result<erase(C, Arg1)>::type
            operator()(C& c, Arg1 const& arg1) const
            {
                return c.erase(arg1);
            }

            template <typename C, typename Arg1, typename Arg2>
            typename result<erase(C, Arg1, Arg2)>::type
            operator()(C& c, Arg1 const& arg1, Arg2 const& arg2) const
            {
                return c.erase(arg1, arg2);
            }
        };

        struct get_allocator
        {
            template<typename Sig>
            struct result;
            
            template <typename This, typename C>
            struct result<This(C)>
            {
        	    typedef
        	        typename allocator_type_of<
        	            typename remove_reference<C>::type
        	        >::type
        	    type;
            };

            template <typename C>
            typename allocator_type_of<C>::type
            operator()(C const& c) const
            {
                return c.get_allocator();
            }
        };

        struct insert
        {
            //  This mouthful can differentiate between the generic insert
            //  functions (Container == deque, list, vector) and those
            //  specific to the two map-types, std::map and std::multimap.
            //
            //  where C is a std::deque, std::list, std::vector:
            //
            //      1) iterator C::insert(iterator where, value_type value);
            //      2) void C::insert(
            //          iterator where, size_type count, value_type value);
            //      3) template <typename Iter>
            //         void C::insert(iterator where, Iter first, Iter last);
            //
            //  where M is a std::map and MM is a std::multimap:
            //
            //      4) pair<iterator, bool> M::insert(value_type const&);
            //      5) iterator MM::insert(value_type const&);
            //
            //  where M is a std::map or std::multimap:
            //
            //      6) template <typename Iter>
            //         void M::insert(Iter first, Iter last);
            
            template<typename Sig>
            struct result;

            template <typename This, typename C, typename Arg1>
            struct result<This(C, Arg1)>
            {
                typedef typename remove_const<typename remove_reference<C>::type>::type container;
                typedef typename remove_const<typename remove_reference<Arg1>::type>::type arg1;
                
                struct pair_iterator_bool
                {
                    typedef std::pair<typename container::iterator, bool> type;
                };

                typedef
                    typename boost::mpl::eval_if<
                        map_insert_returns_pair<container>
                      , pair_iterator_bool
                      , iterator_of<container>
                    >::type
                type;
            };

            template <typename This, typename C, typename Arg1, typename Arg2>
            struct result<This(C, Arg1, Arg2)>
            {
                typedef typename remove_reference<C>::type container;
                typedef typename remove_const<typename remove_reference<Arg1>::type>::type arg1;
                typedef typename remove_const<typename remove_reference<Arg2>::type>::type arg2;
                
                typedef typename
                    boost::mpl::eval_if<
                        boost::is_same<arg1, arg2>
                      , boost::mpl::identity<void>
                      , iterator_of<container>
                    >::type
                type;
            };

            template <typename This, typename C, typename Arg1, typename Arg2, typename Arg3>
            struct result<This(C, Arg1, Arg2, Arg3)>
            {
                typedef void type;
            };

            template <typename C, typename Arg1>
            typename result<insert(C, Arg1)>::type
            operator()(C& c, Arg1 const& arg1) const
            {
        	    return c.insert(arg1);
            }

            template <typename C, typename Arg1, typename Arg2>
            typename result<insert(C, Arg1, Arg2)>::type
            operator()(C& c, Arg1 const& arg1, Arg2 const& arg2) const
            {
                return c.insert(arg1, arg2);
            }

            template <typename C, typename Arg1, typename Arg2, typename Arg3>
            typename result<insert(C, Arg1, Arg2, Arg3)>::type
            operator()(C& c, Arg1 const& arg1, Arg2 const& arg2, Arg3 const& arg3) const
            {
                return c.insert(arg1, arg2, arg3);
            }
        };

        struct key_comp
        {
            template <typename C>
            struct result;
            
            template <typename This, typename C>
            struct result<This(C)>
            {
                typedef
                    typename key_compare_of<
                        typename remove_reference<C>::type
                    >::type
                type;
            };

            template <typename C>
            typename key_compare_of<C>::type
            operator()(C const& c) const
            {
                return c.key_comp();
            }
        };

        struct max_size
        {
            template <typename C>
            struct result;
            
            template <typename This, typename C>
            struct result<This(C)>
            {
                typedef
                    typename size_type_of<
                        typename remove_reference<C>::type
                    >::type
                type;
            };

            template <typename C>
            typename size_type_of<C>::type
            operator()(C const& c) const
            {
                return c.max_size();
            }
        };

        struct pop_back
        {
            typedef void result_type;

            template <typename C>
            void operator()(C& c) const
            {
                return c.pop_back();
            }
        };

        struct pop_front
        {
            typedef void result_type;

            template <typename C>
            void operator()(C& c) const
            {
                return c.pop_front();
            }
        };

        struct push_back
        {
            typedef void result_type;

            template <typename C, typename Arg>
            void operator()(C& c, Arg const& data) const
            {
                return c.push_back(data);
            }
        };

        struct push_front
        {
            typedef void result_type;

            template <typename C, typename Arg>
            void operator()(C& c, Arg const& data) const
            {
                return c.push_front(data);
            }
        };

        struct rbegin
        {
            template <typename Sig>
            struct result;
            
            template <typename This, typename C>
            struct result<This(C)>
            {
                typedef
                    typename const_qualified_reverse_iterator_of<
                        typename remove_reference<C>::type
                    >::type
                type;
            };

            template <typename C>
            typename const_qualified_reverse_iterator_of<C>::type
            operator()(C& c) const
            {
                return c.rbegin();
            }
        };

        struct rend
        {
            template <typename Sig>
            struct result;
            
            template <typename This, typename C>
            struct result<This(C)>
            {
                typedef
                    typename const_qualified_reverse_iterator_of<
                        typename remove_reference<C>::type
                    >::type
                type;
            };

            template <typename C>
            typename const_qualified_reverse_iterator_of<C>::type
            operator()(C& c) const
            {
                return c.rend();
            }
        };

        struct reserve
        {
            typedef void result_type;

            template <typename C, typename Arg>
            void operator()(C& c, Arg const& count) const
            {
                return c.reserve(count);
            }
        };

        struct resize
        {
            typedef void result_type;

            template <typename C, typename Arg1>
            void operator()(C& c, Arg1 const& arg1) const
            {
                return c.resize(arg1);
            }

            template <typename C, typename Arg1, typename Arg2>
            void operator()(C& c, Arg1 const& arg1, Arg2 const& arg2) const
            {
                return c.resize(arg1, arg2);
            }
        };

        struct size
        {
            template <typename Sig>
            struct result;
            
            template <typename This, typename C>
            struct result<This(C)>
            {
                typedef
                    typename size_type_of<
                        typename remove_reference<C>::type
                    >::type
                type;
            };

            template <typename C>
            typename size_type_of<C>::type
            operator()(C const& c) const
            {
                return c.size();
            }
        };

    struct splice
    {
        typedef void result_type;

        template <typename C, typename Arg1, typename Arg2>
        void operator()(C& c, Arg1 const& arg1, Arg2& arg2) const
        {
            c.splice(arg1, arg2);
        }

        template <typename C, typename Arg1, typename Arg2, typename Arg3>
        void operator()(C& c, Arg1 const& arg1, Arg2& arg2, Arg3 const& arg3) const
        {
            c.splice(arg1, arg2, arg3);
        }

        template <typename C, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
        void operator()(C& c, Arg1 const& arg1, Arg2& arg2, Arg3 const& arg3, Arg4 const& arg4) const
        {
            c.splice(arg1, arg2, arg3, arg4);
        }
    };

    struct value_comp
    {
        template <typename Sig>
        struct result;
        
        template <typename This, typename C>
        struct result<This(C)>
        {
            typedef
                typename value_compare_of<
                    typename remove_reference<C>::type
                >::type
            type;
        };

        template <typename C>
        typename value_compare_of<C>::type
        operator()(C const& c) const
        {
            return c.value_comp();
        }
    };

} // namespace stl

///////////////////////////////////////////////////////////////////////////////
//
//  The lazy functions themselves.
//
///////////////////////////////////////////////////////////////////////////////
function<stl::assign> const         assign = {};
function<stl::at> const             at = {};
function<stl::back> const           back = {};
function<stl::begin> const          begin = {};
function<stl::capacity> const       capacity = {};
function<stl::clear> const          clear = {};
function<stl::empty> const          empty = {};
function<stl::end> const            end = {};
function<stl::erase> const          erase = {};
function<stl::front> const          front = {};
function<stl::get_allocator> const  get_allocator = {};
function<stl::insert> const         insert = {};
function<stl::key_comp> const       key_comp = {};
function<stl::max_size> const       max_size = {};
function<stl::pop_back> const       pop_back  = {};
function<stl::pop_front> const      pop_front = {};
function<stl::push_back> const      push_back  = {};
function<stl::push_front> const     push_front = {};
function<stl::rbegin> const         rbegin = {};
function<stl::rend> const           rend = {};
function<stl::reserve> const        reserve = {};
function<stl::resize> const         resize = {};
function<stl::size> const           size = {};
function<stl::splice> const         splice = {};
function<stl::value_comp> const     value_comp = {};

}} // namespace boost::phoenix

#endif // PHOENIX_STL_CONTAINERS_HPP
