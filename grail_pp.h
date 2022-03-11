#2""3

#define GRAIL_PP_PRAGMA(x) _Pragma(#x)
#define GRAIL_PP_REVIVE(m) GRAIL_PP_PRAGMA(push_macro(#m))GRAIL_PP_PRAGMA(pop_macro(#m))

#define GRAIL_PP_0PSTR(x...) #x
#define GRAIL_PP_0STR(x...) GRAIL_PP_0PSTR(x)

#define GRAIL_PP_CAT(a,b) GRAIL_PP_REVIVE(GRAIL_PP_CAT)GRAIL_PP_PCAT(a,b)
#define GRAIL_PP_RCAT(a,b) GRAIL_PP_REVIVE(GRAIL_PP_RCAT)GRAIL_PP_PCAT(b,a)
#define GRAIL_PP_PCAT(a,b) GRAIL_PP_REVIVE(GRAIL_PP_PCAT)a##b

#define GRAIL_PP_EAT(...)
#define GRAIL_PP_SCAN(x...) GRAIL_PP_REVIVE(GRAIL_PP_SCAN)x
#define GRAIL_PP_EMPTY

#define GRAIL_PP_FX(f,x) GRAIL_PP_REVIVE(GRAIL_PP_FX)GRAIL_PP_##f x

#define GRAIL_PP_TUPLE_AT_0(P,a,...) GRAIL_PP_REVIVE(GRAIL_PP_TUPLE_AT_0) P##a
#define GRAIL_PP_TUPLE_AT_2(P,a,b,c,...) GRAIL_PP_REVIVE(GRAIL_PP_TUPLE_AT_2) P##c

#define GRAIL_PP_0VARG_AT_0(a,...) GRAIL_PP_REVIVE(GRAIL_PP_0VARG_AT_0)a
#define GRAIL_PP_0VARG_AT_1(a,b,...) GRAIL_PP_REVIVE(GRAIL_PP_0VARG_AT_1)b
#define GRAIL_PP_0VARG_AT_2(a,b,c,...) GRAIL_PP_REVIVE(GRAIL_PP_0VARG_AT_2)c
#define GRAIL_PP_0VARG_AT_3(a,b,c,d,...) GRAIL_PP_REVIVE(GRAIL_PP_0VARG_AT_3)d

#define GRAIL_PP_IF_(P,t,f...) GRAIL_PP_REVIVE(GRAIL_PP_IF_)P##f
#define GRAIL_PP_IF_0(P,t,f...) GRAIL_PP_REVIVE(GRAIL_PP_IF_0)P##f
#define GRAIL_PP_IF_1(P,t,f...) GRAIL_PP_REVIVE(GRAIL_PP_IF_1)P##t
#define GRAIL_PP_NIF_(P,t,f...) GRAIL_PP_REVIVE(GRAIL_PP_IF_)P##t
#define GRAIL_PP_NIF_0(P,t,f...) GRAIL_PP_REVIVE(GRAIL_PP_IF_0)P##t
#define GRAIL_PP_NIF_1(P,t,f...) GRAIL_PP_REVIVE(GRAIL_PP_IF_1)P##f


#define GRAIL_PP_SELECT(P,c0,c1) GRAIL_PP_REVIVE(GRAIL_PP_SELECT)GRAIL_PP_CAT(P##c0(GRAIL_PP_SELECT_,1,0),P##c1(,1,0))
#define GRAIL_PP_SELECT_11(P,tt,tf,ft,ff...) GRAIL_PP_REVIVE(GRAIL_PP_SELECT_11)P##tt
#define GRAIL_PP_SELECT_10(P,tt,tf,ft,ff...) GRAIL_PP_REVIVE(GRAIL_PP_SELECT_10)P##tf
#define GRAIL_PP_SELECT_01(P,tt,tf,ft,ff...) GRAIL_PP_REVIVE(GRAIL_PP_SELECT_01)P##ft
#define GRAIL_PP_SELECT_00(P,tt,tf,ft,ff...) GRAIL_PP_REVIVE(GRAIL_PP_SELECT_00)P##ff

#define GRAIL_PP_AND(t) GRAIL_PP_REVIVE(GRAIL_PP_AND)GRAIL_PP_AND_##t
#define GRAIL_PP_AND_(P,t,...) GRAIL_PP_REVIVE(GRAIL_PP_AND_)P##t
#define GRAIL_PP_AND_and(c) GRAIL_PP_REVIVE(GRAIL_PP_AND_and)c(GRAIL_PP_,AND,FALSE)
#define GRAIL_PP_AND_not(c) GRAIL_PP_REVIVE(GRAIL_PP_AND_not)c(GRAIL_PP_,FALSE,AND)

#define GRAIL_PP_FALSE(t) GRAIL_PP_REVIVE(GRAIL_PP_FALSE)GRAIL_PP_FALSE_##t
#define GRAIL_PP_FALSE_(P,t,f...) GRAIL_PP_REVIVE(GRAIL_PP_FALSE_)P##f
#define GRAIL_PP_FALSE_and(c) GRAIL_PP_REVIVE(GRAIL_PP_FALSE_and)GRAIL_PP_FALSE
#define GRAIL_PP_FALSE_not(c) GRAIL_PP_REVIVE(GRAIL_PP_FALSE_not)GRAIL_PP_FALSE

#define GRAIL_PP_OR(t) GRAIL_PP_REVIVE(GRAIL_PP_OR)GRAIL_PP_OR_##t
#define GRAIL_PP_OR_(P,t,f...) GRAIL_PP_REVIVE(GRAIL_PP_OR_)P##f
#define GRAIL_PP_OR_or(c) GRAIL_PP_REVIVE(GRAIL_PP_OR_or)c(GRAIL_PP_,TRUE,OR)
#define GRAIL_PP_OR_not(c) GRAIL_PP_REVIVE(GRAIL_PP_OR_not)c(GRAIL_PP_,OR,TRUE)

#define GRAIL_PP_TRUE(t) GRAIL_PP_REVIVE(GRAIL_PP_TRUE)GRAIL_PP_TRUE_##t
#define GRAIL_PP_TRUE_(P,t,...) GRAIL_PP_REVIVE(GRAIL_PP_TRUE_)P##t
#define GRAIL_PP_TRUE_not(c) GRAIL_PP_REVIVE(GRAIL_PP_TRUE_not)GRAIL_PP_TRUE
#define GRAIL_PP_TRUE_or(c) GRAIL_PP_REVIVE(GRAIL_PP_TRUE_or)GRAIL_PP_TRUE


#define GRAIL_PP_IS_NIL_TEST(x...) ,##x

#define GRAIL_PP_IS_NIL(P,x) GRAIL_PP_SCAN(GRAIL_PP_TUPLE_AT_2 GRAIL_PP_EAT() (GRAIL_PP_IF_,GRAIL_PP_IS_NIL_TEST(x),0,1))

#define GRAIL_PP_0VARG_IS_EMPTY(P...) GRAIL_PP_SCAN(GRAIL_PP_TUPLE_AT_0 GRAIL_PP_EMPTY (GRAIL_PP_IF_,,##P 1))
#define GRAIL_PP_0VARG_ISNT_EMPTY(P...) GRAIL_PP_SCAN(GRAIL_PP_TUPLE_AT_0 GRAIL_PP_EMPTY (GRAIL_PP_IF_,,##P 0))

#if 0
#define GRAIL_PP_0VARG_IS_EMPTY(...) GRAIL_PP_CAT(GRAIL_PP_NIF_, __VA_OPT__(1))
GRAIL_PP_0VARG_IS_EMPTY () (,true,false)
GRAIL_PP_0VARG_IS_EMPTY (1) (,true,false)
#endif

#define GRAIL_PP_LEFT(P,x...) GRAIL_PP_REVIVE(GRAIL_PP_LEFT)P##x

#define GRAIL_PP_SEQ_HEAD(P,s) GRAIL_PP_SCAN(GRAIL_PP_TUPLE_AT_0 GRAIL_PP_EMPTY(,GRAIL_PP_X_COMMA P##s))
#define GRAIL_PP_X_COMMA(x...) GRAIL_PP_LEFT(,##x),


//OPTIMISE
#define GRAIL_PP_SEQ_FOREACH(P,f,s) \
GRAIL_PP_REVIVE(GRAIL_PP_SEQ_FOREACH) \
GRAIL_PP_0VARG_IS_EMPTY(s)(GRAIL_PP_SEQ_FOREACH_,STOP,LOOP)(,P##f,P##s)

#define GRAIL_PP_SEQ_FOREACH_LOOP(P,f,s) \
GRAIL_PP_REVIVE(GRAIL_PP_SEQ_FOREACH_LOOP) \
P##f(GRAIL_PP_SEQ_HEAD(,s)) \
GRAIL_PP_SCAN(GRAIL_PP_SEQ_FOREACH GRAIL_PP_EMPTY(,f,GRAIL_PP_EAT s))

#define GRAIL_PP_SEQ_FOREACH_STOP(P,f,_) GRAIL_PP_REVIVE(GRAIL_PP_SEQ_FOREACH_STOP)


//OPTIMISE
#define GRAIL_PP_0FOLD_ARGS(f, x, args...) \
GRAIL_PP_REVIVE (GRAIL_PP_0FOLD_ARGS) \
GRAIL_PP_0VARG_IS_EMPTY(args) (GRAIL_PP_0FOLD_ARGS_,STOP,LOOP) (f,x,args)

#define GRAIL_PP_0FOLD_ARGS_LOOP(f,x,args...) \
GRAIL_PP_REVIVE (GRAIL_PP_0FOLD_ARGS_LOOP) \
f (GRAIL_PP_0FOLD_ARGS (f,args),x)

#define GRAIL_PP_0FOLD_ARGS_STOP(f,x,...) GRAIL_PP_REVIVE (GRAIL_PP_0FOLD_ARGS_STOP) x


#define GRAIL_PP_0TUPLE_FOLD(f,x,t) GRAIL_PP_0FOLD_ARGS(f,x,GRAIL_PP_SCAN t)


#if 0
#define GRAIL_PP_0MAP_ARGS(f,x,args...) \
GRAIL_PP_REVIVE(GRAIL_PP_0MAP_ARGS) \
GRAIL_PP_0VARG_IS_EMPTY(args) (GRAIL_PP_0MAP_ARGS_,STOP,LOOP) (f,x,args)

#define GRAIL_PP_0MAP_ARGS_LOOP(f,x,args...) \
GRAIL_PP_REVIVE(GRAIL_PP_0MAP_ARGS_LOOP) \
f (x),GRAIL_PP_0MAP_ARGS(f,args)

#define GRAIL_PP_0MAP_ARGS_STOP(f,x,...) \
GRAIL_PP_REVIVE(GRAIL_PP_0MAP_ARGS_STOP) \
f(x)
#else
#define GRAIL_PP_0MAP_ARGS(f,x,args...) \
GRAIL_PP_REVIVE(GRAIL_PP_0MAP_ARGS) \
GRAIL_PP_0VARG_IS_EMPTY(args)(,f(x),f(x),GRAIL_PP_0MAP_ARGS(f,args)) 
#endif


#define GRAIL_PP_UNTIL(p,s,o,x...) \
GRAIL_PP_REVIVE (GRAIL_PP_UNTIL) \
p(x)(GRAIL_PP_UNTIL_,STOP,LOOP)(p,s,o,x)

#define GRAIL_PP_UNTIL_LOOP(p,s,o,x...) \
GRAIL_PP_REVIVE (GRAIL_PP_UNTIL_LOOP) \
o (x) \
GRAIL_PP_SCAN (GRAIL_PP_UNTIL GRAIL_PP_EMPTY (p,s,o, s (x)))

#define GRAIL_PP_UNTIL_STOP(p,s,o,x...) GRAIL_PP_REVIVE(GRAIL_PP_UNTIL_STOP) x


//OPTIMISE
#define GRAIL_PP_0IS_1(x...) \
GRAIL_PP_REVIVE(GRAIL_PP_0IS_1) \
GRAIL_PP_SCAN(GRAIL_PP_0VARG_IS_EMPTY(x)(,GRAIL_PP_IF_,GRAIL_PP_0VARG_IS_EMPTY GRAIL_PP_0DEC (x)))


#define GRAIL_PP_0EQ(a,b) \
GRAIL_PP_REVIVE(GRAIL_PP_0EQ) \
GRAIL_PP_SELECT(,GRAIL_PP_0VARG_IS_EMPTY a,GRAIL_PP_0VARG_IS_EMPTY b) \
(GRAIL_PP_,IF_1,IF_,IF_,0EQ(GRAIL_PP_0DEC a,GRAIL_PP_0DEC b))

#define GRAIL_PP_0LQT(a,b) \
GRAIL_PP_REVIVE(GRAIL_PP_0LQT) \
GRAIL_PP_SELECT(,GRAIL_PP_0VARG_IS_EMPTY a,GRAIL_PP_0VARG_IS_EMPTY b) \
(GRAIL_PP_,IF_1,IF_1,IF_,0LQT(GRAIL_PP_0DEC a,GRAIL_PP_0DEC b))
//GRAIL_PP_0LQT((,),(,)) (,true,false)

#define GRAIL_PP_0LT(a,b) \
GRAIL_PP_REVIVE(GRAIL_PP_0LT) \
GRAIL_PP_SELECT(,GRAIL_PP_0VARG_IS_EMPTY a,GRAIL_PP_0VARG_IS_EMPTY b) \
(GRAIL_PP_,IF_,IF_1,IF_,0LT(GRAIL_PP_0DEC a,GRAIL_PP_0DEC b))
//GRAIL_PP_0LT((),()) (,true,false)

#define GRAIL_PP_0GQT(a,b) \
GRAIL_PP_REVIVE(GRAIL_PP_0GQT) \
GRAIL_PP_SELECT(,GRAIL_PP_0VARG_IS_EMPTY a,GRAIL_PP_0VARG_IS_EMPTY b) \
(GRAIL_PP_,IF_1,IF_,IF_1,0GQT(GRAIL_PP_0DEC a,GRAIL_PP_0DEC b))
//GRAIL_PP_0GQT((), ()) (,true,false)

#define GRAIL_PP_0GT(a,b) \
GRAIL_PP_REVIVE(GRAIL_PP_0GT) \
GRAIL_PP_SELECT(,GRAIL_PP_0VARG_IS_EMPTY a,GRAIL_PP_0VARG_IS_EMPTY b) \
(GRAIL_PP_,IF_,IF_,IF_1,0GT(GRAIL_PP_0DEC a,GRAIL_PP_0DEC b))
//GRAIL_PP_0GT((), (,,)) (,true,false)


#define GRAIL_PP_0INC(x...) GRAIL_PP_REVIVE(GRAIL_PP_0INC)(,x)
#define GRAIL_PP_0DEC(P,x...) GRAIL_PP_REVIVE(GRAIL_PP_0DEC)(x)


#define GRAIL_PP_0PLUS(a,b) \
GRAIL_PP_REVIVE(GRAIL_PP_0PLUS) \
GRAIL_PP_SCAN (GRAIL_PP_0VARG_IS_EMPTY a (,b,GRAIL_PP_0PLUS (GRAIL_PP_0DEC a, GRAIL_PP_0INC b)))


#define GRAIL_PP_0TIMES(a,b) \
GRAIL_PP_REVIVE(GRAIL_PP_0TIMES) \
GRAIL_PP_0VARG_IS_EMPTY a (,() GRAIL_PP_EAT,GRAIL_PP_0VARG_IS_EMPTY b) (,(),GRAIL_PP_0TIMES_A (a,b,()))

#define GRAIL_PP_0TIMES_A(a,b,r) \
GRAIL_PP_REVIVE(GRAIL_PP_0TIMES_A) \
GRAIL_PP_0VARG_IS_EMPTY a (,r,GRAIL_PP_0TIMES_A (GRAIL_PP_0DEC a, b, GRAIL_PP_0PLUS (r,b)))


#define GRAIL_PP_0MINUS(a,b) \
GRAIL_PP_REVIVE(GRAIL_PP_0MINUS) \
GRAIL_PP_0VARG_IS_EMPTY a (,b,GRAIL_PP_0MINUS (GRAIL_PP_0DEC a, GRAIL_PP_0DEC b))


#define GRAIL_PP_0REPEAT(x,n) \
GRAIL_PP_REVIVE(GRAIL_PP_0REPEAT) \
(GRAIL_PP_SCAN(GRAIL_PP_LEFT GRAIL_PP_0REPEAT_I (x,n,())))

#define GRAIL_PP_0REPEAT_I(x,n,r) \
GRAIL_PP_REVIVE(GRAIL_PP_0REPEAT_I) \
GRAIL_PP_0VARG_IS_EMPTY n(,r,GRAIL_PP_0REPEAT_I(x,GRAIL_PP_0DEC n,(GRAIL_PP_SCAN r,x)))

#if 0
#define GRAIL_PP_0TUPLE_ZIP_WITH(f,l,r) \
GRAIL_PP_REVIVE(GRAIL_PP_0TUPLE_ZIP_WITH) \
GRAIL_PP_SCAN(GRAIL_PP_0VARG_IS_EMPTY l(,GRAIL_PP_EAT GRAIL_PP_EAT,GRAIL_PP_0VARG_IS_EMPTY) r \
(,,f(GRAIL_PP_0VARG_AT_0 l,GRAIL_PP_0VARG_AT_0 r)GRAIL_PP_0TUPLE_ZIP_WITH_I(f,GRAIL_PP_0DEC l, GRAIL_PP_0DEC r)))

#define GRAIL_PP_0TUPLE_ZIP_WITH_I(f,l,r) \
GRAIL_PP_REVIVE(GRAIL_PP_0TUPLE_ZIP_WITH_I) \
GRAIL_PP_SCAN(GRAIL_PP_0VARG_IS_EMPTY l \
(,GRAIL_PP_EAT GRAIL_PP_EAT,GRAIL_PP_0VARG_IS_EMPTY) r \
(,GRAIL_PP_EAT GRAIL_PP_EAT,,f(GRAIL_PP_0VARG_AT_0 l,GRAIL_PP_0VARG_AT_0 r)GRAIL_PP_0TUPLE_ZIP_WITH_I GRAIL_PP_EMPTY(f,GRAIL_PP_0DEC l,GRAIL_PP_0DEC r)))
#else

#define GRAIL_PP_0TUPLE_ZIP_WITH(f,l,r) \
GRAIL_PP_REVIVE(GRAIL_PP_0TUPLE_ZIP_WITH) \
GRAIL_PP_OR(or)(GRAIL_PP_0VARG_IS_EMPTY l)(or)(GRAIL_PP_0VARG_IS_EMPTY r)() \
(,,f(GRAIL_PP_0VARG_AT_0 l,GRAIL_PP_0VARG_AT_0 r)GRAIL_PP_0TUPLE_ZIP_WITH_I(f,GRAIL_PP_0DEC l,GRAIL_PP_0DEC r))

#define GRAIL_PP_0TUPLE_ZIP_WITH_I(f,l,r) \
GRAIL_PP_REVIVE(GRAIL_PP_0TUPLE_ZIP_WITH_I) \
GRAIL_PP_OR(or)(GRAIL_PP_0VARG_IS_EMPTY l)(or)(GRAIL_PP_0VARG_IS_EMPTY r)() \
(,,,f(GRAIL_PP_0VARG_AT_0 l,GRAIL_PP_0VARG_AT_0 r)GRAIL_PP_0TUPLE_ZIP_WITH_I(f,GRAIL_PP_0DEC l,GRAIL_PP_0DEC r))
#endif
//GRAIL_PP_SCAN(GRAIL_PP_0TUPLE_ZIP_WITH(,(1,2,3),(a,b,c)))
 
#define GRAIL_PP_0ID(xs...) GRAIL_PP_LEFT(,##xs)
#if 0
#define GRAIL_PP_0TUPLE(xs...) (GRAIL_PP_LEFT(,##xs))
#else
#define GRAIL_PP_0TUPLE
#endif

#define GRAIL_PP_0TO_LIT(x) \
(GRAIL_PP_0TO_LIT_I(x)0)

#define GRAIL_PP_0TO_LIT_I(x) \
GRAIL_PP_REVIVE(GRAIL_PP_0TO_LIT_I) \
GRAIL_PP_0VARG_IS_EMPTY x(,,-~GRAIL_PP_0TO_LIT_I(GRAIL_PP_0DEC x))


#define GRAIL_PP_0VCAT(xs...) GRAIL_PP_0FOLD_ARGS(GRAIL_PP_RCAT,xs)


#define GRAIL_PP_0TUPLE_TAKE(n,t) \
GRAIL_PP_REVIVE(GRAIL_PP_0TUPLE_TAKE) \
(GRAIL_PP_0TUPLE_ZIP_WITH(GRAIL_PP_0VARG_AT_1, n, t))


#define GRAIL_PP_0TUPLE_DROP GRAIL_PP_0MINUS

#define GRAIL_PP_0TUPLE_IS_EMPTY(t) GRAIL_PP_0VARG_IS_EMPTY t
#define GRAIL_PP_0TUPLE_ISNT_EMPTY(t) GRAIL_PP_0VARG_ISNT_EMPTY t


#define GRAIL_PP_0VARG_FILTER(f,x,xs...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_FILTER) \
f(x) (,x GRAIL_PP_SCAN, GRAIL_PP_0VARG_IS_EMPTY(xs) (,,GRAIL_PP_0VARG_FILTER (f,xs)) GRAIL_PP_EAT) (GRAIL_PP_0VARG_IS_EMPTY(xs)(,,GRAIL_PP_0VARG_FILTER_I(f,xs)))

#define GRAIL_PP_0VARG_FILTER_I(f,x,xs...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_FILTER_I) \
GRAIL_PP_AND(not)(f(x))()(,,,x) GRAIL_PP_0VARG_IS_EMPTY (xs) (,GRAIL_PP_EAT,GRAIL_PP_0VARG_FILTER_I)(f,xs)
//#define FOO(x) GRAIL_PP_0GT(x, (,))
//GRAIL_PP_SCAN(GRAIL_PP_0VARG_FILTER(FOO, (,,,), (), (), (,,), (), (,))) 


#define GRAIL_PP_0VARG_FILTER_AUX(f,a,x,xs...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_FILTER_AUX) \
f(a,x) (,x GRAIL_PP_SCAN, GRAIL_PP_0VARG_IS_EMPTY(xs) (,,GRAIL_PP_0VARG_FILTER_AUX (f,a,xs)) GRAIL_PP_EAT) (GRAIL_PP_0VARG_IS_EMPTY(xs)(,,GRAIL_PP_0VARG_FILTER_AUX_I(f,a,xs)))

#define GRAIL_PP_0VARG_FILTER_AUX_I(f,a,x,xs...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_FILTER_AUX_I) \
GRAIL_PP_AND(not)(f(a,x))()(,,,x) GRAIL_PP_0VARG_IS_EMPTY (xs) (,GRAIL_PP_EAT,GRAIL_PP_0VARG_FILTER_AUX_I)(f,a,xs)
//GRAIL_PP_SCAN(GRAIL_PP_0VARG_FILTER_AUX(GRAIL_PP_0LT,(,), (,,,), (), (), (,,), (), (,)))


#define GRAIL_PP_0TUPLE_AT(n, t) \
GRAIL_PP_REVIVE(GRAIL_PP_0TUPLE_AT) \
GRAIL_PP_SCAN(GRAIL_PP_0VARG_AT_0 GRAIL_PP_0TUPLE_DROP(n, t))


#define GRAIL_PP_0MIN(a,b) GRAIL_PP_REVIVE(GRAIL_PP_0MIN)GRAIL_PP_0LQT(a,b)(,a,b)
#define GRAIL_PP_0MAX(a,b) GRAIL_PP_REVIVE(GRAIL_PP_0MAX)GRAIL_PP_0GQT(a,b)(,a,b)


#define GRAIL_PP_0VARG_SORT(x,xs...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_SORT) \
GRAIL_PP_0VARG_IS_EMPTY (xs) \
(,x,GRAIL_PP_0VARG_SORT_LC(GRAIL_PP_0VARG_SORT_L(x,xs))x GRAIL_PP_0VARG_SORT_GC(GRAIL_PP_0VARG_SORT_G(x,xs)))

#define GRAIL_PP_0VARG_SORT_L(x,xs...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_SORT_L) \
GRAIL_PP_FX(0VARG_SORT, (GRAIL_PP_0VARG_FILTER_AUX(GRAIL_PP_0GQT,x,xs)))

#define GRAIL_PP_0VARG_SORT_G(x,xs...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_SORT_G) \
GRAIL_PP_FX(0VARG_SORT, (GRAIL_PP_0VARG_FILTER_AUX(GRAIL_PP_0LT,x,xs)))

#define GRAIL_PP_0VARG_SORT_LC(ys...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_SORT_LC) \
GRAIL_PP_FX (0VARG_IS_EMPTY,(ys) (,,ys,))

#define GRAIL_PP_0VARG_SORT_GC(ys...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_SORT_GC) \
GRAIL_PP_FX (0VARG_IS_EMPTY,(ys) (,,,ys))

//GRAIL_PP_SCAN(GRAIL_PP_0VARG_SORT((,,), (,,,,,), (,), (,), (,,,,,,,,,), (,,,), (,,,,), (,), (,,), (,,,)))
//GRAIL_PP_SCAN(GRAIL_PP_0VARG_SORT((,,), (,,,,,)))

 
#define GRAIL_PP_0VARG_TO_LIT(xs...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_TO_LIT) \
GRAIL_PP_FX(0MAP_ARGS, (GRAIL_PP_0TO_LIT, xs))


#define GRAIL_PP_0VARG_SUM(xs...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_SUM) \
GRAIL_PP_0FOLD_ARGS(GRAIL_PP_0PLUS,xs)

//GRAIL_PP_0VARG_SUM((,,,), (,,), (,), (,,,,,,))

#define GRAIL_PP_0VARG_PRODUCT(xs...) \
GRAIL_PP_REVIVE(GRAIL_PP_0VARG_PRODUCT) \
GRAIL_PP_0FOLD_ARGS(GRAIL_PP_0TIMES,xs)

//GRAIL_PP_0VARG_PRODUCT((,,,), (,), (,,,,), (,,,), (,,,,))
