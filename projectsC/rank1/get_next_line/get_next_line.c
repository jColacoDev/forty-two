/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:41:37 by joao-rde          #+#    #+#             */
/*   Updated: 2024/05/15 19:41:41 by joao-rde         ###   ########.fr       */
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
	while (!(ft_strchr(static_str, '\n')) && fd_read != 0)
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
