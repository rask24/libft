/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_digits_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/23 22:21:01 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
