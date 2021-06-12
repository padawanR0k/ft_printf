/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:17:48 by yurlee            #+#    #+#             */
/*   Updated: 2021/06/12 17:57:26 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int process_id(va_list va_ptr, t_word_flags *flags)
{
	int value;
	int len;
	int ret;

	value = va_arg(va_ptr, int);
	len = ft_putnbr_len(value, DECIMAL_BASE);
	ret = 0;
	if (flags->left_align == ON)
	{
		ret += print_zero(flags, len);
		ret += ft_putnbr_base(value, DECIMAL_BASE);
		ret += print_blank(flags, len);
	}
	else
	{
		ret += print_blank(flags, len);
		ret += print_zero(flags, len);
		ret += ft_putnbr_base(value, DECIMAL_BASE);
	}
	return (ret);
}

int process_xp(va_list va_ptr, t_word_flags *flags, const char *base)
{
	unsigned long long	value;
	int					len;
	int					ret;
	int					is_pointer;

	is_pointer = flags->type == 'p';
	ret = 0;
	value = va_arg(va_ptr, unsigned long long);
	len = ft_putnbr_len(value, base) + (is_pointer ? 2 : 0);
	if (flags->left_align)
	{
		if (is_pointer)
			ret = ft_putstr("0x");
		ret += ft_putnbr_base(value, base);
		ret += print_blank(flags, len);
	}
	else
	{
		ret += print_blank(flags, len);
		if (is_pointer)
			ret = ft_putstr("0x");
		ret += ft_putnbr_base(value, base);
	}
	return (ret);
}

int process_u(va_list va_ptr, t_word_flags *flags, const char *base)
{
	unsigned int	value;
	int				len;
	int				i;
	int				ret;

	value = va_arg(va_ptr, unsigned int);
	len = ft_putnbr_len(value, base);
	i = 0;
	ret = 0;
	if (flags->left_align)
	{
		ret += print_zero(flags, len);
		ret += ft_putnbr_base(value, base);
		ret += print_blank(flags, len);
	}
	else
	{
		ret += print_blank(flags, len);
		ret += print_zero(flags, len);
		ret += ft_putnbr_base(value, base);
	}
	return (ret);
}

int process_s(va_list va_ptr, t_word_flags *flags)
{
	char	*value;
	int		len;
	int		i;
	int		ret;

	ret = 0;
	value = va_arg(va_ptr, char *);
	len = value == NULL ? ft_strlen(NULL_STR) : ft_strlen(value);
	i = 0;
	if (flags->left_align)
	{
		ret += print_zero(flags, len);
		ret += (value == NULL ? ft_putstr(NULL_STR) : ft_putstr(value));
		ret += print_blank(flags, len);
	}
	else
	{
		ret += print_blank(flags, len);
		ret += print_zero(flags, len);
		ret += (value == NULL ? ft_putstr(NULL_STR) : ft_putstr(value));
	}
	return (ret);
}

int process_c(va_list va_ptr, t_word_flags *flags)
{
	int				value;
	int				len;
	int				i;
	int				ret;

	len = 1;
	ret = 0;
	i = 0;
	value = va_arg(va_ptr, int);
	if (flags->left_align)
	{
		ret += print_zero(flags, len);
		ret += ft_putchar(value);
		ret += print_blank(flags, len);
	}
	else
	{
		ret += print_blank(flags, len);
		ret += print_zero(flags, len);
		ret += ft_putchar(value);
	}
	return (ret);
}