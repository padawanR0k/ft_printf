/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:18:36 by yurlee            #+#    #+#             */
/*   Updated: 2021/06/05 17:39:09 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int is_option(char c)
{
	int valid;
	char *options = "-.*";

	valid = ft_strchr(options, c) != 0 || ft_isdigit(c);
	return (valid);
}

int check_flag_option(const char **str, t_word_flags *flags)
{
	while (is_option(**str))
	{
		if (**str == '-')
		{
			if (flags->left_align == OFF)
				flags->left_align = ON;
			// else
			// 	error
		}
		else if (ft_isdigit(**str))
		{
			if (flags->precision)
			{
				// 정밀도에 의한 패딩
				// 정밀도에 의한 짤림
			}
			else
			{
				while (ft_isdigit(**str))
				{
					flags->width = (flags-> width * 10) + (**str - '0');
					(*str)++;
				}
				// else
				// 	error
			}
		}
		else if (**str == '.')
		{
			if (flags->precision == OFF)
				flags->precision = ON;
			// else
			// {
			// 	error
			// }
		}
	}
	return (0);
}