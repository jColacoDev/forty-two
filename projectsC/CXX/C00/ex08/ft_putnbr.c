#include <unistd.h>
#include <limits.h>
#include <stdio.h>

void ft_putnbr(int n);

int main() {
    int n;
    printf("Digite o valor de n (%d < n < %d): ", INT_MIN, INT_MAX);
    scanf("%d", &n);

    ft_putnbr(n);

    return 0;
}

void ft_putnbr(int n) {
    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }

    char buffer[20];
    int i = 0;

    do {
        buffer[i++] = n % 10 + '0'; 
        n /= 10; 
    } while (n != 0);

    while (i > 0) {
        write(1, &buffer[--i], 1); 
    }

    write(1, "\n", 1);
}
