/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:03:40 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:26:52 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*u;

	u = (unsigned char *)b;
	while (len--)
		*u++ = (unsigned char)c;
	return (b);
}
