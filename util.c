#include "ft_printf.h"

int	ft_putchr(const char chr)
{
	write(STDOUT_FILENO, &chr, 1);
	return (1);
}

int	ft_putstr(const char *chr)
{
	int len;

	len = ft_strlen(chr);
	write(STDOUT_FILENO, chr, len);
	return (len);
}