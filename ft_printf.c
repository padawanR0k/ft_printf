/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:32:44 by yurlee            #+#    #+#             */
/*   Updated: 2021/05/28 17:39:14 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(char *str)
{
	while (*str)
	{
		if (*str == '%')
		{
			// 출력
		}
		str++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list va_ptr;
	va_start(va_ptr, format);
	ft_parse(format);
	va_end(va_ptr);
	return (0);
}
