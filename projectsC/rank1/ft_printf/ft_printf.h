/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:09:57 by joao-rde          #+#    #+#             */
/*   Updated: 2024/05/21 19:18:33 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int	hash;
	int	zero;
	int	minus;
	int	space;
	int	plus;
	int	width;
	int	precision;
	int	dot;
}		t_flags;

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_strpad(char *str, char pad, int len, int left_align);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dst, const char *src);
int		ft_putstr(char *s);
char	*ft_strdup(const char *s);
char	*ft_utoa_base(unsigned long long n, int base, char *charset);
char	*ft_itoa(int n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_memset(void *s, int c, size_t n);

int		handle_number_conversion(va_list ap, int s, t_flags flags);
int		handle_special_cases(va_list ap, int s, t_flags flags);
void	handle_flag_width(char **str, char *prefix, t_flags flags);
void	handle_num_flags(char **str, char *prefix, t_flags flags);

#endif
