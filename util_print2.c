/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:04:03 by yurlee            #+#    #+#             */
/*   Updated: 2021/06/12 17:59:55 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_diff(int diff, char c)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (diff > i)
	{
		ret += ft_putchar(c);
		i++;
	}
	return (ret);
}

int		print_zero(t_word_flags *flags, int len)
{
	int	diff;
	int	ret;

	ret = 0;
	if (flags->precision)
	{
		diff = flags->width - flags->width_p;
		if (flags->fill_zero)
			ret = print_diff(flags->width_p - len, '0');
	}
	else
	{
		diff = flags->width - len;
		if (flags->fill_zero)
			ret = print_diff(flags->width - len, '0');
	}
	return (ret);
}

int		print_blank(t_word_flags *flags, int len)
{
	int	diff;
	int	ret;

	ret = 0;
	if (flags->precision)
	{
		diff = flags->width - flags->width_p;
		if (flags->width && flags->width - flags->width_p > 0)
			ret += print_diff(diff, ' ');
	}
	else
	{
		if (flags->fill_zero == OFF)
		{
			diff = flags->width - len;
			ret += print_diff(diff, ' ');
		}
	}
	return (ret);
}

int		print_padding(t_word_flags *flags, int len)
{
	int	i;
	int	ret;
	int	width;
	int	diff;

	i = 0;
	ret = 0;
	width = 0;
	diff = flags->precision
		? flags->width - flags->width_p
		: flags->width - len;
	if (flags->left_align)
	{
		if (flags->precision)
			ret += print_diff(flags->width_p - len, '0');
		i = 0;
		if (flags->width && flags->width - flags->width_p > 0)
			ret += print_diff(diff, ' ');
	}
	else
	{
		if (flags->width && flags->width - flags->width_p > 0)
			ret += print_diff(diff, ' ');
		i = 0;
		if (flags->precision)
			ret += print_diff(flags->width_p - len, '0');
	}
	return (ret);
}