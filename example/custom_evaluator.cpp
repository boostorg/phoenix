/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/proto/proto.hpp>

#include <iostream>
#include <typeinfo>

namespace proto = boost::proto;
namespace phoenix = boost::phoenix;

namespace impl
{

    template <typename OutStream>
    struct phoenix_to_cpp
    {
        phoenix_to_cpp( OutStream& ostr ) : ostr(ostr), level(1) {};

        OutStream& ostr;
        int level;

        template <typename Expr, typename Tag = typename proto::tag_of<Expr>::type>
        struct eval
            : proto::null_eval<Expr, phoenix_to_cpp>
        {};

        template <typename Expr>
        struct eval<Expr, proto::tag::minus>
        {
            typedef OutStream& result_type;

            result_type operator()(Expr &expr, phoenix_to_cpp &ctx) const
            {
                proto::eval(proto::child_c<0>(expr), ctx);
                ctx.ostr << " - ";
                proto::eval(proto::child_c<1>(expr), ctx);

                return ctx.ostr;
            }
        };

        template <typename Expr>
        struct eval<Expr, proto::tag::plus>
        {
            typedef OutStream& result_type;

            result_type operator()(Expr &expr, phoenix_to_cpp &ctx) const
            {
                proto::eval(proto::child_c<0>(expr), ctx);
                ctx.ostr << " + ";
                proto::eval(proto::child_c<1>(expr), ctx);

                return ctx.ostr;
            }
        };

        template <typename Expr>
        struct eval<Expr, proto::tag::comma>
        {
            typedef OutStream& result_type;

            result_type operator()(Expr &expr, phoenix_to_cpp &ctx) const
            {
                ctx.ostr << std::setw(ctx.level*4) << " "; proto::eval(proto::child_c<0>(expr), ctx);
                ctx.ostr << ";\n";
                ctx.ostr << std::setw(ctx.level*4) << " "; proto::eval(proto::child_c<1>(expr), ctx);
                ctx.ostr << ";";

                return ctx.ostr;
            }
        };
        
        template <typename Expr>
        struct eval<Expr, proto::tag::function>
        {
            typedef OutStream& result_type;
            
            template <typename N, typename E>
            void output(OutStream& os, E &expr) const {}

            template <typename N, typename Env>
            void output(OutStream& os,
                    phoenix::actor<
                        proto::basic_expr<
                            boost::proto::tag::function
                          , proto::list3<
                                proto::basic_expr<
                                    proto::tag::terminal
                                  , proto::term< phoenix::funcwrap<phoenix::argument> >
                                >
                              , Env
                              , proto::basic_expr<
                                    proto::tag::terminal
                                  , proto::term< N >
                                >
                            >
                        >
                    > const& expr) const
            {
                os << "arg" << N::value;
            }

            result_type operator()(Expr &expr, phoenix_to_cpp &ctx) const
            {

                output( ctx.ostr, expr );

                return ctx.ostr;
            }
        };
    };
}

template <typename Expr>
void phoenix_to_cpp(Expr const& expr)
{
    std::cout << "template <typename Result";

    for( unsigned i = 0; i < phoenix::arity(expr); ++i )
    {
        std::cout << ", typename Arg" << i;
    }
    std::cout << ">\n";
    std::cout << "Result f(";
    for( unsigned i = 0; i < phoenix::arity(expr); ++i )
    {
        std::cout << "Arg" << i << " arg" << i;
        if( i != phoenix::arity(expr)-1 ) std::cout << ", ";
    }
    std::cout << ")\n{\n";

    impl::phoenix_to_cpp<std::ostream> ctx(std::cout);
    proto::eval( expr, ctx );

    std::cout << "\n}\n";
}


int main()
{
    using phoenix::arg_names::arg1;
    using phoenix::arg_names::arg2;
    using phoenix::arg_names::arg3;

    phoenix_to_cpp( (arg1 + arg2, arg1 - arg2, arg1 + arg2 - arg3 ) );
    
}

