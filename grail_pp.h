#2""3
#define GRAIL_PP_IF_(P,c,...) P##c
#define GRAIL_PP_IF_0(P,c,v...) P##v
#define GRAIL_PP_IF_1(P,c,...) P##c

#define GRAIL_PP_0NEVER(...) GRAIL_PP_IF_0

#define GRAIL_PP_IS_EDIBLE(P,x) GRAIL_PP_TEST(GRAIL_PP_IF_,GRAIL_PP_IS_EDIBLE_TEST x##P,,0)
#define GRAIL_PP_IS_EDIBLE_TEST(...) ,,

#define GRAIL_PP_IS_NIL(P,x) GRAIL_PP_IS_EDIBLE(,P##x)(GRAIL_PP_,0NEVER,IS_EDIBLE)(,P##x())

#define GRAIL_PP_TEST(P,x,c,a) GRAIL_PP_TUPLE_AT_3(,x,P##c,,P##a)
#define GRAIL_PP_TUPLE_AT_3(P,a,b,c,d,...) d

#define P(_) _Pragma(#_)
#define CC(___,_,__,...) ___##__
#define C(_...) CC(_)
#define X(x...) x
#define E(...)
#define R(x...) E(x)
#define U(_) P(push_macro(#_))
#define O(_) P(pop_macro(#_))

#define IIF_1 GRAIL_PP_IF_1


#define A(x) x,
#define _1(a,...) a

#define N GRAIL_PP_IS_NIL

#define G(s) N(,s)(,,X(_1 E()(_1(A s))))
#define H(f,x) N(,x) (,,f(x))
#define SMR(f,s) U(SMR)O(SMR) N(,s)(,E,SMR)(f, E s) H(f,G(s))

//#define CSVMR(f,t...) U(SMR)O(SMR) N(,t)(,E,SMR)(f, E s) H(f,G(s))

#define COM_X(x),x


#define S(x) (x)
#define PLUS(x) + x

#define REST(x,r...) r
