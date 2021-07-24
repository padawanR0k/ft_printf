/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:32:42 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/24 17:14:35 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

# define ON 1
# define OFF 0
# define FLAG_LEFT_ALIGN 10
# define FLAG_BLANK 20
# define FLAG_PRECISON 30
# define FORMAT_SPECIFIER "cspdiuxX"
# define FLAG_OPTION "-.*\0"
# define HEXA_BASE_L "0123456789abcdef"
# define HEXA_BASE_U "0123456789ABCDEF"
# define DECIMAL_BASE "0123456789"
# define NULL_STR "(null)"

typedef struct s_word_flags
{
	char		type;
	int			width;
	int			width_p;
	short		fill_zero;
	short		specifier;
	short		left_align;
	short		blank;
	short		precision;
	void		*value;
}				t_word_flags;

int				ft_printf(const char *format, ...);
int				ft_putchar(const char str);
int				ft_putstr(const char *chr);
int				ft_putnbr_base(long long n, const char *base);
int				check_flag_option(const char **str, t_word_flags *flags);
int				ft_putnbr_len(long long n, const char *base);
int				process_id(va_list va_ptr,
					t_word_flags *flags, const char *base);
int				process_x(va_list va_ptr,
					t_word_flags *flags, const char *base);
int				process_u(va_list va_ptr,
					t_word_flags *flags, const char *base);
int				process_s(va_list va_ptr, t_word_flags *flags);
int				process_c(va_list va_ptr, t_word_flags *flags);
int				process_p(va_list va_ptr,
					t_word_flags *flags, const char *base);
int				print_zero(t_word_flags *flags, int len);
int				print_blank(t_word_flags *flags, int len);
int				is_format_specifier(char c);
int				print_repeat(int diff, char c);
#endif