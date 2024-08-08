#include <stdlib.h>
#include <stdio.h>
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

void print_tree(tree_node_t *root, int level) {
    if (root == NULL) {
        return;
    }

    print_tree(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    
    printf("%c\n", root->data);
    print_tree(root->left, level + 1);
}

void free_tree(tree_node_t *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}




