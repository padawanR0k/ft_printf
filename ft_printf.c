/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:32:44 by yurlee            #+#    #+#             */
/*   Updated: 2021/06/04 18:44:19 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		process_by_format(const char *str, int *idx, va_list va_ptr)
{
	int ret;

	ret = 0;
	if (*str == 'c')
		ret = ft_putchr(va_arg(va_ptr, int));
	else if (*str == 's')
		ret = ft_putstr(va_arg(va_ptr, char *));
	else if (*str == 'p')
		ret = ft_putchr(str[*idx]);
	else if (*str == 'd')
		ret = ft_putchr(str[*idx]);
	else if (*str == 'i')
		ret = ft_putchr(str[*idx]);
	else if (*str == 'u')
		ret = ft_putchr(str[*idx]);
	else if (*str == 'x')
		ret = ft_putchr(str[*idx]);
	else if (*str == 'X')
		ret = ft_putchr(str[*idx]);
	return (ret);
}

int		core(const char *str, va_list va_ptr)
{
	int	idx;
	int is_fs;
	int ret;

	idx = 0;
	ret = 0;
	while (str[idx])
	{
		is_fs = str[idx] == '%';
		if (is_fs)
		{
			idx++;
			ret += process_by_format(str + idx, &idx, va_ptr);
		}
		else
			ret += ft_putchr(str[idx]);
		idx++;
	}

	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	va_ptr;
	int		ret;

	va_start(va_ptr, format);
	ret = core(format, va_ptr);
	va_end(va_ptr);
	return (ret);
}
