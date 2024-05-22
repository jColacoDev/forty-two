/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:27:32 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/21 21:52:31 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	i;

	i = 0;
	if (!range)
		return (-1);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	array = (int *)malloc(sizeof(int) * (max - min));
	while (i < (max - min))
	{
		array[i] = min + i;
		i++;
	}
	range[0] = array;
	return (i);
}
/*
int	main(void)
{
	int	i;
	int	min;
	int	max;
	int	**range;

	range = (int **)malloc(sizeof(int*));
	i = 0;
	min = -3;
	max = 9;
	printf("%d\n",ft_ultimate_range(range, min, max));
	while (i < (max - min))
	{
		printf ("%d ", range[0][i]);
		i++;
	}
	printf ("\n");
	return (0);
}
*/
/*
int	main(void)
{
	int	res;
	int	offset;
	int	*range;
	int	*arr1;
	int	*arr2;
	int	*arr3;
	int	*arr4;
	int	*arr5;
	int	*arr6;
	int	size1;
	int	size2;
	int	size3;
	int	size4;
	int	size5;
	int	size6;

	res = ft_ultimate_range(&range, 0, 8);
	if (res == -1)
	{
		printf("Error\n");
		return (1);
	}
	offset = 0;
	while (offset < 8)
	{
		printf("%d ", range[offset]);
		offset++;
	}
	printf("\nres: %d", res);
	printf("\n");
	size1 = ft_ultimate_range(&arr1, 1, 2);
	size2 = ft_ultimate_range(&arr2, -1, 2);
	size3 = ft_ultimate_range(&arr3, -3, -1);
	size4 = ft_ultimate_range(&arr4, -2, -3);
	size5 = ft_ultimate_range(&arr5, 0, 10);
	size6 = ft_ultimate_range(&arr6, -2, 0);
	offset = 0;
	while (offset < 1)
	{
		printf("%d ", arr1[offset]);
		offset++;
	}
	printf("| min %d ", 1);
	printf("| max %d ", 2);
	printf("| size %d", size1);
	printf("\n");
	offset = 0;
	while (offset < 3)
	{
		printf("%d ", arr2[offset]);
		offset++;
	}
	printf("| min %d ", -1);
	printf("| max %d ", 2);
	printf("| size %d", size2);
	printf("\n");
	offset = 0;
	while (offset < 2)
	{
		printf("%d ", arr3[offset]);
		offset++;
	}
	printf("| min %d ", -3);
	printf("| max %d ", -1);
	printf("| size %d", size5);
	printf("\n");
	offset = 0;
	while (offset < 10)
	{
		printf("%d ", arr5[offset]);
		offset++;
	}
	printf("| min %d ", -2);
	printf("| max %d ", -3);
	printf("| size %d", size4);
	printf("\n");
	offset = 0;
	while (offset < 2)
	{
		printf("%d ", arr4[offset]);
		offset++;
	}
	printf("| min %d ", -2);
	printf("| max %d ", 0);
	printf("| size %d", size6);
	return (0);
}
*/
