#include <stdio.h>
#include <stdlib.h>

int* move_even_odd(int *array, int n)
{
    int *output;
    int low, high;
    low = 0;
    high = n-1;
    output = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        if(array[i] % 2 == 0) {
            output[high--] = array[i];
        }
        else {
            output[low++] = array[i];
        }
    }
    return output;
}

int main(int argc, char** argv)
{
    int *array, *a_out;
    int n, L;
    float avge;

    do
    {
        printf("N: ");
        scanf("%d", &n);   
    } while (n > 50);

    avge = 0;
    array = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
        avge += array[i];
    }
    avge = (float)avge/n;

    L = 0;
    printf("The elements of array: \n");
    for(int i = 0; i < n; i++) {
        printf("array[%d] = %d\n", i, array[i]);
        if(array[i] < avge) {
            L++;
        }
    }
    printf("The value of average: %.2f\n", avge);
    printf("Number of element less than average value: %d\n", L);

    a_out = move_even_odd(array, n);
    printf("The elements of array after move: \n");
    for(int i = 0; i < n; i++) {
        printf("array[%d] = %d\n", i, a_out[i]);
    }    
    free(array);
    free(a_out);

    return 0;
}