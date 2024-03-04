#include <unistd.h>

void ft_print_comb() {
	char buffer[3];
	for (int i = 0; i <= 7; ++i) {
		for (int j = i + 1; j <= 8; ++j) {
		    for (int k = j + 1; k <= 9; ++k) {
			buffer[0] = i + '0';
			buffer[1] = j + '0';
			buffer[2] = k + '0';

			write(1, buffer, 3);

			if (!(i == 7 && j == 8 && k == 9)) {
			    char comma = ',';
			    write(1, &comma, 1);
			}
		    }
		}
	}
}

int main() {
	ft_print_comb();
	return 0;
}

