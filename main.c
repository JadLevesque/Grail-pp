#include <stdio.h>

#include "grail_pp.h"

#if 0
#define PLUS(x,y) x + y
#define PAIR(rec,x) {x, rec}

GRAIL_PP_FOLD_ARGS (PAIR, 0,1,2,3,4,5)
GRAIL_PP_FOLD_ARGS (PLUS, 0,1,2,3,4,5)

#define INC(x) x + 1


GRAIL_PP_SCAN (GRAIL_PP_FOLD_ARGS GRAIL_PP_EMPTY(PAIR, GRAIL_PP_MAP_ARGS (INC,1,2,3,4,5))))

#define foo \
GRAIL_PP_REVIVE(GRAIL_PP_SEQ_FOREACH) \
GRAIL_PP_SEQ_FOREACH (,INC, (1)(2)(3))

GRAIL_PP_SCAN (GRAIL_PP_SEQ_FOREACH(, GRAIL_PP_STR, (foo) (2) (3)))

  
#define FIB(n...) GRAIL_PP_SCAN (GRAIL_PP_UNTIL (FIB_PRED, FIB_STEP, FIB_OP, 0, 1, n))

#define FIB_OP(a,b,n...) a,

#define FIB_PRED(a,b,n...) GRAIL_PP_IS_EMPTY_VA_ARGS(n)

#define FIB_STEP(a,b,x,v...) b,(a+b),v

#else

int main () {
    int a[] = {FIB(,,,,,,,,,)};
    int i;

    for (i = 0; i < sizeof a / sizeof a[0]; i++) {
        printf ("%i\n", a [i]);
    }
}
#endif
