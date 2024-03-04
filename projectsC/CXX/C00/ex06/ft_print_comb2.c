#include <unistd.h>

void ft_print_comb2() {
	char buffer[5];
	int i, j;
	for (i = 0; i < 100; i++) {
		for (j = i; j < 100; j++) {
			if (i != j){
				buffer[0] = i / 10 + '0';
				buffer[1] = i % 10 + '0';
				buffer[2] = ' ';
				
				buffer[3] = j / 10 + '0';
				buffer[4] = j % 10 + '0';
				
				write(1, buffer, 5);
				if (!(i == 98 && j == 99)) {
				    char comma = ',';
				    write(1, &comma, 1);
				}
			}
		}
	}
}

int main() {
	ft_print_comb2();
	return 0;
}
