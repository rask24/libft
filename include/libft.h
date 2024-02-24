/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:54:41 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 01:17:08 by reasuke          ###   ########.fr       */
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

# define OK 0
# define ERROR -1

# define LOWER_BASE "0123456789abcdefghijklmnopqrstuvwxyz"
# define UPPER_BASE "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define MAX_OVERFLOW 0b01
# define MIN_OVERFLOW 0b10

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

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

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_xmalloc(size_t size);

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

void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

void				ft_lstadd_back(t_list **lst, t_list *new_lst);
void				ft_lstadd_front(t_list **lst, t_list *new_lst);
t_list				*ft_lst_before(t_list *lst, t_list *trg);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*f)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_vdprintf(int fd, const char *format, va_list ap);

char				*get_next_line(int fd);

char				**file_to_lines(char *file_name);

int					ft_abs(int a);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
bool				ft_chmax(int *a, int b);
bool				ft_chmin(int *a, int b);
void				ft_swap(int *a, int *b);

#endif
