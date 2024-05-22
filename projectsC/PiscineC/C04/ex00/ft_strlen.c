/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:44:04 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/13 20:19:13 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
	{
		count++;
	}
	return (count);
}

/*
void	ft_strlen_test(char *str)
{
	int	size;
	int	ft_size;

	size = strlen(str);
	ft_size = ft_strlen(str);
	if (size != ft_size)
		printf("> KO,
			return (value of ft_strlen differs from expected. expected: %d, got:
			%d\n", size, ft_size));
	else
		printf("> OK. result: %d\n", ft_size);
}

int	main(void)
{
	char	*str;

	str = "";
	ft_strlen_test(str);
	str = "Test";
	ft_strlen_test(str);
	str = "Testing mored and more and more and more and more and more.";
	ft_strlen_test(str);
	return (0);
}
*/
