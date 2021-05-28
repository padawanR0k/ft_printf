/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:32:42 by yurlee            #+#    #+#             */
/*   Updated: 2021/05/28 14:15:08 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
#define FT_PRINT_H

# include <stdarg.h>
# include <stdio.h>

typedef struct			s_word_node
{
	void				*content;
	void				*value;
	struct s_word_node	*next;
}						t_word_node;

int						get_formats_cnt(char *str);

#endif