#include <stdlib.h>

int *ft_range(int min, int max) {
    int i;
    int size;
    int *array; 
    
    if (min >= max) 
        return NULL;
    size = max - min;
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL)
        return NULL;
    i = 0;
    while (min < max) {
        array[i] = min;
        min++;
        i++;
    }
    return (array);
}
