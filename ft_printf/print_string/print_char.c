/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:02:59 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/23 23:44:31 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	fp_print_char(char c, t_format_info *fi, t_format_result *fr)
{
	if (fi->width && !(fi->flags & FLAG_MINUS) && !(fi->flags & FLAG_ZERO))
		fp_print_padding(' ', fi->width - 1, STDOUT_FILENO);
	else if (fi->width && !(fi->flags & FLAG_MINUS) && fi->flags & FLAG_ZERO)
		fp_print_padding('0', fi->width - 1, STDOUT_FILENO);
	ft_putchar_fd(c, STDOUT_FILENO);
	if (fi->width && fi->flags & FLAG_MINUS)
		fp_print_padding(' ', fi->width - 1, STDOUT_FILENO);
	if (fi->width)
		fr->cnt += fi->width;
	else
		fr->cnt++;
}
