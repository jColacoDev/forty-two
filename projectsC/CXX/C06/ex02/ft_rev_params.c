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
    int i;

    i=argc;
    while(argv[--i] && i > 0)
    {
        ft_putstr(argv[i]);
        write(1,"\n",1);
    }

    return (0);
}