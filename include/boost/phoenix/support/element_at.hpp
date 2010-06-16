/*==============================================================================
    Copyright (c) 2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SUPPORT_ELEMENT_AT_HPP
#define PHOENIX_SUPPORT_ELEMENT_AT_HPP

#include <boost/fusion/sequence/intrinsic/value_at.hpp>

#include <boost/proto/traits.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Actors carry specific information with it. Primitive actors may hold
    // simple primitive data, like values (e.g. int). Composites hold a tuple
    // of proto expressions that evaluate to actors (using fusion vector).
    // The following facilities extract the "elements" from an actor. An
    // element is just a proto expression that evaluates to an actor.
    //
    ////////////////////////////////////////////////////////////////////////////
    namespace result_of
    {
        // Get the Nth element value type from Expr (N is an integral constant)
        template <class Expr, int N>
        struct element_value_at_c : fusion::result_of::value_at_c<Expr, N+2>
        {};
        
        // Get the Nth element value type from Expr (N is an mpl int_)
        template <class Expr, class N>
        struct element_value_at : element_value_at_c<Expr, N::value>
        {};
        
        // Get the element type N from Expr (N is an integral constant)
        template <class Expr, int N>
        struct element_at_c : proto::result_of::child_c<Expr &, N+2>
        {};

        // Get the Nth element type N from Expr (N is an mpl int_)
        template <class Expr, class N>
        struct element_at : element_at_c<Expr, N::value>
        {};
    }

    // Get the Nth element value N from Expr (N is an integral constant)
    // non-const overload
    template <int N, class Expr>
    typename result_of::element_at_c<Expr, N>::type
    element_at_c(Expr& expr)
    {
        return proto::child_c<N+2>(expr);
    }
    
    // Get the Nth element value N from Expr (N is an integral constant)
    // const overload
    template <int N, class Expr>
    typename result_of::element_at_c<Expr const, N>::type
    element_at_c(Expr const& expr)
    {
        return proto::child_c<N+2>(expr);
    }
    
    // Get the Nth element value N from Expr (N is an mpl int_)
    // non-const overload
    template <class N, class Expr>
    typename result_of::element_at<Expr, N>::type
    element_at(Expr& expr)
    {
        return proto::child_c<N::value + 2>(expr);
    }
    
    // Get the Nth element value N from Expr (N is an mpl int_)
    // const overload
    template <class N, class Expr>
    typename result_of::element_at<Expr const, N>::type
    element_at(Expr const& expr)
    {
        return proto::child_c<N::value + 2>(expr);
    }

}}

#endif
