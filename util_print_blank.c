/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_blank.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:45:22 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/27 10:56:29 by yurlee           ###   ########.fr       */
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

int	print_blank_diuxX(t_word_flags *flags, int len)
{
	int	ret;
	int	padding;
	int	max;

	ret = 0;
	padding = 0;
	max = 0;
	if (flags->precision && flags->width)
	{
		if (flags->width_p == 0 && *(int *)flags->value == 0)
			len = 0;
		if (len > flags->width_p)
			padding = flags->width - len;
		else if (flags->width_p > len)
			padding = flags->width - flags->width_p;
		else
			padding = flags->width - len;
		if (flags->width_p >= len && *(int *)(flags->value) < 0)
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

int	print_blank_percent(t_word_flags *flags, int len)
{
	int	ret;
	int	blank;

	ret = 0;
	blank = 0;
	if (flags->fill_zero || flags->width == 0)
		return (ret);
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
		if (flags->type == 'd' || flags->type == 'i'
			|| flags->type == 'u' || flags->type == 'x'
			|| flags->type == 'X')
			ret += print_blank_diuxX(flags, len);
		else if (flags->type == 's')
			ret += print_blank_s(flags, len);
		else if (flags->type == '%')
			ret += print_blank_percent(flags, len);
		else if (flags->width && blank > 0)
			ret += print_repeat(blank, ' ');
	}
	else if (flags->fill_zero == OFF && blank > 0)
		ret += print_repeat(blank, ' ');
	return (ret);
}
