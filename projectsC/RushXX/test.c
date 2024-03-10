#include <stdio.h>
#include <stdlib.h>

#define is_delimiter(c, delim) ((delim) != NULL && strchr((delim), (c)) != NULL)

char *ft_strcpy(char *dest, const char *src) {
    char *start = dest;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0'; // Null-terminate the destination string
    return start;
}

char *ft_strtok(char *str, const char *delim) {
    static char *value;
    static char *next_value;
    char *result;

    if (str) {
        value = str;
    } else {
        value = next_value;
    }
    if (value == NULL) {
        return NULL;
    }

    // Skip leading delimiters
    while (*value != '\0' && is_delimiter(*value, delim)) {
        value++;
    }

    if (*value == '\0') {
        return NULL;
    }

    result = value;

    // Find the end of the value
    while (*value != '\0' && !is_delimiter(*value, delim)) {
        value++;
    }

    if (*value != '\0') {
        *value = '\0';  // Replace delimiter with null terminator
        value++;
        next_value = value;
    } else {
        next_value = NULL;
    }

    return result;
}

int main() {
    char str[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
    char *delim = " ";
    int numCount = 0;
    int values[16]; // Assuming maximum of 16 integers

    char *token = ft_strtok(str, delim);
    while (token != NULL) {
        values[numCount++] = atoi(token);
        token = ft_strtok(NULL, delim);
    }

    // Print the input values
    for (int i = 0; i < numCount; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    return 0;
}
