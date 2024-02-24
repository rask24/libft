/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:42:38 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 16:09:58 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_type.h"

static int	parse_prefix(t_tol_info *info)
{
	ptrdiff_t	index;
	char		*ptr;

	if (!ft_strncmp(info->str, "0x", 2))
	{
		index = -1;
		ptr = ft_strchr(UPPER_BASE, info->str[2]);
		if (ptr)
			index = ptr - UPPER_BASE;
		ptr = ft_strchr(LOWER_BASE, info->str[2]);
		if (ptr)
			index = ptr - LOWER_BASE;
		if (index < 0 || info->base <= index)
		{
			info->digit_cnt++;
			info->str++;
			return (0);
		}
		info->digit_cnt++;
		info->str += 2;
	}
	return (1);
}

static void	convert_str_to_long(t_tol_info *info)
{
	ptrdiff_t	index;
	char		*ptr;

	if (info->base == 16 && !parse_prefix(info))
		return ;
	while (1)
	{
		index = -1;
		ptr = ft_strchr(UPPER_BASE, *info->str);
		if (ptr)
			index = ptr - UPPER_BASE;
		ptr = ft_strchr(LOWER_BASE, *info->str);
		if (ptr)
			index = ptr - LOWER_BASE;
		if (index < 0 || info->base <= index)
			break ;
		if (info->sign * info->nb > (LONG_MAX - index) / info->base && !info->overflow)
			info->overflow = MAX_OVERFLOW;
		if (info->sign * info->nb < (LONG_MIN + index) / info->base && !info->overflow)
			info->overflow = MIN_OVERFLOW;
		info->nb = info->nb * info->base + index;
		info->digit_cnt++;
		info->str++;
	}
}

static int	init_conv_spec(t_tol_info *info,
				const char *str, char **endptr, int base)
{
	info->str = str;
	info->endptr = endptr;
	if (info->endptr)
		*info->endptr = (char *)str;
	info->nb = 0;
	info->sign = 1;
	info->digit_cnt = 0;
	info->overflow = 0b00;
	if (!(base == 0 || (2 <= base && base <= 36)))
		return (0);
	while (ft_isspace(*info->str))
		info->str++;
	if (*info->str == '+' || *info->str == '-')
		if (*info->str++ == '-')
			info->sign *= -1;
	if (base)
		info->base = base;
	else if (*info->str == '0' && (info->str[1] == 'x' || info->str[1] == 'X'))
		info->base = 16;
	else if (*info->str == '0')
		info->base = 8;
	else
		info->base = 10;
	return (1);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	t_tol_info	info;

	if (init_conv_spec(&info, str, endptr, base))
		convert_str_to_long(&info);
	if (info.endptr && info.digit_cnt)
		*info.endptr = (char *)(info.str);
	if (info.overflow)
		errno = ERANGE;
	else if (info.digit_cnt == 0)
		errno = EINVAL;
	if (info.overflow == MAX_OVERFLOW)
		return (LONG_MAX);
	else if (info.overflow == MIN_OVERFLOW)
		return (LONG_MIN);
	return (info.sign * info.nb);
}
