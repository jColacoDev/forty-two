#include "utils.h"

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstr(char *str) {
    while (*str)
        ft_putchar(*str++);
}

void ft_puterror(char *str) {
    while (*str)
        write(2, str++, 1);
}

int ft_strlen(char *str) {
    int len = 0;
    while (str[len])
        len++;
    return len;
}
