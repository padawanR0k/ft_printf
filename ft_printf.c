/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:32:44 by yurlee            #+#    #+#             */
/*   Updated: 2021/06/05 18:12:07 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		process_by_format(const char *str, va_list va_ptr, t_word_flags *flags)
{
	int ret;

	ret = 0;
	if (*str == 'c')
		ret = ft_putchar(va_arg(va_ptr, int));
	else if (*str == 's')
		ret = ft_putstr(va_arg(va_ptr, char *));
	// else if (*str == 'p')
	// {
		// ret += ft_putnbr_base(va_arg(va_ptr, unsigned long long), HEXA_BASE_L);
	// }
	else if (*str == 'd' || *str == 'i')
		ret = process_id(va_ptr, flags);
	else if (*str == 'u')
		ret = process_u(va_ptr, flags, DECIMAL_BASE);
	else if (*str == 'x' || *str == 'X' || *str == 'p')
	{
		flags->type = *str;
		ret = process_xX(va_ptr, flags, *str == 'X' ? HEXA_BASE_U : HEXA_BASE_L);
	}
	return (ret);
}

void	init_flags(t_word_flags *flags)
{
	flags->blank = 0;
	flags->left_align = 0;
	flags->precision = 0;
	flags->specifier = 0;
	flags->width = 0;
	flags->type = 0;
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
