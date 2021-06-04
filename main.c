#include "ft_printf.h"

int main()
{
	// printf("[%c]\n", 'a');
	// ft_printf("[%c]\n", 'a');

	printf("[%s]\n", "abc");
	ft_printf("[%s]\n", "abc");

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
