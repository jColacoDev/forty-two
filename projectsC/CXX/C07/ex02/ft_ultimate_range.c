#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max) {
    int i;
    int size;

    if (min >= max) {
        *range = NULL;
        return (-1);     
    }
    size = max - min;
    *range = (int *)malloc(size * sizeof(int));
    if (*range == NULL)
        return (-1);
    i = 0;
    while (min < max) {
        (*range)[i] = min;
        min++;
        i++;
    }

    return (size);
}
