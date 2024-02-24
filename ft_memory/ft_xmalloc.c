/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:13:22 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:27:23 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "libft.h"

void	*ft_xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_dprintf(STDERR_FILENO,
			"ft_xmalloc: cannot allocate %zu bytes\n", size);
		exit(2);
	}
	return (ptr);
}
