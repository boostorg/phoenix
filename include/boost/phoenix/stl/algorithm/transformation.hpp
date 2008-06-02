// Copyright 2005 Daniel Wallin. 
// Copyright 2005 Joel de Guzman.
// Copyright 2005 Dan Marsden. 
//
// Use, modification and distribution is subject to the Boost Software 
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// Modeled after range_ex, Copyright 2004 Eric Niebler

#ifndef PHOENIX_ALGORITHM_TRANSFORMATION_HPP
#define PHOENIX_ALGORITHM_TRANSFORMATION_HPP

#include <algorithm>
#include <numeric>

#include <boost/phoenix/stl/algorithm/detail/has_sort.hpp>
#include <boost/phoenix/stl/algorithm/detail/has_remove.hpp>
#include <boost/phoenix/stl/algorithm/detail/has_remove_if.hpp>
#include <boost/phoenix/stl/algorithm/detail/has_unique.hpp>
#include <boost/phoenix/stl/algorithm/detail/has_reverse.hpp>
#include <boost/phoenix/stl/algorithm/detail/has_sort.hpp>

#include <boost/phoenix/stl/algorithm/detail/begin.hpp>
#include <boost/phoenix/stl/algorithm/detail/end.hpp>
#include <boost/phoenix/stl/algorithm/detail/decay_array.hpp>

#include <boost/phoenix/function/function.hpp>

#include <boost/range/result_iterator.hpp>
#include <boost/range/difference_type.hpp>

#include <boost/mpl/if.hpp>

#include <boost/type_traits/is_void.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace boost { namespace phoenix { namespace impl
{
    struct swap
    {
        typedef void result_type;

        template <class A, class B>
        void operator()(A& a, B& b) const
        {
            using std::swap;
            swap(a, b);
        }
    };

    struct copy
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class I>
        struct result<This(R, I)>
          : detail::decay_array<typename remove_reference<I>::type>
        {};

        template<class R, class I>
        I operator()(R& r, I i) const
        {
            return std::copy(detail::begin_(r), detail::end_(r), i);
        }
    };

    struct copy_backward
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class I>
        struct result<This(R, I)>
        {
            typedef
                typename remove_const<
                    typename remove_reference<I>::type
                >::type
            type;
        };
        
        template<class R, class I>
        I operator()(R& r, I i) const
        {
            return std::copy_backward(detail::begin_(r), detail::end_(r), i);
        }
    };

    struct transform
    {
        template<typename Sig>
        struct result;
        
        template<typename This, class R, class O, class F>
        struct result<This(R, O, F)>
        {
            typedef
                typename detail::decay_array<
                    typename remove_reference<O>::type
                >::type
            type;
        };

        template<typename This, class R, class I, class O, class F>
        struct result<This(R, I, O, F)>
        {
            typedef
                typename detail::decay_array<
                    typename remove_reference<O>::type
                >::type
            type;
        };

        template<class R, class O, class F>
        O operator()(R& r, O o, F f) const
        {
            return std::transform(detail::begin_(r), detail::end_(r), o, f);
        }

        template<class R, class I, class O, class F>
        O operator()(R& r, I i, O o, F f) const
        {
            return std::transform(detail::begin_(r), detail::end_(r), i, o, f);
        }
    };

    struct replace
    {
        typedef void result_type;

        template<class R, class T>
        void operator()(R& r, T const& what, T const& with) const
        {
            std::replace(detail::begin_(r), detail::end_(r), what, with);
        }
    };

    struct replace_if
    {
        typedef void result_type;

        template<class R, class P, class T>
        void operator()(R& r, P p, T const& with) const
        {
            std::replace_if(detail::begin_(r), detail::end_(r), p, with);
        }
    };

    struct replace_copy
    {
        template<typename Sig>
        struct result;
        
        template<class This, class R, class O, class T, class T2>
        struct result<This(R, O, T, T2)>
        {
            typedef
                typename detail::decay_array<
                    typename remove_reference<O>::type
                >::type
            type;
        };

        template<class R, class O, class T>
        O operator()(R& r, O o, T const& what, T const& with) const
        {
            return std::replace_copy(detail::begin_(r), detail::end_(r), o, what, with);
        }
    };

    struct replace_copy_if
    {
        template<typename Sig>
        struct result;
        
        template<class This, class R, class O, class P, class T>
        struct result<This(R, O, P, T)>
        {
            typedef
                typename detail::decay_array<
                    typename remove_reference<O>::type
                >::type
            type;
        };

        template<class R, class O, class P, class T>
        O operator()(R& r, O o, P p, T const& with) const
        {
            return std::replace_copy_if(detail::begin_(r), detail::end_(r), o, p, with);
        }
    };

    struct fill
    {
        typedef void result_type;

        template<class R, class T>
        void operator()(R& r, T const& x) const
        {
            std::fill(detail::begin_(r), detail::end_(r), x);
        }
    };

    struct fill_n
    {
        typedef void result_type;

        template<class R, class N, class T>
        void operator()(R& r, N n, T const& x) const
        {
            std::fill_n(detail::begin_(r), n, x);
        }
    };

    struct generate
    {
        typedef void result_type;

        template<class R, class G>
        void operator()(R& r, G g) const
        {
            std::generate(detail::begin_(r), detail::end_(r), g);
        }
    };

    struct generate_n
    {
        typedef void result_type;

        template<class R, class N, class G>
        void operator()(R& r, N n, G g) const
        {
            std::generate_n(detail::begin_(r), n, g);
        }
    };

    struct remove
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class T>
        struct result<This(R, T)>
          : range_result_iterator<typename remove_reference<R>::type>
        {};

        template<class R, class T>
        typename range_result_iterator<R>::type
        execute(R& r, T const& x, mpl::true_) const
        {
            r.remove(x);
            return detail::end_(r);
        }

        template<class R, class T>
        typename range_result_iterator<R>::type
        execute(R& r, T const& x, mpl::false_) const
        {
            return std::remove(detail::begin_(r), detail::end_(r), x);
        }

        template<class R, class T>
        typename range_result_iterator<R>::type
        operator()(R& r, T const& x) const
        {
            return this->execute(r, x, has_remove<R>());
        }
    };

    struct remove_if
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class P>
        struct result<This(R, P)>
          : range_result_iterator<typename remove_reference<R>::type>
        {};

        template<class R, class P>
        typename range_result_iterator<R>::type
        execute(R& r, P p, mpl::true_) const
        {
            r.remove_if(p);
            return detail::end_(r);
        }

        template<class R, class P>
        typename range_result_iterator<R>::type
        execute(R& r, P p, mpl::false_) const
        {
            return std::remove_if(detail::begin_(r), detail::end_(r), p);
        }

        template<class R, class P>
        typename range_result_iterator<R>::type
        operator()(R& r, P p) const
        {
            return this->execute(r, p, has_remove_if<R>());
        }
    };

    struct remove_copy
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class O, class T>
        struct result<This(R, O, T)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class R, class O, class T>
        O operator()(R& r, O o, T const& x) const
        {
            return std::remove_copy(detail::begin_(r), detail::end_(r), o, x);
        }
    };

    struct remove_copy_if
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class O, class P>
        struct result<This(R, O, P)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class R, class O, class P>
        O operator()(R& r, O o, P p) const
        {
            return std::remove_copy_if(detail::begin_(r), detail::end_(r), o, p);
        }
    };

    struct unique
    {
        template<class Sig>
        struct result;
        
        template<class This, class R>
        struct result<This(R)>
          : range_result_iterator<typename remove_reference<R>::type>
        {};

        template<class This, class R, class P>
        struct result<This(R, P)>
          : range_result_iterator<typename remove_reference<R>::type>
        {};

        template<class R>
        typename range_result_iterator<R>::type
        execute(R& r, mpl::true_) const
        {
            r.unique();
            return detail::end_(r);
        }

        template<class R>
        typename range_result_iterator<R>::type
        execute(R& r, mpl::false_) const
        {
            return std::unique(detail::begin_(r), detail::end_(r));
        }

        template<class R>
        typename range_result_iterator<R>::type
        operator()(R& r) const
        {
            return this->execute(r, has_unique<R>());
        }

        template<class R, class P>
        typename range_result_iterator<R>::type
        execute(R& r, P p, mpl::true_) const
        {
            r.unique(p);
            return detail::end_(r);
        }

        template<class R, class P>
        typename range_result_iterator<R>::type
        execute(R& r, P p, mpl::false_) const
        {
            return std::unique(detail::begin_(r), detail::end_(r), p);
        }

        template<class R, class P>
        typename range_result_iterator<R>::type
        operator()(R& r, P p) const
        {
            return this->execute(r, p, has_unique<R>());
        }
    };

    struct unique_copy
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class O>
        struct result<This(R, O)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class This, class R, class O, class P>
        struct result<This(R, O, P)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class R, class O>
        O operator()(R& r, O o) const
        {
            return std::unique_copy(
                detail::begin_(r)
              , detail::end_(r)
              , o
            );
        }

        template<class R, class O, class P>
        O operator()(R& r, O o, P p) const
        {
            return std::unique_copy(
                detail::begin_(r)
              , detail::end_(r)
              , o
              , p
            );
        }
    };

    struct reverse
    {
        typedef void result_type;

        template<class R>
        void execute(R& r, mpl::true_) const
        {
            r.reverse();
        }

        template<class R>
        void execute(R& r, mpl::false_) const
        {
            std::reverse(detail::begin_(r), detail::end_(r));
        }

        template<class R>
        void operator()(R& r) const
        {
            this->execute(r, has_reverse<R>());
        }
    };

    struct reverse_copy
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class O>
        struct result<This(R, O)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class R, class O>
        O operator()(R& r, O o) const
        {
            return std::reverse_copy(
                detail::begin_(r)
              , detail::end_(r)
              , o
            );
        }
    };

    struct rotate
    {
        typedef void result_type;

        template<class R, class M>
        void operator()(R& r, M m) const
        {
            std::rotate(
                detail::begin_(r)
              , m
              , detail::end_(r)
            );
        }
    };

    struct rotate_copy
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class M, class O>
        struct result<This(R, M, O)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class R, class M, class O>
        O operator()(R& r, M m, O o) const
        {
            return std::rotate_copy(
                detail::begin_(r)
              , m
              , detail::end_(r)
              , o
            );
        }
    };

    struct random_shuffle
    {
        typedef void result_type;

        template<class R>
        void operator()(R& r) const
        {
            return std::random_shuffle(detail::begin_(r), detail::end_(r));
        }

        template<class R, class G>
        void operator()(R& r, G g) const
        {
            return std::random_shuffle(detail::begin_(r), detail::end_(r), g);
        }
    };

    struct partition
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class P>
        struct result<This(R, P)>
          : range_result_iterator<typename remove_reference<R>::type>
        {};

        template<class R, class P>
        typename range_result_iterator<R>::type
        operator()(R& r, P p) const
        {
            return std::partition(detail::begin_(r), detail::end_(r), p);
        }
    };

    struct stable_partition
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class P>
        struct result<This(R, P)>
          : range_result_iterator<typename remove_reference<R>::type>
        {};

        template<class R, class P>
        typename range_result_iterator<R>::type
        operator()(R& r, P p) const
        {
            return std::stable_partition(detail::begin_(r), detail::end_(r), p);
        }
    };

    struct sort
    {
        typedef void result_type;

        template<class R>
        void execute(R& r, mpl::true_) const
        {
            r.sort();
        }

        template<class R>
        void execute(R& r, mpl::false_) const
        {
            std::sort(detail::begin_(r), detail::end_(r));
        }

        template<class R>
        void operator()(R& r) const
        {
            this->execute(r, has_sort<R>());
        }

        template<class R, class C>
        void execute(R& r, C c, mpl::true_) const
        {
            r.sort(c);
        }

        template<class R, class C>
        void execute(R& r, C c, mpl::false_) const
        {
            std::sort(detail::begin_(r), detail::end_(r), c);
        }

        template<class R, class C>
        void operator()(R& r, C c) const
        {
            this->execute(r, c, has_sort<R>());
        }
    };

    struct stable_sort
    {
        typedef void result_type;

        template<class R>
        void operator()(R& r) const
        {
            std::stable_sort(detail::begin_(r), detail::end_(r));
        }

        template<class R, class C>
        void operator()(R& r, C c) const
        {
            std::stable_sort(detail::begin_(r), detail::end_(r), c);
        }
    };

    struct partial_sort
    {
        typedef void result_type;

        template<class R, class M>
        void operator()(R& r, M m) const
        {
            std::partial_sort(detail::begin_(r), m, detail::end_(r));
        }

        template<class R, class M, class C>
        void operator()(R& r, M m, C c) const
        {
            std::partial_sort(detail::begin_(r), m, detail::end_(r), c);
        }
    };

    struct partial_sort_copy
    {
        template<class Sig>
        struct result;
        
        template<class This, class R1, class R2>
        struct result<This(R1, R2)>
          : range_result_iterator<typename remove_reference<R2>::type>
        {};

        template<class This, class R1, class R2, class C>
        struct result<This(R1, R2, C)>
          : range_result_iterator<typename remove_reference<R2>::type>
        {};

        template<class R1, class R2>
        typename range_result_iterator<R2>::type
        operator()(R1& r1, R2& r2) const
        {
            return std::partial_sort_copy(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
            );
        }

        template<class R1, class R2, class C>
        typename range_result_iterator<R2>::type
        operator()(R1& r1, R2& r2, C c) const
        {
            return std::partial_sort_copy(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
              , c
            );
        }
    };

    struct nth_element
    {
        typedef void result_type;

        template<class R, class N>
        void operator()(R& r, N n) const
        {
            std::nth_element(detail::begin_(r), n, detail::end_(r));
        }

        template<class R, class N, class C>
        void operator()(R& r, N n, C c) const
        {
            std::nth_element(detail::begin_(r), n, detail::end_(r), c);
        }
    };

    struct merge 
    {
        template<class Sig>
        struct result;
        
        template<class This, class R1, class R2, class O>
        struct result<This(R1, R2, O)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class This, class R1, class R2, class O, class C>
        struct result<This(R1, R2, O, C)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class R1, class R2, class O>
        O operator()(R1& r1, R2& r2, O o) const
        {
            return std::merge(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
              , o
            );
        }

        template<class R1, class R2, class O, class C>
        O operator()(R1& r1, R2& r2, O o, C c) const
        {
            return std::merge(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
              , o
              , c
            );
        }
    };

    struct inplace_merge 
    {
        typedef void result_type;

        template<class R, class M>
        void operator()(R& r, M m) const
        {
            std::inplace_merge(detail::begin_(r), m, detail::end_(r));
        }

        template<class R, class M, class C>
        void operator()(R& r, M m, C c) const
        {
            std::inplace_merge(detail::begin_(r), m, detail::end_(r), c);
        }
    };

    struct next_permutation
    {
        typedef bool result_type;

        template<class R>
        bool operator()(R& r) const
        {
            return std::next_permutation(detail::begin_(r), detail::end_(r));
        }
    
        template<class R, class C>
        bool operator()(R& r, C c) const
        {
            return std::next_permutation(detail::begin_(r), detail::end_(r), c);
        }
    };

    struct prev_permutation
    {
        typedef bool result_type;

        template<class R>
        bool operator()(R& r) const
        {
            return std::prev_permutation(detail::begin_(r), detail::end_(r));
        }
    
        template<class R, class C>
        bool operator()(R& r, C c) const
        {
            return std::prev_permutation(detail::begin_(r), detail::end_(r), c);
        }
    };


    struct inner_product
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class I, class T>
        struct result<This(R, I, T)>
        {
            typedef
                typename remove_const<
                    typename remove_reference<T>::type
                >::type
            type;
        };

        template<class This, class R, class I, class T, class C1, class C2>
        struct result<This(R, I, T, C1, C2)>
        {
            typedef
                typename remove_const<
                    typename remove_reference<T>::type
                >::type
            type;
        };

        template<class R, class I, class T>
        T operator()(R& r, I i, T t) const
        {
            return std::inner_product(
                detail::begin_(r)
              , detail::end_(r)
              , i
              , t
            );
        }

        template<class R, class I, class T, class C1, class C2>
        T operator()(R& r, I i, T t, C1 c1, C2 c2) const
        {
            return std::inner_product(
                detail::begin_(r)
              , detail::end_(r)
              , i
              , t
              , c1
              , c2
            );
        }
    };

    struct partial_sum
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class I>
        struct result<This(R, I)>
          : detail::decay_array<typename remove_reference<I>::type>
        {};
        
        template<class This, class R, class I, class C>
        struct result<This(R, I, C)>
          : detail::decay_array<typename remove_reference<I>::type>
        {};
        
        template<class R, class I>
        I operator()(R& r, I i) const
        {
            return std::partial_sum(
                detail::begin_(r)
              , detail::end_(r)
              , i
            );
        }

        template<class R, class I, class C>
        I operator()(R& r, I i, C c) const
        {
            return std::partial_sum(
                detail::begin_(r)
              , detail::end_(r)
              , i
              , c
            );
        }
    };

    struct adjacent_difference
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class I>
        struct result<This(R, I)>
          : detail::decay_array<typename remove_reference<I>::type>
        {};
        
        template<class This, class R, class I, class C>
        struct result<This(R, I, C)>
          : detail::decay_array<typename remove_reference<I>::type>
        {};

        template<class R, class I>
        I operator()(R& r, I i) const
        {
            return std::adjacent_difference(
                detail::begin_(r)
              , detail::end_(r)
              , i
            );
        }

        template<class R, class I, class C>
        I operator()(R& r, I i, C c) const
        {
            return std::adjacent_difference(
                detail::begin_(r)
              , detail::end_(r)
              , i
              , c
            );
        }    
    };

    struct push_heap
    {
        typedef void result_type;

        template<class R>
        void operator()(R& r) const
        {
            std::push_heap(detail::begin_(r), detail::end_(r));
        }

        template<class R, class C>
        void operator()(R& r, C c) const
        {
            std::push_heap(detail::begin_(r), detail::end_(r), c);
        }
    };

    struct pop_heap
    {
        typedef void result_type;

        template<class R>
        void operator()(R& r) const
        {
            std::pop_heap(detail::begin_(r), detail::end_(r));
        }

        template<class R, class C>
        void operator()(R& r, C c) const
        {
            std::pop_heap(detail::begin_(r), detail::end_(r), c);
        }
    };

    struct make_heap
    {
        typedef void result_type;

        template<class R>
        void operator()(R& r) const
        {
            std::make_heap(detail::begin_(r), detail::end_(r));
        }

        template<class R, class C>
        void operator()(R& r, C c) const
        {
            std::make_heap(detail::begin_(r), detail::end_(r), c);
        }
    };

    struct sort_heap
    {
        typedef void result_type;

        template<class R>
        void operator()(R& r) const
        {
            std::sort_heap(detail::begin_(r), detail::end_(r));
        }

        template<class R, class C>
        void operator()(R& r, C c) const
        {
            std::sort_heap(detail::begin_(r), detail::end_(r), c);
        }
    };

    struct set_union
    {
        template<class Sig>
        struct result;
        
        template<class This, class R1, class R2, class O>
        struct result<This(R1, R2, O)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class This, class R1, class R2, class O, class C>
        struct result<This(R1, R2, O, C)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class R1, class R2, class O>
        O operator()(R1& r1, R2& r2, O o) const
        {
            return std::set_union(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
              , o
            );
        }

        template<class R1, class R2, class O, class C>
        O operator()(R1& r1, R2& r2, O o, C c) const
        {
            return std::set_union(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
              , o
              , c
            );
        }
    };

    struct set_intersection
    {
        template<class Sig>
        struct result;
        
        template<class This, class R1, class R2, class O>
        struct result<This(R1, R2, O)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class This, class R1, class R2, class O, class C>
        struct result<This(R1, R2, O, C)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class R1, class R2, class O>
        O operator()(R1& r1, R2& r2, O o) const
        {
            return std::set_intersection(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
              , o
            );
        }

        template<class R1, class R2, class O, class C>
        O operator()(R1& r1, R2& r2, O o, C c) const
        {
            return std::set_intersection(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
              , o
              , c
            );
        }
    };

    struct set_difference
    {
        template<class Sig>
        struct result;
        
        template<class This, class R1, class R2, class O>
        struct result<This(R1, R2, O)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class This, class R1, class R2, class O, class C>
        struct result<This(R1, R2, O, C)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class R1, class R2, class O>
        O operator()(R1& r1, R2& r2, O o) const
        {
            return std::set_difference(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
              , o
            );
        }

        template<class R1, class R2, class O, class C>
        O operator()(R1& r1, R2& r2, O o, C c) const
        {
            return std::set_difference(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
              , o
              , c
            );
        }
    };

    struct set_symmetric_difference
    {
        template<class Sig>
        struct result;
        
        template<class This, class R1, class R2, class O>
        struct result<This(R1, R2, O)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class This, class R1, class R2, class O, class C>
        struct result<This(R1, R2, O, C)>
          : detail::decay_array<typename remove_reference<O>::type>
        {};

        template<class R1, class R2, class O>
        O operator()(R1& r1, R2& r2, O o) const
        {
            return std::set_symmetric_difference(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
              , o
            );
        }

        template<class R1, class R2, class O, class C>
        O operator()(R1& r1, R2& r2, O o, C c) const
        {
            return std::set_symmetric_difference(
                detail::begin_(r1)
              , detail::end_(r1)
              , detail::begin_(r2)
              , detail::end_(r2)
              , o
              , c
            );
        }
    };

}}} // boost::phoenix::impl

namespace boost { namespace phoenix
{
    function<impl::swap> const swap = {};
    function<impl::copy> const copy = {};
    function<impl::copy_backward> const copy_backward = {};
    function<impl::transform> const transform = {};
    function<impl::replace> const replace = {};
    function<impl::replace_if> const replace_if = {};
    function<impl::replace_copy> const replace_copy = {};
    function<impl::replace_copy_if> const replace_copy_if = {};
    function<impl::fill> const fill = {};
    function<impl::fill_n> const fill_n = {};
    function<impl::generate> const generate = {};
    function<impl::generate_n> const generate_n = {};
    function<impl::remove> const remove = {};
    function<impl::remove_if> const remove_if = {};
    function<impl::remove_copy> const remove_copy = {};
    function<impl::remove_copy_if> const remove_copy_if = {};
    function<impl::unique> const unique = {};
    function<impl::unique_copy> const unique_copy = {};
    function<impl::reverse> const reverse = {};
    function<impl::reverse_copy> const reverse_copy = {};
    function<impl::rotate> const rotate = {};
    function<impl::rotate_copy> const rotate_copy = {};
    function<impl::random_shuffle> const random_shuffle = {};
    function<impl::partition> const partition = {};
    function<impl::stable_partition> const stable_partition = {};
    function<impl::sort> const sort = {};
    function<impl::stable_sort> const stable_sort = {};
    function<impl::partial_sort> const partial_sort = {};
    function<impl::partial_sort_copy> const partial_sort_copy = {};
    function<impl::nth_element> const nth_element = {};
    function<impl::merge> const merge = {};
    function<impl::inplace_merge> const inplace_merge = {};
    function<impl::next_permutation> const next_permutation = {};
    function<impl::prev_permutation> const prev_permutation = {};
    function<impl::inner_product> const inner_product = {};
    function<impl::partial_sum> const partial_sum = {};
    function<impl::adjacent_difference> const adjacent_difference = {};
    function<impl::push_heap> const push_heap = {};
    function<impl::pop_heap> const pop_heap = {};
    function<impl::make_heap> const make_heap = {};
    function<impl::sort_heap> const sort_heap = {};
    function<impl::set_union> const set_union = {};
    function<impl::set_intersection> const set_intersection = {};
    function<impl::set_difference> const set_difference = {};
    function<impl::set_symmetric_difference> const set_symmetric_difference = {};
}}

#endif
