/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:09:57 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/26 19:50:23 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h> // needs -lbsd |compile link to library
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

// GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define FD_MAX 1024
char	*get_next_line(int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// ft_printf
typedef struct s_flags
{
	int			hash;
	int			zero;
	int			minus;
	int			space;
	int			plus;
	int			width;
	int			precision;
	int			dot;
}				t_flags;

int				handle_number_conversion(va_list ap, int c, t_flags flags);
int				handle_pointer(va_list ap, t_flags flags);
void			handle_flag_width(char **str, t_flags flags);
void			handle_hex(char **str, char **prefix, int c, t_flags flags);
int				handle_special_cases(va_list ap, int s, t_flags flags);
void			handle_zero_precision(char **str, unsigned long value,
					t_flags flags);

int				ft_printf(const char *format, ...);

// ft_libft
void				ft_array_r(int *array, size_t size);
bool				ft_atoiv(const char *str, int *n);
int					ft_abs(int n);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, const char *base);
int					ft_isspace(int c);
int					ft_putstr(char *s);
int 				ft_streq(const char *s1, const char *s2);

unsigned long		ft_strtoul_base(const char *str, const char *base);

char				*ft_strfill(char c, int width);
char				*ft_concat(const char *str1, const char *str2, int at_beginning);
char				*ft_strcat(char *dest, const char *src, size_t start);
char				*ft_strpad(char *str, char pad, int len, int left_align);
char				*ft_strnstr(const char *haystack, const char *needle,						size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *str);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_utoa_base(unsigned long long n, int base, char *charset, t_flags flags);
char				*ft_strcpy(char *dst, const char *src);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
