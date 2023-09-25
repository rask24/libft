/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:10:11 by reasuke           #+#    #+#             */
/*   Updated: 2023/09/25 13:16:33 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
