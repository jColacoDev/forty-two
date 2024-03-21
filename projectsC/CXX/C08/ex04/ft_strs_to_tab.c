/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:43:21 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/21 00:01:11 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i])
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock_pointer;
	int			i;

	i = 0;
	stock_pointer = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (stock_pointer == NULL)
		return (NULL);
	while (i < ac)
	{
		stock_pointer[i].size = ft_strlen(av[i]);
		stock_pointer[i].str = av[i];
		stock_pointer[i].copy = ft_strdup(av[i]);
		i++;
	}
	stock_pointer[i].size = 0;
	stock_pointer[i].str = 0;
	stock_pointer[i].copy = 0;
	return (stock_pointer);
}

/*
int	main(int argc, char *argv[])
{
	t_stock_str	*tab;
	int			i;

	tab = ft_strs_to_tab(argc, argv);
	i = 0;
	while (tab[i].str)
	{
		printf("Argumento n %d\n", i);
		printf("String: %s\n", tab[i].str);
		printf("Size: %i\n", tab[i].size);
		printf("copy: %s\n\n", tab[i].copy);
		printf("---------------\n");
		i++;
	}
}
*/
