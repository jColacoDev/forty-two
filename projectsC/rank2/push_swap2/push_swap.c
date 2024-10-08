/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:25:18 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/26 20:43:13 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	stack = parse_stack(argc - 1, &argv[1]);
	index_stack(&stack);
	sort(stack);
	free_stack(stack);
	return (0);
}
