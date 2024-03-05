/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 05:11:01 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/05 05:11:01 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	aux_arr[100];

	i = 0;
	while (i < size)
	{
		aux_arr[i] = tab[size - 1 - i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = aux_arr[i];
		i++;
	}
}
