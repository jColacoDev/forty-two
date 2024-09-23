/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:46:26 by joao-rde          #+#    #+#             */
/*   Updated: 2024/08/29 15:13:18 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	int			fd_read;
	static char	*static_str[FD_MAX];

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	fd_read = 1;
	while (!ft_strchr(static_str[fd], '\n') && fd_read != 0)
	{
		fd_read = read(fd, buffer, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[fd_read] = '\0';
		static_str[fd] = ft_strjoin(static_str[fd], buffer);
	}
	free(buffer);
	buffer = ft_line_read(static_str[fd]);
	static_str[fd] = ft_new_static_str(static_str[fd]);
	return (buffer);
}

/*
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 
get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o gnl_test_bonus
// ./gnl_test_bonus file1.txt file2.txt file3.txt

int	main(int ac, char **av)
{
	char	*line;
	int		fd[ac - 1];
	int		line_number = 0;
	int		i;
	int		active_fds;

	if (ac < 2)
	{
		printf("Usage: %s <file1> <file2> ... <fileN>\n", av[0]);
		return (1);
	}
	// Open all files passed as arguments
	for (i = 0; i < ac - 1; i++)
	{
		fd[i] = open(av[i + 1], O_RDONLY);
		if (fd[i] == -1)
		{
			perror("Error opening file");
			return (1);
		}
	}
	// Read all file descriptors
	active_fds = ac - 1;
	while (active_fds > 0)
	{
		for (i = 0; i < ac - 1; i++)
		{
			if (fd[i] != -1)
			{
				line = get_next_line(fd[i]);
				if (line)
				{
					printf("File %d Line %02d: %s \n", 
					i + 1, line_number++, line);
					free(line);
				}
				else
				{
					// Close file descriptor after EOF
					if (close(fd[i]) == -1)
						perror("Error closing file");
					fd[i] = -1;
					active_fds--;
				}
			}
		}
	}

	return (0);
}
*/