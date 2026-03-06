#include "../include/allocator.h"
#include <stdio.h>

int main() {

    printf("Testing custom allocator\n");

    int* arr = (int*) my_malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
        arr[i] = i * 10;

    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    printf("\n");

    my_free(arr);

    printf("Memory freed successfully\n");

    return 0;
}