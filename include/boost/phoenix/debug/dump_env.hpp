/*==============================================================================
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_DEBUG_DUMP_ENVIRONMENT_HPP
#define PHOENIX_DEBUG_DUMP_ENVIRONMENT_HPP

#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/mpl/void.hpp>
#include <boost/phoenix/core/extension.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/proto/proto_fwd.hpp>
#include <boost/proto/matches.hpp>

#include <iostream>

namespace boost { namespace phoenix
{
    namespace detail
    {
        struct dump_env_tag {};

        typedef extension<dump_env_tag> dump_env_ext;

        struct dump
        {
            template<typename T>
            void
            operator()(T & t ) const
            {
                std::cout << t << std::endl;
            }
        };

        struct dump_env
            : proto::callable
        {
            typedef void result_type;

            template<typename Env>
            void
            operator()(Env & env) const
            {
                if( fusion::size( env ) == 0 )
                {
                    std::cout << "current environment is empty.\n";
                    return;
                }

                std::cout << "current environment is:\n";
                fusion::for_each( env, dump() );
            }
        };
    }

    
	/// FIXME: boost::result_of doesn't seem to like that...
	//boost::result_of< detail::dump_environment_extension() >::type
    /*
	boost::result_of< detail::dump_env_ext( mpl::void_ ) >::type
		dump_env()
	{
		return detail::dump_env_ext()( mpl::void_() );
	}*/
    
    
    template<>
    struct eval_cases::case_<debug::detail::dump_env_tag>
        : proto::or_<
            proto::when<
                proto::_, debug::detail::dump_env(proto::_state)> >
	{};

}}

#endif
