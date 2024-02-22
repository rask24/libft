/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:20:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/22 23:46:53 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define OCT_BASE "01234567"
# define DEC_BASE "0123456789"
# define UPPER_HEX_BASE "0123456789ABCDEF"
# define LOWER_HEX_BASE "0123456789abcdef"

# define FLAGS "-+ #0"

typedef enum s_flag_options
{
	FLAG_NONE = 0,
	FLAG_MINUS = 1 << 0,
	FLAG_PLUS = 1 << 1,
	FLAG_SPACE = 1 << 2,
	FLAG_HASH = 1 << 3,
	FLAG_ZERO = 1 << 4,
}				t_flag_options;

# define WIDTH_NONE 0

# define PREC_NONE -1

typedef enum e_length_options
{
	LENGTH_NONE,
	LENGTH_L,
	LENGTH_LL,
	LENGTH_H,
	LENGTH_HH,
	LENGTH_J,
	LENGTH_T,
	LENGTH_Z,
}				t_length_options;

# define STR_NULL "(null)"

# define OCT_PREFIX "0"
# define LOEWR_HEX_PREFIX "0x"
# define UPPER_HEX_PREFIX "0X"

typedef struct s_format_result
{
	const char	*format;
	int			cnt;
}				t_format_result;

typedef struct s_format_info
{
	int			flags;
	int			width;
	int			precision;
	int			length;
	char		conversion;
}				t_format_info;

typedef struct s_integer_info
{
	bool		is_signed;
	char		*base;
	char		*prefix;
	int			space_width;
	int			zero_width;
	int			prefix_width;
	int			digits;
}				t_integer_info;

int				ft_printf(const char *format, ...);

void			fpf_parse_spec(t_format_info *fi, t_format_result *fr,
					va_list *ap);
void			fpf_conversion_router(t_format_info *fi, t_format_result *fr,
					va_list *ap);
void			fpf_print_char(char c, t_format_info *fi, t_format_result *fr);
void			fpf_print_str(char *str, t_format_info *fi,
					t_format_result *fr);
void			fpf_print_padding(char c, int len);
void			fpf_print_integer(intmax_t nb, t_format_info *fi,
					t_format_result *fr);
void			fpf_putnbr_base(intmax_t nb, const char *base, bool is_signed);
int				fpf_digits_base(intmax_t nb, size_t radix, bool is_signed);
int				fpf_max(int a, int b);

#endif
