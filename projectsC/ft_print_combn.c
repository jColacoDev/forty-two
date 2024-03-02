#include <unistd.h>
#include <stdio.h>

void ft_print_combn(int n);
void generate_combinations(int data[], int start, int end, int index, int n, int *first);
void print_combinations(int data[], int n, int *first);

int main() {
    int n;
    printf("Digite o valor de n (0 < n < 10): ");
    scanf("%d", &n);

    ft_print_combn(n);

    return 0;
}

void ft_print_combn(int n) {
    int floor = 0;
    int roof = 9;

    if (n <= floor && n >= roof) {
        char error_message[] = "Valor de n fora do intervalo permitido.\n";
        write(1, error_message, sizeof(error_message) - 1);
        return;
    }
    
    int data[n];
    int first = 1;

    generate_combinations(data, floor, roof, floor, n, &first);
}

void generate_combinations(int data[], int start, int end, int index, int n, int *first) {
    if (index == n) {
        print_combinations(data, n, first);
        return;
    }

    for (int i = start; i <= end; i++) {
        data[index] = i;
        generate_combinations(data, i + 1, end, index + 1, n, first);
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

