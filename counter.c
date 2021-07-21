int	is_format_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
	{
		return (1);
	}
	else
		return (0);
}

int	get_formats_cnt(char *str)
{
	int	cnt;
	int	is_format_set;

	cnt = 0;
	while (*(str + 1))
	{
		is_format_set = *str == '%' && is_format_specifier(*(str + 1));
		if (is_format_set)
			cnt++;
		str++;
	}
	return (cnt);
}
