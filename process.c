/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:17:48 by yurlee            #+#    #+#             */
/*   Updated: 2021/06/05 18:12:15 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int process_id(va_list va_ptr, t_word_flags *flags)
{
	int value;
	int len;
	int i;

	value = va_arg(va_ptr, int);
	len = ft_putnbr_len(value, DECIMAL_BASE);
	i = 0;
	while (flags->width > len + i)
	{
		ft_putchar(' ');
		i++;
	}
	return (ft_putnbr_base(value, DECIMAL_BASE));
}

int process_xX(va_list va_ptr, t_word_flags *flags, const char *base)
{
	unsigned long long	value;
	int					len;
	int					i;
	int					ret;

	if (flags->type == 'p')
		ret = ft_putstr("0x");
	value = va_arg(va_ptr, unsigned long long);
	len = ft_putnbr_len(value, base);
	i = 0;
	while (flags->width > len + i)
	{
		ft_putchar(' ');
		i++;
	}
	ret += ft_putnbr_base(value, base);
	return (ret);
}

int process_u(va_list va_ptr, t_word_flags *flags, const char *base)
{
	unsigned int	value;
	int				len;
	int				i;

	value = va_arg(va_ptr, unsigned int);
	len = ft_putnbr_len(value, base);
	i = 0;
	while (flags->width > len + i)
	{
		ft_putchar(' ');
		i++;
	}
	return (ft_putnbr_base(value, base));
}