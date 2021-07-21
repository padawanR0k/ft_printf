/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:04:03 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/21 18:36:00 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_diff(int diff, char c)
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

int	print_zero(t_word_flags *flags, int len)
{
	int	diff;
	int	ret;

	ret = 0;
	if (flags->precision)
	{
		diff = flags->width_p - len;
		if (diff > 0)
			ret = print_diff(diff, '0');
	}
	else
	{
		diff = flags->width - len;
		if (flags->fill_zero)
			ret = print_diff(diff, '0');
	}
	return (ret);
}

int	print_blank(t_word_flags *flags, int len)
{
	int	diff;
	int	ret;

	ret = 0;
	if (flags->precision)
	{
		diff = flags->width - flags->width_p;
		if (len - flags->width_p < 0)
			diff += (len - flags->width_p) * -1;
		if (flags->width && flags->width - flags->width_p > 0)
			ret += print_diff(diff, ' ');
	}
	else
	{
		if (flags->fill_zero == OFF)
		{
			diff = flags->width - len;
			if (diff > 0)
				ret += print_diff(diff, ' ');
		}
	}
	return (ret);
}
