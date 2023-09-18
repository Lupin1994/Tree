
typedef struct Tnode Ttree;

struct Tnode
{
    int value;
    struct Tnode *left_node;
    struct Tnode *right_node;
    struct Tnode *parent_node;
};

Ttree* tree_create(Ttree *root, int value);
Ttree* tree_addNode(Ttree *root, int value);
Ttree* tree_searchValue(Ttree *root, int value);
Ttree* tree_minValue(Ttree *root);
Ttree* tree_maxValue(Ttree *root);
Ttree* function_return_node_toReplace_delete_value(Ttree *root);
Ttree* tree_removeValue(Ttree *root, int value);
void tree_printIn_forwardOrder(Ttree *root);