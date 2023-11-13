

typedef struct s_cell{
    int value;
    unsigned int nb_lvl;
    struct s_cell** nexts;
} s_cell;