/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:32:42 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/28 15:54:55 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

# define ON 1
# define OFF 0
# define FORMAT_SPECIFIER "cspdiuxX%"
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
	short		left_align;
	short		blank;
	short		precision;
	void		*value;
}				t_word_flags;

int				ft_printf(const char *format, ...);
int				ft_putchar(const char str);
int				ft_putstr(const char *chr);
int				ft_putnbr_base(long long n, const char *base);
char			*check_flag_option(char *str, t_word_flags *flags);
int				ft_putnbr_len(long long n, const char *base);
int				process_id(va_list va_ptr,
					t_word_flags *flags, const char *base);
int				process_x(va_list va_ptr,
					t_word_flags *flags, const char *base);
int				process_u(va_list va_ptr,
					t_word_flags *flags, const char *base);
int				process_s(va_list va_ptr, t_word_flags *flags);
int				process_c(va_list va_ptr, t_word_flags *flags);
int				process_percent(t_word_flags *flags);
int				process_p(va_list va_ptr,
					t_word_flags *flags, const char *base);
int				print_zero(t_word_flags *flags, int len);
int				print_blank(t_word_flags *flags, int len);
int				is_format_specifier(char c);
int				print_repeat(int diff, char c);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
int				is_flag(char c);
#endif