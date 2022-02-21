#define GRAIL_PP_P(x) _Pragma(#x)
#define GRAIL_PP_REVIVE(m) GRAIL_PP_P(push_macro(#m))GRAIL_PP_P(pop_macro(#m))

#define GRAIL_PP_EAT(...)
#define GRAIL_PP_SCAN(x...) x

#define GRAIL_PP_TUPLE_AT_2(P,a,b,c,...) P##c

#define GRAIL_PP_IS_NIL_TEST(x...) ,##x

#define GRAIL_PP_IS_NIL(P,x) GRAIL_PP_SCAN(GRAIL_PP_TUPLE_AT_2 GRAIL_PP_EAT() (GRAIL_PP_IF_,GRAIL_PP_IS_NIL_TEST(x),0,1))

#define GRAIL_PP_IF_0(P,c,v...) P##v
#define GRAIL_PP_IF_1(P,c,...) P##c

#define GRAIL_PP_LEFT(P,x...) P##x

#define GRAIL_PP_EMPTY

#define GRAIL_PP_SEQ_HEAD(P,s) GRAIL_PP_SCAN(GRAIL_PP_TUPLE_AT_2 GRAIL_PP_EMPTY (,,,GRAIL_PP_X_COMMA P##s))
#define GRAIL_PP_X_COMMA(x...) GRAIL_PP_LEFT(,##x),

#define GRAIL_PP_SEQ_FOREACH(P,f,s) \
P##f (GRAIL_PP_SEQ_HEAD (s)) \
GRAIL_PP_SEQ_FOREACH_R(,P##s) \
GRAIL_PP_IS_NIL(,GRAIL_PP_EAT s) (GRAIL_PP_,EAT,SEQ_FOREACH) (,P##f,GRAIL_PP_EAT s)

#define GRAIL_PP_SEQ_FOREACH_R(P,s) GRAIL_PP_IS_NIL(,P##s) (GRAIL_PP_,EAT,REVIVE) (GRAIL_PP_SEQ_FOREACH)
