/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:09:36 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:10:31 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTEGER_H
# define FT_INTEGER_H

# include <stdbool.h>

int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
bool	ft_chmax(int *a, int b);
bool	ft_chmin(int *a, int b);
void	ft_swap(int *a, int *b);

#endif
