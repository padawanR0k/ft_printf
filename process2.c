/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:43:43 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/24 15:03:32 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_p(va_list va_ptr, t_word_flags *flags, const char *base)
{
	int		len;
	int		ret;
	void	*value;

	ret = 0;
	value = va_arg(va_ptr, void *);
	flags->value = &value;
	len = ft_putnbr_len((long long)value, base);
	if (flags->precision && value == 0)
		len = 2;
	else
		len += 2;
	if (flags->left_align == OFF)
		ret += print_blank(flags, len);
	ret += ft_putstr("0x");
	if (!(flags->precision && value == 0))
		ret += ft_putnbr_base((long long)value, base);
	if (flags->left_align == ON)
		ret += print_blank(flags, len);
	return (ret);
}
