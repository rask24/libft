/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/23 00:23:43 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_parse_flags(t_format_info *fi, t_format_result *fr)
{
	char		*ptr;
	ptrdiff_t	index;

	while (true)
	{
		ptr = ft_strchr(FLAGS, *fr->format);
		if (!ptr)
			break ;
		index = ptr - FLAGS;
		fi->flags |= 1 << index;
		fr->format++;
	}
}

static void	_parse_width(t_format_info *fi, t_format_result *fr, va_list *ap)
{
	if (*fr->format == '*')
	{
		fi->width = va_arg(*ap, int);
		if (fi->width < 0)
		{
			fi->width = -fi->width;
			fi->flags |= FLAG_MINUS;
		}
		fr->format++;
	}
	else
	{
		fi->width = ft_atoi(fr->format);
		while (ft_isdigit(*fr->format))
			fr->format++;
	}
}

static void	_parse_precision(t_format_info *fi, t_format_result *fr,
		va_list *ap)
{
	if (*fr->format == '.')
	{
		fr->format++;
		if (*fr->format == '*')
		{
			fi->precision = va_arg(*ap, int);
			fr->format++;
		}
		else
		{
			fi->precision = ft_atoi(fr->format);
			while (ft_isdigit(*fr->format))
				fr->format++;
		}
		if (fi->precision < 0)
			fi->precision = PREC_NONE;
	}
}

static void	_parse_conversion(t_format_info *fi, t_format_result *fr)
{
	if (!ft_strncmp(fr->format, "ll", 2))
		fi->length = LENGTH_LL;
	else if (!ft_strncmp(fr->format, "l", 1))
		fi->length = LENGTH_L;
	else if (!ft_strncmp(fr->format, "hh", 2))
		fi->length = LENGTH_HH;
	else if (!ft_strncmp(fr->format, "h", 1))
		fi->length = LENGTH_H;
	else if (!ft_strncmp(fr->format, "j", 1))
		fi->length = LENGTH_J;
	else if (!ft_strncmp(fr->format, "t", 1))
		fi->length = LENGTH_T;
	else if (!ft_strncmp(fr->format, "z", 1))
		fi->length = LENGTH_Z;
	while (ft_strchr("lhjtz", *fr->format))
		fr->format++;
	fi->conversion = *fr->format;
}

void	fpf_parse_format_info(t_format_info *fi, t_format_result *fr, va_list *ap)
{
	fr->format++;
	_parse_flags(fi, fr);
	_parse_width(fi, fr, ap);
	if (fi->flags & FLAG_MINUS && fi->flags & FLAG_ZERO)
		fi->flags &= ~FLAG_ZERO;
	_parse_precision(fi, fr, ap);
	_parse_conversion(fi, fr);
	fr->format++;
}
