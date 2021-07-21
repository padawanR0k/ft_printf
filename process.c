/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:17:48 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/21 18:34:33 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_id(va_list va_ptr, t_word_flags *flags)
{
	int	value;
	int	output_length;
	int	ret;

	value = va_arg(va_ptr, int);
	output_length = ft_putnbr_len(value, DECIMAL_BASE);
	ret = 0;
	if (flags->left_align == OFF && output_length < flags->width)
		ret += print_blank(flags, output_length);
	ret += print_zero(flags, output_length);
	if (!(flags->precision == ON && flags->width_p == 0 && value == 0))
		ret += ft_putnbr_base(value, DECIMAL_BASE);
	if (flags->left_align == ON && output_length < flags->width)
		ret += print_blank(flags, output_length);
	return (ret);
}

int	process_xp(va_list va_ptr, t_word_flags *flags, const char *base)
{
	int					len;
	int					ret;
	int					is_pointer;
	unsigned long long	value;

	is_pointer = flags->type == 'p';
	ret = 0;
	value = va_arg(va_ptr, unsigned long long);
	len = ft_putnbr_len(value, base);
	if (is_pointer)
		len += 2;
	if (flags->left_align == OFF)
		ret += print_blank(flags, len);
	if (is_pointer)
		ret = ft_putstr("0x");
	ret += ft_putnbr_base(value, base);
	if (flags->left_align == ON)
		ret += print_blank(flags, len);
	return (ret);
}

int	process_u(va_list va_ptr, t_word_flags *flags, const char *base)
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

int	process_s(va_list va_ptr, t_word_flags *flags)
{
	char	*value;
	int		len;
	int		i;
	int		ret;

	ret = 0;
	value = va_arg(va_ptr, char *);
	i = 0;
	if (value == NULL)
		len = ft_strlen(NULL_STR);
	else
		len = ft_strlen(value);
	if (flags->left_align == OFF)
		ret += print_blank(flags, len);
	if (value == NULL)
		ret += ft_putstr(NULL_STR);
	else
		ret += ft_putstr(value);
	if (flags->left_align)
		ret += print_blank(flags, len);
	return (ret);
}

int	process_c(va_list va_ptr, t_word_flags *flags)
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
