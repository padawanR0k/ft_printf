/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_zero_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:59:33 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/26 21:09:55 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_zero_di(t_word_flags *flags, int len)
{
	int	ret;
	int	padding;

	ret = 0;
	padding = flags->width_p - len;
	if (*(int *)(flags->value) < 0)
		padding += 1;
	ret = print_repeat(padding, '0');
	return (ret);
}

int	print_zero_percent(t_word_flags *flags, int len)
{
	int	ret;
	int	padding;

	ret = 0;
	padding = flags->width - len;
	ret = print_repeat(padding, '0');
	return (ret);
}

int	print_zero(t_word_flags *flags, int len)
{
	int	diff;
	int	ret;

	ret = 0;
	if (flags->precision)
	{
		if (flags->type == 'd' || flags->type == 'i')
			ret = print_zero_di(flags, len);
		else if (flags->type == '%')
			ret = print_zero_percent(flags, len);
		else
		{
			diff = flags->width_p - len;
			if (diff > 0)
				ret = print_repeat(diff, '0');
		}
	}
	else
	{
		diff = flags->width - len;
		if (flags->fill_zero)
			ret = print_repeat(diff, '0');
	}
	return (ret);
}
