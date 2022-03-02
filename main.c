#include <stdio.h>

#include "grail_pp.h"


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
