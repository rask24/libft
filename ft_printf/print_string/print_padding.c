/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:02:59 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:43:13 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"
#include "ft_printf.h"

void	fp_print_padding(char c, int len, int fd)
{
	while (len-- > 0)
		ft_putchar_fd(c, fd);
}
