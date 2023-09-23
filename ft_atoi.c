/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:18:20 by reasuke           #+#    #+#             */
/*   Updated: 2023/09/23 12:07:37 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdbool.h>
#include <errno.h>

#define LOWER_BASE "0123456789abcdefghijklmnopqrstuvwxyz"
#define UPPER_BASE "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

static int	ft_isspace(int c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static const char	*parse_prefix(const char *str, int *base)
{
	if (*str == '0')
	{
		if (*(str + 1) == 'x')
		{
			*base = 16;
			return (str + 2);
		}
		else
		{
			*base = 8;
			return (str + 1);
		}
	}
	*base = 10;
	return (str);
}

static long	ret(long nb, const char *str, int base, int sign)
{
	ptrdiff_t	index;

	while (true)
	{
		index = ft_strchr(UPPER_BASE, *str) - UPPER_BASE;
		if (index < 0 || base <= index)
			index = ft_strchr(LOWER_BASE, *str) - LOWER_BASE;
		if (index < 0 || base <= index)
			break ;
		if (sign == 1 && nb > (LONG_MAX - index) / base)
		{
			errno = ERANGE;
			return (LONG_MAX);
		}
		if (sign == -1 && - nb < (LONG_MIN + index) / base)
		{
			errno = ERANGE;
			return (LONG_MIN);
		}
		nb = nb * base + index;
		str++;
	}
	return (sign * nb);
}

long	ft_strtol(const char *str, int base)
{
	long		nb;
	int			sign;

	if (!(base == 0 || (2 <= base && base <= 36)))
		return (0);
	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (base == 0)
		str = parse_prefix(str, &base);
	return (ret(nb, str, base, sign));
}

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
		nbr = nbr * 10 + *str++ - '0';
	return (sign * nbr);
}
