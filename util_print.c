/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurlee <yurlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:18:38 by yurlee            #+#    #+#             */
/*   Updated: 2021/07/23 16:49:06 by yurlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char chr)
{
	return (write(STDOUT_FILENO, &chr, 1));
}

int	ft_putstr(const char *chr)
{
	int	len;

	len = ft_strlen(chr);
	return (write(STDOUT_FILENO, chr, len));
}

int	ft_putnbr_len(long long n, const char *base)
{
	int					len;
	unsigned long long	base_len;
	unsigned long long	nbr;

	len = 0;
	base_len = (unsigned long long)ft_strlen(base);
	if (n < 0)
		len += 1;
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	while (nbr > base_len - 1)
	{
		nbr = nbr / base_len;
		len += 1;
	}
	len += 1;
	return (len);
}

int	printnbr(unsigned long long n, const char *base,
	unsigned long long base_len)
{
	unsigned long long	div;
	unsigned long long	mod;
	int					len;

	len = 0;
	if (n > base_len - 1)
	{
		div = n / base_len;
		mod = n % base_len;
		len += printnbr(div, base, base_len);
		len += ft_putchar(base[mod]);
	}
	else
	{
		len += ft_putchar(base[n]);
	}
	return (len);
}

int	ft_putnbr_base(long long n, const char *base)
{
	unsigned long long	nbr;
	int					base_len;
	int					len;

	base_len = ft_strlen(base);
	len = 0;
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	len += printnbr(nbr, base, (unsigned long long)base_len);
	return (len);
}
