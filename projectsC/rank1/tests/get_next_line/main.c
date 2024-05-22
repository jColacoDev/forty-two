#include "../../ft_printf/ft_printf.h"

int main(void)
{
	ft_printf("-----------------------------\n");
	ft_printf("------  TESTING AREA  -------\n");
	ft_printf("-----------------------------\n");

    ft_printf("Hello, %s!\n", "world");
	printf("Hello, %s!\n", "world");
	ft_printf("-----------------------------\n");

    ft_printf("Number: %d\n", 42);
    printf("Number: %d\n", 42);
	ft_printf("-----------------------------\n");


    ft_printf("Hex: %x\n", 255);
    printf("Hex: %x\n", 255);

    ft_printf("HEX: %X\n", 255);
    printf("HEX: %X\n", 255);

    ft_printf("#Hex: %#x\n", 255);
    printf("#Hex: %#x\n", 255);

    ft_printf("HEX: %#X\n", 255);
    printf("HEX: %#X\n", 255);
	ft_printf("-----------------------------\n");

    ft_printf("Pointer: %p\n", main);
    printf("Pointer: %p\n", main);
	ft_printf("-----------------------------\n");

    ft_printf("Percent: %%\n");
    printf("Percent: %%\n");
	ft_printf("-----------------------------\n");

    ft_printf("Signed: %+d\n", 42);
    printf("Signed: %+d\n", 42);
	ft_printf("-----------------------------\n");

    ft_printf("Space: % d\n", 42);
    printf("Space: % d\n", 42);
	ft_printf("-----------------------------\n");

    return 0;
}
