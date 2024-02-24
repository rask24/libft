/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:06:58 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:31:12 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
