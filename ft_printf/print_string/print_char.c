/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:02:59 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/23 22:19:37 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	fpf_print_char(char c, t_format_info *fi, t_format_result *fr)
{
	if (fi->width && !(fi->flags & FLAG_MINUS) && !(fi->flags & FLAG_ZERO))
		fpf_print_padding(' ', fi->width - 1);
	else if (fi->width && !(fi->flags & FLAG_MINUS) && fi->flags & FLAG_ZERO)
		fpf_print_padding('0', fi->width - 1);
	ft_putchar_fd(c, STDOUT_FILENO);
	if (fi->width && fi->flags & FLAG_MINUS)
		fpf_print_padding(' ', fi->width - 1);
	if (fi->width)
		fr->cnt += fi->width;
	else
		fr->cnt++;
}
