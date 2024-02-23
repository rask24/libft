/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:12:55 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/23 23:52:45 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	fpf_print_integer(intmax_t nb, t_format_info *fi, t_format_result *fr)
{
	t_integer_info	info;

	fp_configure_integer_info(&info, nb, fi);
	if (!(fi->flags & FLAG_MINUS) && info.space_width)
		fp_print_padding(' ', info.space_width, STDOUT_FILENO);
	if (*info.prefix)
		ft_putstr_fd(info.prefix, STDOUT_FILENO);
	if (info.zero_width)
		fp_print_padding('0', info.zero_width, STDOUT_FILENO);
	if (info.digits)
		fp_putnbr_base_fd(nb, info.base, info.is_signed, STDOUT_FILENO);
	if (fi->flags & FLAG_MINUS && info.space_width)
		fp_print_padding(' ', info.space_width, STDOUT_FILENO);
	fr->cnt += info.space_width + info.prefix_width + info.zero_width
		+ info.digits;
}
