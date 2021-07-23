/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:17:48 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/23 18:02:24 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_id(va_list va_ptr, t_word_flags *flags)
{
	int	value;
	int	len;
	int	ret;

	value = va_arg(va_ptr, int);
	flags->value = &value;
	len = ft_putnbr_len(value, DECIMAL_BASE);
	ret = 0;
	if (flags->left_align == OFF && len < flags->width)
		ret += print_blank(flags, len);
	if (value < 0)
		ft_putchar('-');
	ret += print_zero(flags, len);
	if (!(flags->precision == ON && flags->width_p == 0 && value == 0))
		ret += ft_putnbr_base(value, DECIMAL_BASE);
	if (flags->left_align == ON && len < flags->width)
		ret += print_blank(flags, len);
	return (ret);
}

int	process_xp(va_list va_ptr, t_word_flags *flags, const char *base)
{
	int					len;
	int					ret;
	unsigned long long	value;

	ret = 0;
	value = va_arg(va_ptr, unsigned long long);
	flags->value = &value;
	len = ft_putnbr_len(value, base);
	if (flags->type == 'p')
	{
		if (flags->precision && value == 0)
			len = 2;
		else
			len += 2;
	}
	if (flags->left_align == OFF)
		ret += print_blank(flags, len);
	if (flags->type == 'p')
		ret += ft_putstr("0x");
	if (!(flags->type == 'p' && flags->precision && value == 0))
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
	flags->value = &value;
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
	flags->value = &value;
	i = 0;
	if (value == NULL)
	{
		len = ft_strlen(NULL_STR);
		value = NULL_STR;
	}
	else
		len = ft_strlen(value);
	if (!flags->left_align)
		ret += print_blank(flags, len);
	if (flags->precision && len > flags->width_p)
		ret += write(STDOUT_FILENO, value, flags->width_p);
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
	flags->value = &value;
	if (!flags->left_align)
		ret += print_blank(flags, len);
	ret += ft_putchar(value);
	if (flags->left_align)
		ret += print_blank(flags, len);
	return (ret);
}
