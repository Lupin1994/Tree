
typedef struct Tnode Ttree;

struct Tnode
{
    int value;
    struct Tnode *left_node;
    struct Tnode *right_node;
    struct tree *parent_node;
};


