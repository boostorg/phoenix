// Copyright 2005 Daniel Wallin. 
// Copyright 2005 Joel de Guzman.
// Copyright 2005 Dan Marsden. 
//
// Use, modification and distribution is subject to the Boost Software 
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// Modeled after range_ex, Copyright 2004 Eric Niebler

#ifndef PHOENIX_ALGORITHM_ITERATION_HPP
#define PHOENIX_ALGORITHM_ITERATION_HPP

#include <algorithm>
#include <numeric>

#include <boost/phoenix/stl/algorithm/detail/begin.hpp>
#include <boost/phoenix/stl/algorithm/detail/end.hpp>

#include <boost/phoenix/function/function.hpp>

#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace boost { namespace phoenix {
namespace impl
{
    struct for_each
    {
        template<class Sig>
        struct result;
        
        template<class This, class R, class F>
        struct result<This(R, F)>
        {
            typedef
                typename remove_const<
                    typename remove_reference<F>::type
                >::type
            type;
        };

        template<class R, class F>
        F operator()(R& r, F fn) const
        {        
            return std::for_each(detail::begin_(r), detail::end_(r), fn);
        }
    };

    struct accumulate
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

        template<class This, class R, class I, class C>
        struct result<This(R, I, C)>
          : result<This(R, I)>
        {};

        template<class R, class I>
        I operator()(R& r, I i) const
        {
            return std::accumulate(detail::begin_(r), detail::end_(r), i);
        }

        template<class R, class I, class C>
        I operator()(R& r, I i, C c) const
        {
            return std::accumulate(detail::begin_(r), detail::end_(r), i, c);
        }
    };
}

function<impl::for_each> const for_each = {};
function<impl::accumulate> const accumulate = {};

}}

#endif
