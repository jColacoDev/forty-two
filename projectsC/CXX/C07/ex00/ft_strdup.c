#include <stdlib.h>
#include <stddef.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char *ft_strcpy(char *dest, const char *src) {
    char *start = dest;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0'; // Null-terminate the destination string
    return start;
}

char *ft_strdup(const char *src) {
    int length = ft_strlen(src) + 1;

    char *copy = (char *)malloc(length);

    if (copy == NULL) 
        return NULL;

    ft_strcpy(copy, src);

    return (copy);
}
