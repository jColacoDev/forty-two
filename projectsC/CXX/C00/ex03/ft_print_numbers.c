#include <unistd.h>

void ft_print_numbers(void) {
    char digit = '0';
    while (digit <= '9') {
        write(1, &digit, 1);
        digit++;
    }
    write(1, "\n", 1); // Adiciona uma nova linha no final
}

int main() {
    ft_print_numbers();
    return 0;
}
