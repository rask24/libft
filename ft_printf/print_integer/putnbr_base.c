/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/23 22:23:01 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	_putnbr_base_rec(uintmax_t uim_nb, size_t radix, const char *base)
{
	if (uim_nb / radix)
		_putnbr_base_rec(uim_nb / radix, radix, base);
	ft_putchar_fd(base[uim_nb % radix], STDOUT_FILENO);
}

void	fpf_putnbr_base(intmax_t nb, const char *base, bool is_signed)
{
	uintmax_t	uim_nb;
	size_t		radix;

	radix = ft_strlen(base);
	if (radix < 2 || !base)
		return ;
	if (nb < 0 && is_signed)
		uim_nb = -nb;
	else
		uim_nb = nb;
	_putnbr_base_rec(uim_nb, radix, base);
}

int	fpf_digits_base(intmax_t nb, size_t radix, bool is_signed)
{
	uintmax_t	uim_nb;
	int			digits;

	if (nb == 0)
		return (1);
	if (nb < 0 && is_signed)
		uim_nb = -nb;
	else
		uim_nb = nb;
	digits = 0;
	while (uim_nb)
	{
		uim_nb /= radix;
		digits++;
	}
	return (digits);
}
