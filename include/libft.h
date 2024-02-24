/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:54:41 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:24:57 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define LOWER_BASE "0123456789abcdefghijklmnopqrstuvwxyz"
# define UPPER_BASE "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define MAX_OVERFLOW 0b01
# define MIN_OVERFLOW 0b10

typedef struct s_conv_spec
{
	const char		*str;
	char			**endptr;
	long			nb;
	int				base;
	int				sign;
	int				digit_cnt;
	int				overflow;
}					t_conv_spec;

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

int					ft_atoi(const char *str);
void				*ft_free_strs(char **strs);
char				*ft_itoa(int n);
char				**ft_split(const char *s, char c);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
long				ft_strtol(const char *str, char **endptr, int base);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_substr(const char *s, unsigned int start, size_t len);

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_vdprintf(int fd, const char *format, va_list ap);

#endif
