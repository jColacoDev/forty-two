/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:46:26 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/26 19:37:31 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_line_read(char *static_str)
{
	int		i;
	char	*line;

	if (!static_str || !static_str[0])
		return (NULL);
	i = 0;
	while (static_str[i] && static_str[i] != '\n')
		i++;
	i += (static_str[i] == '\n');
	line = (char *)malloc(1 + i * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (static_str[++i] && static_str[i] != '\n')
		line[i] = static_str[i];
	if (static_str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_new_static_str(char	*static_str)
{
	char	*new_static_str;
	int		i;
	int		j;

	i = 0;
	while (static_str[i] && static_str[i] != '\n')
		i++;
	if (static_str[i] == '\0')
	{
		free(static_str);
		return (NULL);
	}
	i += (static_str[i] == '\n');
	new_static_str = (char *)malloc(1 + ft_strlen(static_str) - i);
	if (!new_static_str)
		return (NULL);
	j = -1;
	while (static_str[i + ++j])
		new_static_str[j] = static_str[i + j];
	new_static_str[j] = '\0';
	free(static_str);
	return (new_static_str);
}

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
