/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:12:55 by reasuke           #+#    #+#             */
/*   Updated: 2023/10/12 20:21:53 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_init_width(
				t_integer_info *info, intmax_t nb, t_format_spec *fs)
{
	info->prefix_width = ft_strlen(info->prefix);
	if (nb == 0 && fs->precision == 0)
		info->digits = 0;
	else
		info->digits = _digits_base(nb, ft_strlen(info->base), info->is_signed);
	if (fs->width && fs->precision == PREC_NONE && fs->flags & FLAG_ZERO)
	{
		info->space_width = 0;
		info->zero_width = _ft_max(fs->width
				- info->digits - info->prefix_width, 0);
	}
	else
	{
		info->space_width = _ft_max(fs->width
				- _ft_max(fs->precision, info->digits) - info->prefix_width, 0);
		info->zero_width = _ft_max(fs->precision - info->digits, 0);
	}
}

static void	_init_prefix(t_integer_info *info, intmax_t nb, t_format_spec *fs)
{
	info->prefix = "";
	if (info->is_signed && nb < 0)
		info->prefix = "-";
	else if (info->is_signed && fs->flags & FLAG_PLUS)
		info->prefix = "+";
	else if (info->is_signed && fs->flags & FLAG_SPACE)
		info->prefix = " ";
	else if (fs->flags & FLAG_HASH && fs->conversion == 'x' && nb)
		info->prefix = HEX_PREFIX_LOWER;
	else if (fs->flags & FLAG_HASH && fs->conversion == 'X' && nb)
		info->prefix = HEX_PREFIX_UPPER;
	else if (fs->conversion == 'p')
		info->prefix = HEX_PREFIX_LOWER;
}

static void	_init_integer_info(
				t_integer_info *info, intmax_t nb, t_format_spec *fs)
{
	info->is_signed = (fs->conversion == 'd' || fs->conversion == 'i');
	if (fs->conversion == 'x' || fs->conversion == 'p')
		info->base = HEX_BASE_LOEWR;
	else if (fs->conversion == 'X')
		info->base = HEX_BASE_UPPER;
	else if (fs->conversion == 'o')
		info->base = OCT_BASE;
	else
		info->base = DEC_BASE;
	_init_prefix(info, nb, fs);
	_init_width(info, nb, fs);
	if (fs->flags & FLAG_HASH && !info->is_signed && fs->conversion == 'o'
		&& !info->zero_width && (nb || fs->precision == 0))
	{
		info->prefix = OCT_PREFIX;
		info->prefix_width = 1;
		if (info->space_width)
			info->space_width--;
	}
}

void	_print_integer(intmax_t nb, t_format_spec *fs, t_format_result *fr)
{
	t_integer_info	info;

	_init_integer_info(&info, nb, fs);
	if (!(fs->flags & FLAG_MINUS) && info.space_width)
		_print_padding(' ', info.space_width);
	if (*info.prefix)
		ft_putstr_fd(info.prefix, STDOUT_FILENO);
	if (info.zero_width)
		_print_padding('0', info.zero_width);
	if (info.digits)
		_ft_putnbr_base(nb, info.base, info.is_signed);
	if (fs->flags & FLAG_MINUS && info.space_width)
		_print_padding(' ', info.space_width);
	fr->cnt += info.space_width
		+ info.prefix_width + info.zero_width + info.digits;
}
