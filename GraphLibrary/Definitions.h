//
// Created by Eugene Marchukevich on 12/15/15.
//

#ifndef TEST_DEFINITIONS_H
#define TEST_DEFINITIONS_H


namespace GraphLibrary
{
#define MAX_DISTANCE 1e18

    typedef int vertex;

    struct EdgeTo
    {
        int finish;
        long long weight;
        EdgeTo(int _finish, long long _weight)
        {
            finish = _finish;
            weight = _weight;
        }
    };

    struct Edge
    {
        int start, finish;
        long long weight;
        Edge(int _start, int _finish, long long _weight)
        {
            start = _start;
            finish = _finish;
            weight = _weight;
        }

        Edge(int _start, int _finish)
        {
            start = _start;
            finish = _finish;
            weight = 1;
        }
        Edge(int _start, EdgeTo edgeTo)
        {
            start = _start;
            finish = edgeTo.finish;
            weight = edgeTo.weight;
        }
    };


#define CREATE_MEMBER_DETECTOR(X)                                                   \
template<typename T> class Detect_##X {                                             \
    struct Fallback { int X; };                                                     \
    struct Derived : T, Fallback { };                                               \
                                                                                    \
    template<typename U, U> struct Check;                                           \
                                                                                    \
    typedef char ArrayOfOne[1];                                                     \
    typedef char ArrayOfTwo[2];                                                     \
                                                                                    \
    template<typename U> static ArrayOfOne & func(Check<int Fallback::*, &U::X> *); \
    template<typename U> static ArrayOfTwo & func(...);                             \
  public:                                                                           \
    typedef Detect_##X type;                                                        \
    enum { value = sizeof(func<Derived>(0)) == 2 };                                 \
};

#define CREATE_METHOD_CALLER_NO_PARAMETERS(X, G)    \
    template< typename ReturnType, typename T1 = G > \
    struct call_##X \
    { \
        T1* object; \
        call_##X( T1* object ) \
                : object( object ) \
        {} \
\
        template< typename U, bool > \
        struct chooser; \
\
        template< typename U > \
        struct chooser< U, true > \
        {\
            T1* object;\
            chooser( T1* object ) \
                    : object( object ) \
            {}\
\
            ReturnType operator()()\
            {\
                return object->X();\
            } \
        }; \
\
        template< typename U > \
        struct chooser< U, false > \
        { \
            T1* object; \
            chooser( T1* object ) \
                    : object( object )\
            {} \
\
            ReturnType operator()() \
            { \
                return ReturnType(); \
            } \
        }; \
\
        ReturnType operator()() \
        { \
            chooser< T1, Detect_##X< T1 >::value > c( object ); \
            return c(); \
        } \
    };

#define CREATE_METHOD_CALLER_WITH_PARAMETERS(X, G)    \
    template< typename ReturnType, typename T1 = G > \
    struct call_##X \
    { \
        T1* object; \
        call_##X( T1* object ) \
                : object( object ) \
        {} \
\
        template< typename U, bool > \
        struct chooser; \
\
        template< typename U > \
        struct chooser< U, true > \
        {\
            T1* object;\
            chooser( T1* object ) \
                    : object( object ) \
            {}\
\
            ReturnType operator()(vertex v)\
            {\
                return object->X(v);\
            } \
        }; \
\
        template< typename U > \
        struct chooser< U, false > \
        { \
            T1* object; \
            chooser( T1* object ) \
                    : object( object )\
            {} \
\
            ReturnType operator()(vertex v) \
            { \
                return ReturnType(); \
            } \
        }; \
\
        ReturnType operator()(vertex v) \
        { \
            chooser< T1, Detect_##X< T1 >::value > c( object ); \
            return c(v); \
        } \
    };


#define CREATE_CHECK_METHOD_NO_PARAMS( X, G) \
    CREATE_MEMBER_DETECTOR(X); \
    CREATE_METHOD_CALLER_NO_PARAMETERS(X, G);


#define CREATE_CHECK_METHOD_PARAMS( X, G) \
    CREATE_MEMBER_DETECTOR(X); \
    CREATE_METHOD_CALLER_WITH_PARAMETERS(X, G);

#define CREATE_METHOD_CALLER(R,X,G) \
    call_##X<R> callMethod_##X( G );

}

#endif //TEST_DEFINITIONS_H
