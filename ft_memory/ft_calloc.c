/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:17:23 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:25:35 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	return (ft_memset(ret, 0, count * size));
}
