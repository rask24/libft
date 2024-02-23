/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/23 23:52:02 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	_putnbr_base_rec(uintmax_t uim_nb, size_t radix, const char *base,
				int fd)
{
	if (uim_nb / radix)
		_putnbr_base_rec(uim_nb / radix, radix, base, fd);
	ft_putchar_fd(base[uim_nb % radix], fd);
}

void	fp_putnbr_base_fd(intmax_t nb, const char *base, bool is_signed, int fd)
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
	_putnbr_base_rec(uim_nb, radix, base, fd);
}

int	fp_digits_base(intmax_t nb, size_t radix, bool is_signed)
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
