/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_integer_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:12:55 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/23 22:36:28 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	_set_base(t_integer_info *info, t_format_info *fi)
{
	if (fi->conversion == 'x' || fi->conversion == 'p')
		info->base = LOWER_HEX_BASE;
	else if (fi->conversion == 'X')
		info->base = UPPER_HEX_BASE;
	else if (fi->conversion == 'o')
		info->base = OCT_BASE;
	else
		info->base = DEC_BASE;
}

static void	_set_prefix(t_integer_info *info, intmax_t nb, t_format_info *fi)
{
	info->prefix = "";
	if (info->is_signed && nb < 0)
		info->prefix = "-";
	else if (info->is_signed && fi->flags & FLAG_PLUS)
		info->prefix = "+";
	else if (info->is_signed && fi->flags & FLAG_SPACE)
		info->prefix = " ";
	else if (fi->flags & FLAG_HASH && fi->conversion == 'x' && nb)
		info->prefix = LOEWR_HEX_PREFIX;
	else if (fi->flags & FLAG_HASH && fi->conversion == 'X' && nb)
		info->prefix = UPPER_HEX_PREFIX;
	else if (fi->conversion == 'p')
		info->prefix = LOEWR_HEX_PREFIX;
}

static void	_set_width(t_integer_info *info, intmax_t nb, t_format_info *fi)
{
	info->prefix_width = ft_strlen(info->prefix);
	if (nb == 0 && fi->precision == 0)
		info->digits = 0;
	else
		info->digits = fpf_digits_base(nb, ft_strlen(info->base),
				info->is_signed);
	if (fi->width && fi->precision == PREC_NONE && fi->flags & FLAG_ZERO)
	{
		info->space_width = 0;
		info->zero_width = ft_max(fi->width - info->digits
				- info->prefix_width, 0);
	}
	else
	{
		info->space_width = ft_max(fi->width - ft_max(fi->precision,
					info->digits) - info->prefix_width, 0);
		info->zero_width = ft_max(fi->precision - info->digits, 0);
	}
}

static void	_adjust_for_oct_prefix(t_integer_info *info, intmax_t nb,
				t_format_info *fi)
{
	if (fi->flags & FLAG_HASH && !info->is_signed && fi->conversion == 'o'
		&& !info->zero_width && (nb || fi->precision == 0))
	{
		info->prefix = OCT_PREFIX;
		info->prefix_width = 1;
		if (info->space_width)
			info->space_width--;
	}
}

void	fpf_configure_integer_info(t_integer_info *info, intmax_t nb,
			t_format_info *fi)
{
	info->is_signed = (fi->conversion == 'd' || fi->conversion == 'i');
	_set_base(info, fi);
	_set_prefix(info, nb, fi);
	_set_width(info, nb, fi);
	_adjust_for_oct_prefix(info, nb, fi);
}
