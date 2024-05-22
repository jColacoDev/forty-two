/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:38:19 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/21 16:27:15 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

int	ft_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

# define ABS(Value) ft_absolute(Value)

#endif
