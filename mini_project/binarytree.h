#ifndef __BINARY_TREE__
#define __BINARY_TREE__

typedef struct _tree_node
{
    char data;
    struct _tree_node *left;
    struct _tree_node *right;
} tree_node_t;

tree_node_t *create_node(char val);

tree_node_t *insert_left(tree_node_t *root, char val);

tree_node_t *find_left(tree_node_t *node, char val);

tree_node_t *insert_right(tree_node_t *root, char val);

tree_node_t *find_right(tree_node_t *node, char val);

void free_tree(tree_node_t *root);

#endif