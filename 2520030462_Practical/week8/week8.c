#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, *b;

    a = (int*)malloc(5 * sizeof(int));
    b = (int*)calloc(5, sizeof(int));

    a = (int*)realloc(a, 10 * sizeof(int));

    printf("Memory allocated using malloc\n");
    printf("Memory allocated using calloc\n");
    printf("Memory resized using realloc\n");

    free(a);
    free(b);

    printf("Memory released successfully\n");

    return 0;
}
