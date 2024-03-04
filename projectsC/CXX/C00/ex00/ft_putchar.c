#include <unistd.h>

void ft_putchar(char c){
	write(1, &c, 1);
	
	return;
}

int main(void){
	ft_putchar('Y');
	
	return (0);
}
