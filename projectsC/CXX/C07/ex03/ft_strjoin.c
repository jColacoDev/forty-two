#include <stdlib.h>

int ft_strlen(char *str) {
    int count = 0;
    while (*str) {
        count++;
        str++;
    }
    return (count);
}

int calculate_total_length(int size, char **strs, char *sep) {
    int total_length;
    int i;

    total_length = 0;
    i = 0;
    while (i < size) {
        total_length += ft_strlen(strs[i]);
        i++;
    }
    total_length += (size - 1) * ft_strlen(sep);
    
    return (total_length);
}

char *allocate_memory(int total_length) {
    char *result;
    result = (char *)malloc((total_length + 1) * sizeof(char));
    if (result == NULL)
        return NULL;

    return (result);
}

void concat_strings(int size, char **strs, char *sep, char *result) {
    int malloc_index;
    int sep_len;
    int str_len;
    int i;

    malloc_index = 0;
    sep_len = ft_strlen(sep);
    i = 0;
    while (i < size) {
        str_len = ft_strlen(strs[i]);
        ft_strcpy(result + malloc_index, strs[i]);
        malloc_index += str_len;
        if (i < size - 1) {
            ft_strcpy(result + malloc_index, sep);
            malloc_index += sep_len;
        }
        i++;
    }
}

char *ft_strjoin(int size, char **strs, char *sep) {
    char *result;
    int total_length;
    char *result;

    if (size <= 0) {
        result = (char *)malloc(sizeof(char));
        if (result == NULL)
            return (NULL);
        *result = '\0';
        return (result);
    }
    total_length = calculate_total_length(size, strs, sep);
    result = allocate_memory(total_length);
    if (result == NULL)
        return (NULL);
    concat_strings(size, strs, sep, result);
    result[total_length] = '\0';
    return (result);
}
