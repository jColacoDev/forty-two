/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:41:37 by joao-rde          #+#    #+#             */
/*   Updated: 2024/08/29 15:13:01 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	int			fd_read;
	static char	*static_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_read = 1;
	buffer = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(static_str, '\n') && fd_read != 0)
	{
		fd_read = read(fd, buffer, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[fd_read] = '\0';
		static_str = ft_strjoin(static_str, buffer);
	}
	free(buffer);
	buffer = ft_line_read(static_str);
	static_str = ft_new_static_str(static_str);
	return (buffer);
}

/*
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 
get_next_line.c get_next_line_utils.c main.c -o gnl_test
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
*/