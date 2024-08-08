#include <stdlib.h>
#include "binarytree.h"

tree_node_t *create_node(char val)
{   
    tree_node_t *new_node = (tree_node_t *)malloc(sizeof(tree_node_t));
    if(new_node != NULL) {
        new_node->data = val;
        new_node->right = NULL;
        new_node->left = NULL;
    }
    return new_node;
}

tree_node_t *insert_left(tree_node_t *root, char val)
{
    if(root) {
        root->left = create_node(val);
        return root->left;
    }
    return NULL;
}

tree_node_t *find_left(tree_node_t *node, char val)
{
    if(node == NULL) {
        return NULL;
    }
    if(node->left->data == val) {
        return node;
    }
    return NULL;
}

tree_node_t *find_right(tree_node_t *node, char val)
{
    if(node == NULL) {
        return NULL;
    }
    if(node->right->data == val) {
        return node;
    }
    return NULL;
}


tree_node_t *insert_right(tree_node_t *root, char val)
{
    if(root) {
        root->right = create_node(val);
        return root->right;
    }
    return NULL;
}
 
// // left, then right
// void inorder_traversal(tree_node_t *root)
// {

// }

// // right, then left
// void preorder_traversal(tree_node_t *root)
// {

// }

tree_node_t* search_node(tree_node_t *root, char target)
{
    tree_node_t *node = root;
    if(root == NULL || root->data == target) {
        return root;
    }
    if(node) {
        if(node->data == target) {
            return node;
        }
        else {
            search_node(node->left, target);
            search_node(node->right, target);
        }
    }
    return NULL;
}

void free_tree(tree_node_t *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}




