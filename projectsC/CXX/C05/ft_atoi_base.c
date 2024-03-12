/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:16:27 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/12 02:16:27 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
"Write a function that converts the beginning of a string to its integer representation.
• The string is in a specific base passed as the second argument.
• Apart from the base system, this function should replicate the behavior of ft_atoi.
• If a parameter contains an error, the function returns 0. An error can be:
◦ The base is empty or of size 1;
◦ The base contains the same character twice;
◦ The base contains the characters + or - or whitespaces;
• It should be prototyped as follows:
int ft_atoi_base(char *str, char *base);"
*/

#include <stdio.h>
#include <stdbool.h>

int char_to_digit(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else
        return -1;
}

bool is_valid_base(char *base) {
    //  ◦ The base is empty or of size 1;
    if (base == NULL || base[0] == '\0' || base[1] == '\0')
        return 0;
    //  ◦ The base contains the characters + or - or whitespaces;
    for (int i = 0; base[i] != '\0'; i++) {
        if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
            return 0;
    }
    //  ◦ The base contains the same character twice;
    for (int i = 0; base[i] != '\0'; i++) {
        for (int j = i + 1; base[j] != '\0'; j++) {
            if (base[i] == base[j])
                return 0;
        }
    }

    return true;
}

int powers_method(int str_len, int i, int result, int digit, int base_length){
        int power = 1;
        int j = 0;

        while (j < str_len - i - 1) {
            power *= base_length;
            j++;
        }
        return result += digit * power;
}

int convert_to_integer(int i, char *str, char *base, int base_length) {
    int result = 0;
    
    while (str[i] != '\0') {
        int digit = char_to_digit(str[i]);
        if (digit < 0 || digit >= base_length)
            return 0;

        // result += powers_method(strlen(str), i, result, digit, base_length);
        result = result * base_length + digit;
        i++;
    }
    return result;
}

int ft_atoi_base(char *str, char *base) {
    int result;
    int sign;
    int base_length;
    int i;
    int digit;
    
    result = 0;
    sign = 1;
    base_length = 0;
    i = 0;

    if (!is_valid_base(base))
        return 0;

    while (*base)
        base_length++;

    while (str[i] == ' ')
        i++;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }


    return sign * convert_to_integer(i, str, base, base_length);
}

int main() {
    char str[] = "1A7B"; // Número hexadecimal 1A7B
    char base[] = "0123456789ABCDEF"; // Base hexadecimal
    int num = ft_atoi_base(str, base);
    printf("Converted string to integer: %d\n", num);
    return 0;
}
