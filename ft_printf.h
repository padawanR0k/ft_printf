/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:32:42 by yurlee            #+#    #+#             */
/*   Updated: 2021/06/04 18:32:34 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
#define FT_PRINT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

# define FLAG_LEFT_ALIGN  10
# define FLAG_BLANK  20
# define FLAG_PRECISON  30
# define FORMAT_SPECIFIER  "cspdiuxX"

typedef struct	s_word_node
{
	char		*value;
	int			type;
	int			left_align;
	int			blank;
	int			precision;
}				t_word_node;

int				ft_printf(const char *format, ...);
int				get_formats_cnt(char *str);
int				ft_putchr(const char str);
int				ft_putstr(const char *chr);
#endif