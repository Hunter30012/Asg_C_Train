#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool encrypt(char *filename_input, char *filename_output, unsigned int num_shift)
{
    FILE *input, *output;
    char line[256];
    char base;

    input = fopen(filename_input, "r");
    if(input == NULL) {
        printf("Can't open the input file\n");
        return false;
    }

    output = fopen(filename_output, "w");
    if(output == NULL) {
        printf("Can't open the input file\n");
        fclose(input);
        return false;
    }

    while (fgets(line, sizeof(line), input) != NULL) {
        for(int i = 0; i < strlen(line); i++) {
            if(line[i] >= 'a' || line[i] <= 'z') {
                base = 'a';
                line[i] = (line[i] - base + num_shift) % 26 + base;
            }
            if(line[i] >= 'A' || line[i] <= 'Z') {
                base = 'A';
                line[i] = (line[i] - base + num_shift) % 26 + base;
            }
        }
        fprintf(output, "%s", line);
    }

    fclose(output);
    fclose(input);
    return true;
}

bool decrypt(char *filename_input, char *filename_output, unsigned int num_shift)
{
    FILE *input, *output;
    char line[256];
    char base;

    input = fopen(filename_input, "r");
    if(input == NULL) {
        printf("Can't open the input file\n");
        return false;
    }

    output = fopen(filename_output, "w");
    if(output == NULL) {
        printf("Can't open the input file\n");
        fclose(input);
        return false;
    }

    while (fgets(line, sizeof(line), input) != NULL) {
        for(int i = 0; i < strlen(line); i++) {
            if(line[i] >= 'a' || line[i] <= 'z') {
                base = 'a';
                line[i] = (line[i] - base - num_shift) % 26 + base;
            }
            if(line[i] >= 'A' || line[i] <= 'Z') {
                base = 'A';
                line[i] = (line[i] - base - num_shift) % 26 + base;
            }
        }
        fprintf(output, "%s", line);
    }

    fclose(output);
    fclose(input);
    return true;
}
/**
 * ./exe mode file_input
 */
int main(int argc, char **argv)
{
    unsigned int num_shift;
    if (argc != 3)
    {
        printf("Form: ./exe mode file_input Please run again!\n");
        return 0;
    }
    printf("The mount of shifting: ");
    scanf("%d", &num_shift);
    if(strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2], "decrypt.txt", num_shift);
    }
    else if(strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2], "encrypt.txt", num_shift);
    }
    else {
        return 0;
    }
    return 0;
}