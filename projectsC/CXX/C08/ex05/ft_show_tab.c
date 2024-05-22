/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:50:16 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/21 00:01:08 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	n;

	if (nb > 9)
		ft_putnbr(nb / 10);
	n = nb % 10 + '0';
	write(1, &n, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *str)
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
	t_stock_str	*strct;
	int			i;

	i = 0;
	strct = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (strct == NULL)
		return (NULL);
	while (i < ac)
	{
		strct[i].size = ft_strlen(av[i]);
		strct[i].str = av[i];
		strct[i].copy = ft_strcpy(av[i]);
		i++;
	}
	strct[i].size = 0;
	strct[i].str = 0;
	strct[i].copy = 0;
	return (strct);
}

/*
void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	j;

	i = 0;
	while (par[i].str)
	{
		j = 0;
		while (par[i].str[j])
		{
			write(1, &par[i].str[j], 1);
			j++;
		}
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		j = 0;
		while (par[i].copy[j])
		{
			write(1, &par[i].copy[j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stock_str	*tab;
	int			i;

	tab = ft_strs_to_tab(argc, argv);
	i = 0;
	ft_show_tab(tab);
}
*/
