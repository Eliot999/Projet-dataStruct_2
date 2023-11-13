#include "cell.h"

typedef struct l_list{
    unsigned int max_lvl;
    struct cell** heads;
} l_list;

