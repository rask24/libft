/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:49:30 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:32:23 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	ret = malloc(s1_len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, s1_len + 1);
	return (ret);
}
