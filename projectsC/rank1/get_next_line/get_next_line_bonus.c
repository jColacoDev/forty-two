/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:46:26 by joao-rde          #+#    #+#             */
/*   Updated: 2024/05/15 19:46:26 by joao-rde         ###   ########.fr       */
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
