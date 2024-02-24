/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:54:42 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:26:29 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*u;

	u = (const unsigned char *)s;
	while (n--)
	{
		if (*u == (unsigned char)c)
			return ((void *)u);
		u++;
	}
	return (NULL);
}
