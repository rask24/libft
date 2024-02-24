/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:57:42 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:05:56 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

# define OK 0
# define ERROR -1

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>

char	**file_to_lines(char *file_name);

#endif
