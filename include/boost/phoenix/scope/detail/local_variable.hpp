/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_DETAIL_LOCAL_VARIABLE_HPP
#define PHOENIX_SCOPE_DETAIL_LOCAL_VARIABLE_HPP

#define PHOENIX_MAP_LOCAL_TEMPLATE_PARAM(z, n, data) \
    typename T##n = unused<n>

#define PHOENIX_MAP_LOCAL_DISPATCH(z, n, data)  \
    typedef char(&result##n)[n+2];              \
    static result##n get(T##n*);


namespace boost { namespace phoenix
{
    namespace detail
    {
        struct compute_no_nullary
        {
            template <typename State, typename T>
            struct apply
            {
                typedef typename 
                    mpl::or_<typename no_nullary<T>::type, State>::type
                type;
            };
        };

        template <typename Env>
        struct initialize_local
        {
            template <typename Sig>
            struct result;

            template <typename This, typename Expr>
            struct result<This(Expr)>
            {
                typedef typename remove_reference<Expr>::type expr_type;
                typedef typename boost::result_of<eval_grammar(expr_type const&, Env &)>::type type;
            };

            initialize_local(Env& env)
                : env(env) {}

            template <typename Expr>
            typename result<initialize_local(Expr)>::type
            operator()(Expr const& expr) const
            {
                return eval(expr, env);
            }

            Env& env;
        };

        template <int N>
        struct unused;

        template <BOOST_PP_ENUM(
                PHOENIX_LOCAL_LIMIT, PHOENIX_MAP_LOCAL_TEMPLATE_PARAM, _)>
        struct map_local_index_to_tuple
        {
            typedef char(&not_found)[1];
            static not_found get(...);

            BOOST_PP_REPEAT(PHOENIX_LOCAL_LIMIT, PHOENIX_MAP_LOCAL_DISPATCH, _)
        };

        template<typename T>
        T* generate_pointer();

        template <typename Map, typename Tag>
        struct get_index
        {
            BOOST_STATIC_CONSTANT(int,
                value = (
                    static_cast<int>((sizeof(Map::get(generate_pointer<Tag>()))) / sizeof(char)) - 2
                ));

            // if value == -1, Tag is not found
            typedef mpl::int_<value> type;
        };

        template <typename Key, typename Env>
        struct apply_local;

        template <typename Key, typename Env>
        struct outer_local
        {
            typedef typename
                apply_local<Key, typename Env::outer_env_type>::type
            type;
        };

        template <typename Locals, typename Index>
        struct get_local_or_void
        {
            typedef typename
                mpl::eval_if<
                    mpl::less<Index, mpl::size<Locals> >
                  , fusion::result_of::at<Locals, Index>
                  , mpl::identity<fusion::void_>
                >::type
            type;
        };

        template <typename Key, typename Env, typename Index>
        struct get_local_from_index
        {
            typedef typename
                mpl::eval_if<
                    mpl::equal_to<Index, mpl::int_<-1> >
                  , outer_local<Key, Env>
                  , get_local_or_void<typename Env::locals_type, Index>
                >::type
            type;
        };

        template <typename Key, typename Env>
        struct get_local
        {
            typedef typename
                get_index<
                    typename Env::map_type, Key>::type
            index_type;

            typedef typename
                get_local_from_index<Key, Env, index_type>::type
            type;
        };

        template <typename Key, typename Env>
        struct apply_local
        {
            //BOOST_STATIC_ASSERT( is_scoped_environment<Env>::value );
            // $$$ TODO: static assert that Env is a scoped_environment $$$
            typedef typename get_local<Key, Env>::type type;
        };

        template <typename Key>
        struct eval_local
        {
            template <typename RT, typename Env, typename Index>
            static RT
            get(Env & env, Index, mpl::false_)
            {
                return fusion::at<Index>(env.locals);
            }

            template <typename RT, typename Env, typename Index>
            static RT
            get(Env & env, Index index, mpl::true_)
            {
                typedef typename
                    get_index<typename Env::outer_env_type::map_type, Key>::type
                index_type;

                return get<RT>(
                    env.outer_env
                  , index_type()
                  , mpl::equal_to<index_type, mpl::int_<-1> >());
            }

            template <typename RT, typename Env, typename Index>
            static RT
            get(Env & env, Index index)
            {
                return get<RT>(
                    env
                  , index
                  , mpl::equal_to<Index, mpl::int_<-1> >());
            }
        };

    }

}}

#endif
