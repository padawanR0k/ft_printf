/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:34:17 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/24 13:17:23 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_zero_d(t_word_flags *flags, int len)
{
	int	ret;
	int	padding;

	ret = 0;
	padding = 0;
	padding = flags->width_p - len;
	if (*(int *)(flags->value) < 0)
		padding += 1;
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
		if (flags->type == 'd' || flags->type == 'i'
			|| flags->type == 'u')
			ret = print_zero_d(flags, len);
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