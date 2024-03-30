/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:06:58 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:00:28 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

void	*ft_free_strs(char **strs)
{
	char	**tmp;

	tmp = strs;
	while (*tmp)
		free(*tmp++);
	free(strs);
	return (NULL);
}
