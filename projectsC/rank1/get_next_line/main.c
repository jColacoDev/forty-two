#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o gnl_test
// ./gnl_test your_file.txt

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		line_number;

	if (ac != 2)
	{
		printf("Usage: %s <file_name>\n", av[0]);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line_number = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %02d: %s", line_number++, line);
		free(line);
	}
	if (close(fd) == -1)
	{
		perror("Error closing file");
		return (1);
	}

	return (0);
}
