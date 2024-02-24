/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:10:11 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:26:41 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*u_dst;
	const unsigned char	*u_src;

	if (!dst && !src)
		return (dst);
	u_dst = (unsigned char *)dst;
	u_src = (const unsigned char *)src;
	while (n--)
		*u_dst++ = *u_src++;
	return (dst);
}
