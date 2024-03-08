/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:43:43 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/05 01:43:43 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int isAlphanumeric(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

void capitalizeWords(char *str) {
    int i = 0;
    int capitalizeNext = 1;
    while (str[i]) {
        if (isAlphanumeric(str[i])) {
            if (capitalizeNext) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    str[i] -= 32;
                }
                capitalizeNext = 0;
            } else {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    str[i] += 32;
                }
            }
        } else {
            capitalizeNext = 1;
        }
        i++;
    }
}

int main() {
    char str[] = "hello world! this is a test 123.my-goD-1aS";
    capitalizeWords(str);
    printf("%s\n", str);
    return 0;
}
