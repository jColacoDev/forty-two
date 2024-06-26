/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:49:12 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/13 23:44:06 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (s1[i] - s2[i]);
}

/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	s5[] = {'a', 'b', 'c', -10, -20, '\0'};
	char	*s6;
	char	*s7;

	s1 = "abcdefghi";
	s2 = "abcdefg";
	s3 = "abcdEfghi";
	s4 = "ab0defghi";
	s6 = "abcdefghi";
	s7 = "";
	printf("s1: %s, s2: %s, s3: %s, s4: %s, s5: %s, s6: %s, s7: %s\n", s1, s2,
		s3, s4, s5, s6, s7);
	printf("ft_strcmp(s1, s2)\t= %d\noriginal strcmp(s1,
		s2)\t=%d\n------------------------------\n", ft_strcmp(s1, s2),
		strcmp(s1,s2));
	printf("ft_strcmp(s1, s3)\t= %d\noriginal strcmp(s1,
		s3)\t=%d\n------------------------------\n", ft_strcmp(s1, s3),
		strcmp(s1,s3));
	printf("ft_strcmp(s1, s4)\t= %d\noriginal strcmp(s1,
		s4)\t=%d\n------------------------------\n", ft_strcmp(s1, s4),
		strcmp(s1,s4));
	printf("ft_strcmp(s1, s5)\t= %d\noriginal strcmp(s1,
		s5)\t=%d\n------------------------------\n", ft_strcmp(s1, s5),
		strcmp(s1,s5));
	printf("ft_strcmp(s1, s6)\t= %d\noriginal strcmp(s1,
		s6)\t=%d\n------------------------------\n", ft_strcmp(s1, s6),
		strcmp(s1,s6));
	printf("ft_strcmp(s1, s7)\t= %d\noriginal strcmp(s1,
		s7)\t=%d\n------------------------------\n", ft_strcmp(s1, s7),
		strcmp(s1,s7));
	return(0);
}
*/
