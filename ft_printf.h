/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:32:42 by yurlee            #+#    #+#             */
/*   Updated: 2021/06/05 18:11:18 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

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

typedef struct	s_word_flags
{
	char		type;
	int			width;
	short		specifier;
	short		left_align;
	short		blank;
	short		precision;
}				t_word_flags;

int				ft_printf(const char *format, ...);
int				get_formats_cnt(char *str);
int				ft_putchar(const char str);
int				ft_putstr(const char *chr);
int				ft_putnbr_base(long long n, const char *base);
int				check_flag_option(const char **str, t_word_flags *flags);
int				ft_putnbr_len(long long n, const char *base);
int				process_id(va_list va_ptr, t_word_flags *flags);
int				process_xX(va_list va_ptr, t_word_flags *flags, const char *base);
int				process_u(va_list va_ptr, t_word_flags *flags, const char *base);
#endif