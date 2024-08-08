#ifndef __MORSE__
#define __MORSE__

#include "binarytree.h"

#define MAX 512

bool get_morse_code(tree_node_t *node, char character, char *code, int depth);

char* encode_line(char *str_to_encode, tree_node_t *root) ;

char* decode_morse_code(const char *morse_code, tree_node_t *root);

tree_node_t* initialize_morse_tree();


#endif