/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:18:36 by yurlee            #+#    #+#             */
/*   Updated: 2021/06/12 17:47:14 by yurlee           ###   ########.fr       */
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
// TODO: 왼쪽정렬 - DONE
// TODO: 너비 - DONE
// TODO: 0으로 채우기 - DONE
// TODO: 정밀도
// TODO: * 변수로 받기

int check_flag_option(const char **str, t_word_flags *flags)
{
	while (is_option(**str))
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
	}
	return (0);
}