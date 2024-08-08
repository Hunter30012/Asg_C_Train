#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarytree.h"

#define MAX 512

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

char* encode_line(char *str_to_encode, int size, tree_node_t *root)
{
    int dot = 0;
    int dash = 0;
    char *output = (char *) malloc(MAX * sizeof(char));
    int len = 0;
    int j;
    char temp[10];

    for(int i = 0; i < strlen(str_to_encode); i++) {
        dot = 0;
        dash = 0;
        // check alpha
        if(str_to_encode[i] == ' ') {
            output[len++] = ' ';
            output[len++] = ' ';
            output[len++] = ' ';
        }
        j = 0;

        while ()
        {
            /* code */
        }
        
    }
}

char* decode_line(char *str_to_decode, int size)
{

}

int main()
{
    tree_node_t *tree = create_node('*'); // root of tree

    // 1st Level
    tree_node_t *level1_left = insert_left(tree, 'E');
    tree_node_t *level1_right = insert_right(tree, 'T');

    // 2nd Level
    tree_node_t *level2_left_left = insert_left(level1_left, 'I');
    tree_node_t *level2_left_right = insert_right(level1_left, 'A');
    tree_node_t *level2_right_left = insert_left(level1_right, 'N');
    tree_node_t *level2_right_right = insert_right(level1_right, 'M');

    // 3rd Level
    tree_node_t *level3_left_left_left = insert_left(level2_left_left, 'S');
    tree_node_t *level3_left_left_right = insert_right(level2_left_left, 'U');
    tree_node_t *level3_left_right_left = insert_left(level2_left_right, 'R');
    tree_node_t *level3_left_right_right = insert_right(level2_left_right, 'W');

    tree_node_t *level3_right_left_left = insert_left(level2_right_left, 'D');
    tree_node_t *level3_right_left_right = insert_right(level2_right_left, 'K');
    tree_node_t *level3_right_right_left = insert_left(level2_right_right, 'G');
    tree_node_t *level3_right_right_right = insert_right(level2_right_right, 'O');

    // 4th Level
    insert_left(level3_left_left_left, 'H');
    insert_right(level3_left_left_left, 'V');
    insert_left(level3_left_left_right, 'F');
    insert_right(level3_left_left_right, '\0');
    insert_left(level3_left_right_left, 'L');
    insert_right(level3_left_right_left, '\0');
    insert_left(level3_left_right_right, 'P');
    insert_right(level3_left_right_right, 'J');

    insert_left(level3_right_left_left, 'B');
    insert_right(level3_right_left_left, 'X');
    insert_left(level3_right_left_right, 'C');
    insert_right(level3_right_left_right, 'Y');
    insert_left(level3_right_right_left, 'Z');
    insert_right(level3_right_right_left, 'Q');
    insert_left(level3_right_right_right, '\0');
    insert_right(level3_right_right_right, '\0');


    // print_tree(tree, 0);
    int selection;
    char encode_file[MAX], decode_file[MAX];
    char *encode_str, *decode_str;

    printf("Seclet 1 (encoding) or 2 (decoding): ");
    scanf("%d", &selection);
    if(selection == 1) {
        printf("Enter your encoded text or file: ");
        fgets(encode_file, MAX, stdin);
        encode_file[strcspn(encode_file, "\n")] = '\0';

        printf("Your decoded text/file is: ");
        fgets(decode_file, MAX, stdin);
        encode_file[strcspn(encode_file, "\n")] = '\0';        
    }
    else if(selection == 2) {
        
    }

    free(tree);

    return 0;
}