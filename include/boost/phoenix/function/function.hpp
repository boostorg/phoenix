/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_FUNCTION_FUNCTION_HPP
#define PHOENIX_FUNCTION_FUNCTION_HPP

//#include <boost/phoenix/core/extension.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/proto/proto.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // Functions
    ////////////////////////////////////////////////////////////////////////////

    // functor which returns our lazy function call extension
    template<typename F>
    struct function
    {
        //typedef extension<proto::tag::function> extension_type;

        typedef function<F> function_type;
 
        function() {}

        function(F f)
            : f(f)
        {}

        template<typename Signature>
        struct result;

        template<typename This>
        struct result<This()> //: boost::result_of<extension_type(F)>
            : proto::result_of::make_expr<proto::tag::function, phoenix_domain, F>
        {};

        template<typename This, typename A0>
        struct result<This(A0 const &)> //: boost::result_of<extension_type(F, A0 const &)>
            : proto::result_of::make_expr<proto::tag::function, phoenix_domain, F, A0>
        {};

        template<typename This, typename A0, typename A1>
        struct result<This(A0 const &, A1 const &)>
            //: boost::result_of<extension_type(F, A0 const &, A1 const &)>
            : proto::result_of::make_expr<proto::tag::function, phoenix_domain, F, A0, A1>
        {};
        
        /* ... more ... */

        //typename boost::result_of<function_type()>::type
        typename proto::result_of::make_expr<
            proto::tag::function, phoenix_domain, F>::type const
        operator()() const
        {
            //return extension_type()(f);
            return proto::make_expr<proto::tag::function, phoenix_domain>(f);
        }

        template<typename A0>
        //typename boost::result_of<function_type(A0 const &)>::type const
        typename proto::result_of::make_expr<
            proto::tag::function, phoenix_domain, F, A0>::type const
        operator()(A0 const & a0) const
        {
            //return extension_type()(f, a0);
            return proto::make_expr<
                proto::tag::function, phoenix_domain>(f, a0);
        }

        template<typename A0, typename A1>
        //typename boost::result_of<function_type(A0 const &, A1 const &)>::type
        typename proto::result_of::make_expr<
            proto::tag::function, phoenix_domain, F, A0, A1>::type const
        operator()(A0 const & a0, A1 const & a1) const
        {
            //return extension_type()(f, a0, a1);
            return proto::make_expr<
                proto::tag::function, phoenix_domain>(f, a0, a1);
        }

        /* ... more ... */

        F f;
    };

}

    template<typename F>
    struct result_of<phoenix::function<F>()>
    {
        typedef phoenix::function<F> Fun;
        typedef typename Fun::template result<Fun()>::type type;
    };

}

#endif
