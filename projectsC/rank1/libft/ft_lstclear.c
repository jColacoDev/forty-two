/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:55:38 by joao-rde          #+#    #+#             */
/*   Updated: 2024/04/11 17:55:34 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*ptr_next;

	if (!lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		ptr_next = ptr->next;
		del(ptr->content);
		free(ptr);
		ptr = ptr_next;
	}
	*lst = NULL;
}
