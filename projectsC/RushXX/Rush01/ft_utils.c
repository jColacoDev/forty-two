#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int is_delimiter(char c, const char *delim) {
    while (*delim != '\0') {
        if (c == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}

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

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstr(char *str) {
    while (*str) {
        ft_putchar(*str);
        str++;
    }
}

void ft_putnbr(int n) {
    // Handle negative numbers
    if (n < 0) {
        ft_putchar('-');
        n = -n;
    }
    // Handle the case of n being 0 separately
    if (n == 0) {
        ft_putchar('0');
        return;
    }
    // Initialize variables
    int divisor = 1;
    int temp = n;
    // Find the divisor for the highest order digit
    while (temp >= 10) {
        temp /= 10;
        divisor *= 10;
    }
    // Output each digit one by one using the divisor
    while (divisor > 0) {
        ft_putchar('0' + (n / divisor)); // Output the current digit
        n %= divisor; // Remove the current digit from n
        divisor /= 10; // Update the divisor for the next digit
    }
}