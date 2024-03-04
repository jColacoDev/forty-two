#include <unistd.h>


void print_alphabet() {
    char c = 'a';
    while (c <= 'z') {
        write(1, &c, 1);
        c++;
    }
}

int main(void){
	print_alphabet();
	
	return (0);
}
