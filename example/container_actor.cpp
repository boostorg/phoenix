/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/phoenix/core.hpp>
#include <boost/phoenix/function.hpp>

#include <vector>

namespace phoenix = boost::phoenix;

using phoenix::actor;
using phoenix::function;
using phoenix::arg_names::arg1;

struct size_impl
{
    // result_of protocol:
    template <typename Sig>
    struct result;
    
    template <typename This, typename Container>
    struct result<This(Container)>
    {
        // Note, remove reference here, because Container can be anything
        typedef typename boost::remove_reference<Container>::type container_type;
        
        // The result will be size_type
        typedef typename container_type::size_type type;
    };
    
    template <typename Container>
    typename result<size_impl(Container const&)>::type
    operator()(Container const& container) const
    {
        return container.size();
    }
};

template <typename Expr>
struct container_actor
    : actor<Expr>
{
    typedef actor<Expr> base_type;
    typedef container_actor<Expr> that_type;

    container_actor( base_type const& base )
        : base_type( base ) {}

    typename phoenix::result_of::function<size_impl, that_type>::type const
    size() const
    {
        function<size_impl> const f = size_impl();
        return f(*this);
    }

    // the rest ...
};


template <typename Expr>
container_actor<Expr> const
container( actor<Expr> const& expr )
{
    return expr;
}


template <typename N>
struct make_container_argument : phoenix::compose_ex<phoenix::argument, container_actor, N> {};

typedef make_container_argument<boost::mpl::int_<0> > make_con1;
make_con1::type const con1 = make_con1()(boost::mpl::int_<0>());

int main()
{
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    std::cout << (container(arg1).size())(v) << " == " << v.size() << "\n";


    std::cout << (con1.size())(v) << " == " << v.size() << "\n";
}
