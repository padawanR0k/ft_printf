/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_blank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:04:03 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/23 18:00:17 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_repeat(int diff, char c)
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

int	print_blank_d(t_word_flags *flags, int len)
{
	int	ret;
	int	padding;
	int	max;

	ret = 0;
	padding = 0;
	max = 0;
	if (flags->precision && flags->width)
	{
		if (len > flags->width_p)
			padding = flags->width - len;
		else
		{
			if (flags->width_p > len)
				max = flags->width_p;
			else
				max = len;
			padding = flags->width - max;
		}
		if (*(int *)(flags->value) < 0)
			padding -= 1;
	}
	else if (flags->width)
		padding = flags->width - len;
	ret += print_repeat(padding, ' ');
	return (ret);
}

int	print_blank_s(t_word_flags *flags, int len)
{
	int	ret;
	int	blank;

	ret = 0;
	blank = 0;
	if (len > flags->width_p)
		blank = flags->width - flags->width_p;
	else
		blank = flags->width - len;
	ret += print_repeat(blank, ' ');
	return (ret);
}

int	print_blank(t_word_flags *flags, int len)
{
	int	blank;
	int	ret;

	ret = 0;
	blank = flags->width - len;
	if (flags->precision)
	{
		if (flags->type == 'd')
			ret += print_blank_d(flags, len);
		else if (flags->type == 's')
			ret += print_blank_s(flags, len);
		else if (flags->width && blank > 0)
			ret += print_repeat(blank, ' ');
	}
	else if (flags->fill_zero == OFF && blank > 0)
		ret += print_repeat(blank, ' ');
	return (ret);
}
