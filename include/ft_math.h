/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:09:36 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/20 22:47:01 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stdbool.h>

int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
bool	ft_chmax(int *a, int b);
bool	ft_chmin(int *a, int b);
void	ft_swap(int *a, int *b);

#endif
