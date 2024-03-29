/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chmax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:53:14 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/20 22:47:43 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

bool	ft_chmax(int *a, int b)
{
	if (*a < b)
	{
		*a = b;
		return (true);
	}
	return (false);
}
