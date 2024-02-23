/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:59:33 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/23 23:08:48 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vprintf(const char *format, va_list ap)
{
	t_format_result	fr;
	t_format_info	fi;

	fr = (t_format_result){format, 0};
	while (*fr.format)
	{
		if (*fr.format == '%')
		{
			fi = (t_format_info){FLAG_NONE, WIDTH_NONE, PREC_NONE, LENGTH_NONE,
				'\0'};
			fp_configure_format_info(&fi, &fr, &ap);
			fp_print_by_format(&fi, &fr, &ap);
		}
		else
		{
			ft_putchar_fd(*fr.format++, STDOUT_FILENO);
			fr.cnt++;
		}
	}
	return (fr.cnt);
}
