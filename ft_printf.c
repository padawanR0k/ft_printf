/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:32:44 by yurlee            #+#    #+#             */
/*   Updated: 2021/06/12 16:17:42 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		process_by_format(const char *str, va_list va_ptr, t_word_flags *flags)
{
	int ret;

	ret = 0;
	if (*str == 'c')
		ret = process_c(va_ptr, flags);
	else if (*str == 's')
		ret = process_s(va_ptr, flags);
	else if (*str == 'd' || *str == 'i')
		ret = process_id(va_ptr, flags);
	else if (*str == 'u')
		ret = process_u(va_ptr, flags, DECIMAL_BASE);
	else if (*str == 'x' || *str == 'X' || *str == 'p')
	{
		flags->type = *str;
		ret = process_xp(va_ptr, flags,
									*str == 'X' ? HEXA_BASE_U : HEXA_BASE_L);
	}
	return (ret);
}

void	init_flags(t_word_flags *flags)
{
	flags->blank = OFF;
	flags->left_align = OFF;
	flags->precision = OFF;
	flags->specifier = OFF;
	flags->width = 0;
	flags->width_p = 0;
	flags->fill_zero = OFF;
	flags->type = OFF;
}

int		core(const char *str, va_list va_ptr)
{
	int				ret;
	t_word_flags	flags;

	ret = 0;
	init_flags(&flags);
	while (*str)
	{
		if (*str == '%')
		{
			flags.specifier = ON;
			str++;
			check_flag_option(&str, &flags);
			ret += process_by_format(str, va_ptr, &flags);
		}
		else
			ret += ft_putchar(*str);
		str++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	va_ptr;
	int		ret;
	va_start(va_ptr, format);
	ret = core(format, va_ptr);
	va_end(va_ptr);
	return (ret);
}
