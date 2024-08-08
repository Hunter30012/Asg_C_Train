#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "morse.h"

bool get_morse_code(tree_node_t *node, char character, char *code, int depth)
{
    if (node == NULL) {
        return false;
    } else if (node->data == character) {
        code[depth] = '\0';
        return true;
    } else {
        code[depth] = '.';
        if (get_morse_code(node->left, character, code, depth + 1)) {
            return true;
        }
        code[depth] = '-';
        if (get_morse_code(node->right, character, code, depth + 1)) {
            return true;
        }
    }
    return false;
}

char* encode_line(char *str_to_encode, tree_node_t *root) 
{
    char *morse_code = (char *)malloc(MAX * sizeof(char));
    char character_code[10];
    char ch;

    if (morse_code == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    morse_code[0] = '\0';

    for (int i = 0; i < strlen(str_to_encode); i++) {
        ch = str_to_encode[i];

        if (ch == ' ') {
            if (i > 0 && str_to_encode[i - 1] != ' ') {
                strcat(morse_code, "   "); // Add 3 space
            }
        } else {
            if(ch >= 'a' && ch <= 'z') {
                ch = ch - 32;
            }

            if (get_morse_code(root, ch, character_code, 0)) {
                strcat(morse_code, character_code);
                if (i < strlen(str_to_encode) - 1 && str_to_encode[i + 1] != ' ') {
                    strcat(morse_code, " ");
                }
            } else {
                char str[2] = {ch, '\0'};
                strcat(morse_code, str);
                if (i < strlen(str_to_encode) - 1 && str_to_encode[i + 1] != ' ') {
                    strcat(morse_code, " ");
                }
            }
        }
    }
    return morse_code;
}

char* decode_morse_code(const char *morse_code, tree_node_t *root) 
{
    tree_node_t *current = root;
    char *decoded_string = (char *)malloc(MAX * sizeof(char));
    char ch;
    int morse_char_started = 0;

    if (root == NULL) {
        printf("Tree is empty\n");
        return NULL;
    }

    if (decoded_string == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    decoded_string[0] = '\0';

    for (int i = 0; i <= strlen(morse_code); i++) {
        ch = morse_code[i];

        if (ch == '.' || ch == '-') {
            morse_char_started = 1;
            if (ch == '.') {
                if (current != NULL) {
                    current = current->left;
                }
            } else if (ch == '-') {
                if (current != NULL) {
                    current = current->right;
                }
            }
        } else if (ch == ' ' || ch == '\0') {
            if (morse_char_started) {
                if (current != NULL && current->data != '\0') {
                    strncat(decoded_string, &current->data, 1);
                }
                current = root;
                morse_char_started = 0;
            }

            if (ch == ' ' && morse_code[i + 1] == ' ' && morse_code[i + 2] == ' ') {
                strcat(decoded_string, " ");
                i += 2;
            }
        } else {
            strncat(decoded_string, &ch, 1);
            current = root;
            morse_char_started = 0;
        }
    }

    return decoded_string;
}

tree_node_t* initialize_morse_tree() {
    tree_node_t *root = create_node('*'); // Root node

    // Level 1
    root->left = create_node('E');
    root->right = create_node('T');

    // Level 2
    root->left->left = create_node('I');
    root->left->right = create_node('A');
    root->right->left = create_node('N');
    root->right->right = create_node('M');

    // Level 3
    root->left->left->left = create_node('S');
    root->left->left->right = create_node('U');
    root->left->right->left = create_node('R');
    root->left->right->right = create_node('W');
    root->right->left->left = create_node('D');
    root->right->left->right = create_node('K');
    root->right->right->left = create_node('G');
    root->right->right->right = create_node('O');

    // Level 4
    root->left->left->left->left = create_node('H');
    root->left->left->left->right = create_node('V');
    root->left->left->right->left = create_node('F');
    root->left->left->right->right = create_node('\0');
    root->left->right->left->left = create_node('L');
    root->left->right->left->right = create_node('\0');
    root->left->right->right->left = create_node('P');
    root->left->right->right->right = create_node('J');
    root->right->left->left->left = create_node('B');
    root->right->left->left->right = create_node('X');
    root->right->left->right->left = create_node('C');
    root->right->left->right->right = create_node('Y');
    root->right->right->left->left = create_node('Z');
    root->right->right->left->right = create_node('Q');
    root->right->right->right->left = create_node('\0');
    root->right->right->right->right = create_node('\0');

    return root;
}