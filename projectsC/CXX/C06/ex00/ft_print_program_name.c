
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int main(int argc, char *argv[])
{
    ft_putstr(argv[0]);
    write(1,"\n",1);

    return (0);
}