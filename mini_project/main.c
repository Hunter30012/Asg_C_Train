#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarytree.h"
#include "morse.h"

int main()
{
    int selection;
    char input_file[MAX], output_file[MAX];
    char buffer[MAX];
    FILE *fin, *fout;
    char *result;
    tree_node_t *morse_tree = initialize_morse_tree();

    printf("Select 1 (encoding) or 2 (decoding): ");
    scanf("%d", &selection);
    getchar();

    if (selection == 1) {
        printf("Enter your encoded text or file: ");
        fgets(input_file, MAX, stdin);
        input_file[strcspn(input_file, "\n")] = '\0';

        printf("Your decoded text/file is: ");
        fgets(output_file, MAX, stdin);
        output_file[strcspn(output_file, "\n")] = '\0';

        fin = fopen(input_file, "r");
        if (!fin) {
            perror("Failed to open input file");
            return 1;
        }

        fout = fopen(output_file, "w");
        if (!fout) {
            perror("Failed to open output file");
            fclose(fin);
            return 1;
        }

        while (fgets(buffer, MAX, fin)) {
            buffer[strcspn(buffer, "\n")] = '\0';
            result = encode_line(buffer, morse_tree);
            if (result) {
                fprintf(fout, "%s\n", result);
                free(result);
            }
        }

        fclose(fin);
        fclose(fout);
    } 
    else if (selection == 2) {
        printf("Enter your decoded text or file: ");
        fgets(input_file, MAX, stdin);
        input_file[strcspn(input_file, "\n")] = '\0';

        printf("Your encoded text/file is: ");
        fgets(output_file, MAX, stdin);
        output_file[strcspn(output_file, "\n")] = '\0';

        fin = fopen(input_file, "r");
        if (!fin) {
            perror("Failed to open input file");
            return 1;
        }

        fout = fopen(output_file, "w");
        if (!fout) {
            perror("Failed to open output file");
            fclose(fin);
            return 1;
        }

        while (fgets(buffer, MAX, fin)) {
            buffer[strcspn(buffer, "\n")] = '\0';
            result = decode_morse_code(buffer, morse_tree);
            if (result) {
                fprintf(fout, "%s\n", result);
                free(result);
            }
        }

        fclose(fin);
        fclose(fout);
    } 
    else {
        printf("Invalid selection.\n");
    }

    free(morse_tree);
    return 0;
}