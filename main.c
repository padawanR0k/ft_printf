#include "ft_printf.h"

int main()
{
	// printf("[%c]\n", 'a');
	// ft_printf("[%c]\n", 'a');

	// u 구현
	// unsigned int a = 4294967295;
	// printf("[%10u]\n", a);
	// ft_printf("[%10u]\n", a);

	// x 구현
	// printf("[%10x]\n", 123);
	// ft_printf("[%10x]\n", 123);

	// X 구현
	// printf("[%3X]\n", 123);
	// ft_printf("[%3X]\n", 123);

	// p 구현
	char *a = "Asd";
	printf("[%30p]\n", a);
	ft_printf("[%30p]\n", a);

	// 너비 구현
	// printf("[%0d]\n", 123);
	// ft_printf("[%0d]\n", 123);

	// printf("[%.10d]\n", 123456789);
	// ft_printf("[%.1d]\n", 123456789);

	// char *a = "abc";
	// printf("[%p]\n", a);
	// ft_printf("[%p]\n", a);

	// printf("[%d]\n", 2147483647);
	// ft_printf("[%d]\n", 2147483648);

	// unsigned int a = 214748364800;
	// printf("[%u]\n", a);
	// ft_printf("[%u]\n", a);

	// printf("[%10.2d]\n", 42);
	// printf("[%10.3d]\n", 42);

	// printf("[%10.*d]\n", -2, 42);
	// printf("[%10.*d]\n", -3, 42);

	// printf("[%.d]\n", 0);
	// printf("[%.d]\n", 10);
	// printf("[%.d]\n", -10);

	// printf("[%-12d]\n", 0);
	// printf("[%-12d]\n", 10);
	// printf("[%-10d]\n", 0);
	// printf("[%---10d]\n", 10);

	// printf("[%10.2s]\n", "ab");
	// printf("[%10.3s]\n", "ab");

	// printf("[%10.2c]\n", 'a');
	// printf("[%10.3c]\n", 'a');

	// printf("[%10.2p]\n", "a");
	// printf("[%10.3p]\n", "a");

	// printf("[%10.2x]\n", 32);
	// printf("[%10.3x]\n", 32);

	// printf("[%-10.2d]\n", 42);
	// printf("[%10.9d]\n", 42);
	// printf("%d", get_formats_cnt("\%s%% \n"));
	/* code */
	return 0;
}
