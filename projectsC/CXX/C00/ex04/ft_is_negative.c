#include <unistd.h>

void ft_is_negative(int n) {
    char sign;
    if (n < 0) {
        sign = 'N';
    } else {
        sign = 'P';
    }
    write(1, &sign, 1);
}

int main() {
    ft_is_negative(-10);
    return 0;
}

