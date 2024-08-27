/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:41:44 by joao-rde          #+#    #+#             */
/*   Updated: 2024/05/15 19:41:45 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen(s);
		return (&s[i]);
	}
	i = -1;
	while (s[++i])
		if (s[i] == (char) c)
			return (&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *start, char *buff)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!start)
	{
		start = (char *)malloc(1 * sizeof(char));
		start[0] = '\0';
	}
	if (!start || !buff)
		return (NULL);
	ptr = (char *)malloc(1 + ft_strlen(start) + ft_strlen(buff) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = -1;
	while (start && start[++i])
		ptr[i] = start[i];
	j = -1;
	while (buff && buff[++j])
		ptr[i + j] = buff[j];
	ptr[i + j] = '\0';
	free(start);
	return (ptr);
}

char	*ft_line_read(char *static_str)
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

char	*ft_new_static_str(char	*static_str)
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
