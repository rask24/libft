/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:56:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:32:56 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;

	ret = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			ret = s;
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return ((char *)ret);
}
