/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_router.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:13:31 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/22 23:47:34 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fpf_signed_integer_router(t_format_info *fi, t_format_result *fr,
		va_list *ap)
{
	if (fi->length == LENGTH_NONE)
		fpf_print_integer(va_arg(*ap, int), fi, fr);
	else if (fi->length == LENGTH_L)
		fpf_print_integer(va_arg(*ap, long), fi, fr);
	else if (fi->length == LENGTH_LL)
		fpf_print_integer(va_arg(*ap, long long), fi, fr);
	else if (fi->length == LENGTH_H)
		fpf_print_integer((short)va_arg(*ap, int), fi, fr);
	else if (fi->length == LENGTH_HH)
		fpf_print_integer((signed char)va_arg(*ap, int), fi, fr);
	else if (fi->length == LENGTH_J)
		fpf_print_integer(va_arg(*ap, intmax_t), fi, fr);
	else if (fi->length == LENGTH_T)
		fpf_print_integer(va_arg(*ap, ptrdiff_t), fi, fr);
	else if (fi->length == LENGTH_Z)
		fpf_print_integer(va_arg(*ap, ssize_t), fi, fr);
}

static void	fpf_unsigned_integer_router(t_format_info *fi, t_format_result *fr,
		va_list *ap)
{
	if (fi->length == LENGTH_NONE)
		fpf_print_integer(va_arg(*ap, unsigned int), fi, fr);
	else if (fi->length == LENGTH_L)
		fpf_print_integer(va_arg(*ap, unsigned long), fi, fr);
	else if (fi->length == LENGTH_LL)
		fpf_print_integer(va_arg(*ap, unsigned long long), fi, fr);
	else if (fi->length == LENGTH_H)
		fpf_print_integer((unsigned short)va_arg(*ap, int), fi, fr);
	else if (fi->length == LENGTH_HH)
		fpf_print_integer((unsigned char)va_arg(*ap, int), fi, fr);
	else if (fi->length == LENGTH_J)
		fpf_print_integer(va_arg(*ap, uintmax_t), fi, fr);
	else if (fi->length == LENGTH_T)
		fpf_print_integer(va_arg(*ap, ptrdiff_t), fi, fr);
	else if (fi->length == LENGTH_Z)
		fpf_print_integer(va_arg(*ap, size_t), fi, fr);
}

static void	fpf_n_router(t_format_info *fi, t_format_result *fr, va_list *ap)
{
	if (fi->length == LENGTH_NONE)
		*va_arg(*ap, int *) = fr->cnt;
	else if (fi->length == LENGTH_L)
		*va_arg(*ap, long *) = fr->cnt;
	else if (fi->length == LENGTH_LL)
		*va_arg(*ap, long long *) = fr->cnt;
	else if (fi->length == LENGTH_H)
		*va_arg(*ap, short *) = fr->cnt;
	else if (fi->length == LENGTH_HH)
		*va_arg(*ap, signed char *) = fr->cnt;
	else if (fi->length == LENGTH_J)
		*va_arg(*ap, intmax_t *) = fr->cnt;
	else if (fi->length == LENGTH_T)
		*va_arg(*ap, ptrdiff_t *) = fr->cnt;
	else if (fi->length == LENGTH_Z)
		*va_arg(*ap, ssize_t *) = fr->cnt;
}

void	fpf_conversion_router(t_format_info *fi, t_format_result *fr,
		va_list *ap)
{
	if (fi->conversion == '%')
		fpf_print_char('%', fi, fr);
	else if (fi->conversion == 'c')
		fpf_print_char(va_arg(*ap, int), fi, fr);
	else if (fi->conversion == 's')
		fpf_print_str(va_arg(*ap, char *), fi, fr);
	else if (fi->conversion == 'd' || fi->conversion == 'i')
		fpf_signed_integer_router(fi, fr, ap);
	else if (ft_strchr("uxXo", fi->conversion))
		fpf_unsigned_integer_router(fi, fr, ap);
	else if (fi->conversion == 'p')
		fpf_print_integer(va_arg(*ap, uintptr_t), fi, fr);
	else if (fi->conversion == 'n')
		fpf_n_router(fi, fr, ap);
}
