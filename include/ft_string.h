/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:28:56 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/27 11:19:16 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

# define LOWER_BASE "0123456789abcdefghijklmnopqrstuvwxyz"
# define UPPER_BASE "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define MAX_OVERFLOW 0b01
# define MIN_OVERFLOW 0b10

typedef struct s_tol_info
{
	const char		*str;
	char			**endptr;
	long			nb;
	int				base;
	int				sign;
	int				digit_cnt;
	int				overflow;
}					t_tol_info;

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
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
long				ft_strtol(const char *str, char **endptr, int base);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_substr(const char *s, unsigned int start, size_t len);

#endif
