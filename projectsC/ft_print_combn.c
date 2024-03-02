#include <unistd.h>
#include <stdio.h>

void ft_print_combn(int *counter, int n, int roof, int floor);
void generate_combinations(int *counter, int data[], int start, int end, int index, int n, int *first);
void print_combinations(int data[], int n, int *first);
void ft_putnbr(int n);

int main() {
    int floor = 0;
    int roof = 9;
    int counter = 0;
    int n;

    printf("Digite o valor de n (%d < n < %d): ", floor, roof);
    scanf("%d", &n);

    ft_print_combn(&counter, n, floor, roof);

    printf("\nTotal: ");
    ft_putnbr(counter);
    printf(" combinations\n");

    return 0;
}

void ft_print_combn(int *counter, int n, int floor, int roof) {
    if (n <= floor && n >= roof) {
        char error_message[] = "Valor de n fora do intervalo permitido.\n";
        write(1, error_message, sizeof(error_message) - 1);
        return;
    }
    
    int data[n];
    int first = 1;

    generate_combinations(counter, data, floor, roof, floor, n, &first);
}

void generate_combinations(int *counter, int data[], int start, int end, int index, int n, int *first) {
    if (index == n) {
        print_combinations(data, n, first);
        (*counter)++;

        return;
    }

    for (int i = start; i <= end; i++) {
        data[index] = i;
        generate_combinations(counter, data, i + 1, end, index + 1, n, first);
    }
}


void print_combinations(int data[], int n, int *first) {
    char buffer[20];
    int buffer_index = 0;

    if (!(*first)) {
        char comma = ',';
        write(1, &comma, 1);
    } else {
        *first = 0;
    }
    for (int i = 0; i < n; i++) {
        buffer[buffer_index++] = data[i] + '0';
    }
    write(1, buffer, buffer_index);

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
}
