/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:56:23 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/12 19:11:13 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_char_alpha_numeric(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A'
			&& c <= 'Z'));
}

void	ft_format_char(char *str, int i, int *capitalize_next)
{
	if (*capitalize_next)
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32;
		}
		*capitalize_next = 0;
	}
	else
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalize_next;

	i = 0;
	capitalize_next = 1;
	while (str[i])
	{
		if (ft_is_char_alpha_numeric(str[i]))
		{
			ft_format_char(str, i, &capitalize_next);
		}
		else
		{
			capitalize_next = 1;
		}
		i++;
	}
	return (str);
}

/*
int	main(void)
{
	char	str1[] = "alo maluco 42beleza!";
	char	str2[] = "ALO MALUCO 42BELEZA!";
	char	str3[] = "alo+ma|uco a2beleza!";
	char	str4[] = "ALO+MALUCO*a2BELEZA!";
	char	str5[] = "^uIv#= =9Hf~2y@F3A)FTzBgF";
	char	str6[] = "tsR1|vn_WE}7X6{Vm2vQf(rG}qdnT`1,qH+n";

	printf("str1: %s\n", str1);
	ft_strcapitalize(str1);
	printf("str1_c: %s\n", str1);
	printf("str2: %s\n", str2);
	ft_strcapitalize(str2);
	printf("str2_c: %s\n", str2);
	printf("str3: %s\n", str3);
	ft_strcapitalize(str3);
	printf("str3_c: %s\n", str3);
	printf("str4: %s\n", str4);
	ft_strcapitalize(str4);
	printf("str4_c: %s\n", str4);
	printf("str5: %s\n", str5);
	ft_strcapitalize(str5);
	printf("str5_c: %s\n", str5);
	printf("str6: %s\n", str6);
	ft_strcapitalize(str6);
	printf("str6_c: %s\n", str6);
	return (0);
}
*/
