#include <stdio.h>
#include <stdlib.h>

unsigned int cal_size_of_file(char *file_name)
{
    FILE *file = fopen(file_name, "r");

    if(file == NULL) {
        printf("Find not found\n");
        exit(0);
    }
    fseek(file, 0, SEEK_END);

    unsigned int ret = ftell(file);
    fclose(file);

    return ret;
}

int main(int argc, char **argv)
{
    char file_name[30];
    unsigned int size;
    printf("Please enter your file name: ");
    scanf("%s", file_name);
    size = cal_size_of_file(file_name);
    printf("The size of the test.txt file is %u bytes!\n", size);
    return 0;
}