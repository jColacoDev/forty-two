#include <stdlib.h>
#include <stdio.h>


#define GRID_SIZE 4
#define NUM_DIRECTIONS 4

char *ft_strdup(const char *str) {
    // Calculate the length of the string
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    // Allocate memory for the copy
    char *copy = (char *)malloc((len + 1) * sizeof(char));
    if (copy == NULL) {
        return NULL; // Memory allocation failed
    }
    // Copy the string
    for (int i = 0; i <= len; i++) {
        copy[i] = str[i];
    }
    return copy;
}

int is_delimiter(char c, const char *delim) {
    while (*delim != '\0') {
        if (c == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}

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

    // Allocate memory for the token and copy characters
    char *token = (char *)malloc((value - result + 1) * sizeof(char));
    if (token == NULL) {
        return NULL;  // Memory allocation failed
    }
    ft_strcpy(token, result);  // Copy characters from result to token

    return token;
}



int ft_atoi(const char *str) {
    int result = 0;
    int negative = 0;
    // Handle leading whitespace
    while (str != NULL && (*str == ' ' || *str == '\t' || *str == '\n')) {
        str++;
    }
    // Handle optional sign
    if (*str == '-') {
        negative = 1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    // Convert digits to integer
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    // Apply sign
    if (negative) {
        result = -result;
    }
    return result;
}

int is_number(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

void print_views(int *views[]) {
    printf("Views matrix:\n");
    for (int i = 0; i < NUM_DIRECTIONS; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", views[i][j]);
        }
        printf("\n");
    }
}

int init_views_xargs(int argc, char *argv[], int *views[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"\n", argv[0]);
        return -1;
    }

    char *arg = argv[1]; // Extract numbers from the second argument
    if (arg == NULL || *arg == '\0') {
        fprintf(stderr, "No input provided.\n");
        return -1;
    }

    // Count the number of tokens in arg
    int numCount = 0;
    char *arg_copy = ft_strdup(arg);
    if (arg_copy == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }
    char *token = ft_strtok(arg_copy, " ");
    while (token) {
        numCount++;
        token = ft_strtok(NULL, " ");
    }
    free(arg_copy); // Free the memory allocated for arg_copy

    // Check if the correct number of numbers is provided
    if (numCount != GRID_SIZE * NUM_DIRECTIONS && numCount != 0) {
        fprintf(stderr, "Incorrect number of numbers: %d\n", numCount);
        fprintf(stderr, "Expected: %d\n", GRID_SIZE * NUM_DIRECTIONS);
        return -1;
    }

    // Initialize views array
    for (int i = 0; i < NUM_DIRECTIONS; i++) {
        views[i] = (int *)malloc(GRID_SIZE * sizeof(int));
        if (views[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return -1;
        }
        // Initialize each element to a default value (e.g., 0)
        for (int j = 0; j < GRID_SIZE; j++) {
            views[i][j] = 0;
        }
    }

    // Tokenize arg again and populate views array
    arg_copy = ft_strdup(arg);
    if (arg_copy == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }
    token = ft_strtok(arg_copy, " ");
    numCount = 0;
    while (token) {
        views[numCount / GRID_SIZE][numCount % GRID_SIZE] = ft_atoi(token);
        numCount++;
        token = ft_strtok(NULL, " ");
    }
    free(arg_copy); // Free the memory allocated for arg_copy

    return 1; // Success
}
