/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:59:33 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/23 18:20:44 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	t_format_result	fr;
	t_format_info	fi;

	fr = (t_format_result){format, 0};
	va_start(ap, format);
	while (*fr.format)
	{
		if (*fr.format == '%')
		{
			fi = (t_format_info){FLAG_NONE, WIDTH_NONE, PREC_NONE, LENGTH_NONE,
				'\0'};
			fpf_configure_format_info(&fi, &fr, &ap);
			fpf_conversion_router(&fi, &fr, &ap);
		}
		else
		{
			ft_putchar_fd(*fr.format++, STDOUT_FILENO);
			fr.cnt++;
		}
	}
	va_end(ap);
	return (fr.cnt);
}
