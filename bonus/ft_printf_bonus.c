/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:32:44 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/28 15:54:49 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	process_by_format(char *str, va_list va_ptr, t_word_flags *flags)
{
	int		ret;

	ret = 0;
	if (is_format_specifier(*str))
		flags->type = *str;
	if (*str == '%')
		ret = process_percent(flags);
	else if (*str == 'c')
		ret = process_c(va_ptr, flags);
	else if (*str == 's')
		ret = process_s(va_ptr, flags);
	else if (*str == 'd' || *str == 'i')
		ret = process_id(va_ptr, flags, DECIMAL_BASE);
	else if (*str == 'u')
		ret = process_u(va_ptr, flags, DECIMAL_BASE);
	else if (*str == 'p')
		ret = process_p(va_ptr, flags, HEXA_BASE_L);
	else if (*str == 'x')
		ret = process_x(va_ptr, flags, HEXA_BASE_L);
	else if (*str == 'X')
		ret = process_x(va_ptr, flags, HEXA_BASE_U);
	return (ret);
}

void	init_flags(t_word_flags *flags)
{
	flags->blank = OFF;
	flags->left_align = OFF;
	flags->precision = OFF;
	flags->width = 0;
	flags->width_p = 0;
	flags->fill_zero = OFF;
	flags->type = OFF;
	flags->value = NULL;
}

int	core(const char *str, va_list va_ptr)
{
	int				ret;
	t_word_flags	flags;
	char			*fmt;

	ret = 0;
	fmt = (char *)str;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			init_flags(&flags);
			if (is_flag(*(fmt + 1)) || is_format_specifier(*(fmt + 1)))
			{
				fmt = check_flag_option(fmt + 1, &flags);
				ret += process_by_format(fmt, va_ptr, &flags);
			}
		}
		else
			ret += ft_putchar(*fmt);
		fmt++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	va_ptr;
	int		ret;

	va_start(va_ptr, format);
	ret = core(format, va_ptr);
	va_end(va_ptr);
	return (ret);
}
