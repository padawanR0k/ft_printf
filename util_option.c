/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:18:36 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/27 10:56:29 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char c)
{
	int		valid;
	char	*options;

	options = "-0.";
	valid = ft_strchr(options, c) != 0 || ft_isdigit(c);
	return (valid);
}

void	get_precision(const char **str, t_word_flags *flags)
{
	if (flags->precision == OFF)
	{
		flags->precision = ON;
		(*str)++;
		while (ft_isdigit(**str))
		{
			flags->width_p = (flags->width_p * 10) + (**str - '0');
			(*str)++;
		}
	}
}

int	check_flag_option(const char **str, t_word_flags *flags)
{
	while (is_flag(**str))
	{
		if (**str == '-')
		{
			if (flags->left_align == OFF)
				flags->left_align = ON;
			(*str)++;
		}
		else if (**str == '0')
		{
			if (flags->left_align == OFF && flags->precision == OFF)
				flags->fill_zero = ON;
			(*str)++;
		}
		else if (**str == '.')
			get_precision(str, flags);
		while (ft_isdigit(**str))
		{
			flags->width = (flags->width * 10) + (**str - '0');
			(*str)++;
		}
	}
	return (0);
}

int	is_format_specifier(char c)
{
	if (ft_strchr(FORMAT_SPECIFIER, c))
		return (1);
	else
		return (0);
}
