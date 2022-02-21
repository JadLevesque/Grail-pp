#include <stdio.h>

#include "grail_pp.h"


#define PLUS_1(x...) 1 +

#define PLUS_SEQ_SIZE(s...) GRAIL_PP_SEQ_FOREACH(,PLUS_1,s)

int main () {
    printf ("%i", PLUS_SEQ_SIZE(()()()()()()()()()()()()()()()) 1);
}
