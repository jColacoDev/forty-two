/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:41:32 by joao-rde          #+#    #+#             */
/*   Updated: 2024/04/11 17:55:28 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	if (!ptr)
		return ;
	ptr->next = new;
}
