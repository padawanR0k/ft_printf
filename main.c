#include "ft_printf.h"

int main()
{
	printf("\nprintf(\"[%%c]\", \'a\');\n");
	printf("[%c]\n", 'a');
	ft_printf("[%c]\n", 'a');
	printf("\n==============================\n\n");
	// u 구현
	unsigned int a = 4294967295;
	printf("\nprintf(\"[%%10u]\", 4294967295);\n");
	printf("[%10u]\n", a);
	ft_printf("[%10u]\n", a);
	printf("\n==============================\n\n");
	// // x 구현
	printf("\nprintf(\"[%%10x]\", 123);\n");
	printf("[%10x]\n", 123);
	ft_printf("[%10x]\n", 123);
	printf("\n==============================\n\n");
	// // X 구현
	printf("\nprintf(\"[%%3X]\", 123);\n");
	printf("[%3X]\n", 123);
	ft_printf("[%3X]\n", 123);
	printf("\n==============================\n\n");

	// p 구현
	char *a1 = "Asd";
	printf("\nprintf(\"[%%30p]\", \"Asd\");\n");
	printf("[%30p]\n", a1);
	ft_printf("[%30p]\n", a1);
	printf("\n==============================\n\n");
	// s 구현 && 왼쪽 정렬 && 너비
	char *a2 = NULL;
	printf("\nprintf(\"[%%-30s]\", NULL);\n");
	int n1 = printf("[%-30s]\n", a2);
	printf("n1: %d \n", n1);
	int n2 = ft_printf("[%-30s]\n", a2);
	printf("n2: %d \n", n2);
	printf("\n==============================\n\n");
	// s 구현  0으로 채우기
	int a3 = 1;
	printf("\nprintf(\"[%%010d]\", 1)\n");
	int n3 = printf("[%010d]\n", a3);
	printf("n3: %d \n", n3);
	int n4 = ft_printf("[%010d]\n", a3);
	printf("n4: %d \n", n4);

	printf("\n==============================\n\n");
	// s 구현  정밀도와 너비, 왼쪽정렬 겹치는 경우
	int a4 = 1;
	printf("\nprintf(\"[%%-7.5d]\", 1);\n");
	int n5 = printf("[%-7.5d]\n", a4);
	printf("n5: %d \n", n5);
	int n6 = ft_printf("[%-7.5d]\n", a4);
	printf("n6: %d \n", n6);

	printf("\n==============================\n\n");
	int a5 = 1111111;
	printf("\nprintf(\"[%%-7.5d]\", 1111111);\n");
	int n7 = printf("[%-7.5d]\n", a5);
	printf("n7: %d \n", n7);
	int n8 = ft_printf("[%-7.5d]\n", a5);
	printf("n8: %d \n", n8);

	printf("\n==============================\n\n");
	// // s 구현  정밀도 구현
	int a6 = 1;
	printf("\nprintf(\"[%%.10d]\", 1)\n");
	int n9 = printf("[%.10d]\n", a6);
	printf("n9: %d \n", n9);
	int n10 = ft_printf("[%.10d]\n", a6);
	printf("n10: %d \n", n10);
	printf("\n==============================\n\n");
	// zero 플래그 구현
	int a7 = 1;
	printf("\nprintf(\"[%%05d]\", 1);\n");
	int n11 = printf("[%05d]\n", a7);
	printf("n11: %d \n", n11);
	int n12 = ft_printf("[%05d]\n", a7);
	printf("n12: %d \n", n12);
	printf("\n==============================\n\n");
	// c 구현
	char a8 = 'A';
	printf("\nprintf(\"[%%30c]\", 'A');\n");
	printf("[%30c]\n", a8);
	ft_printf("[%30c]\n", a8);
	printf("\n==============================\n\n");
	// 너비 구현
	printf("\nprintf(\"[%%0d]\", 123);\n");
	printf("[%0d]\n", 123);
	ft_printf("[%0d]\n", 123);
	printf("\n==============================\n\n");
	printf("\nprintf(\"[%%.10d]\", 123456789);\n");
	printf("[%.10d]\n", 123456789);
	ft_printf("[%.10d]\n", 123456789);
	printf("\n==============================\n\n");
	char *a9 = "abc";
	printf("printf(\"[%%p]\", a9);\n");
	printf("[%p]\n", a9);
	ft_printf("[%p]\n", a9);
	printf("\n==============================\n\n");
	printf("printf(\"[%%d]n\", 2147483647);\n");
	printf("[%d]\n", 2147483647);
	ft_printf("[%d]\n", 2147483647);
	printf("\n==============================\n\n");
	printf("printf(\"[%%d]n\", -2147483647);\n");
	printf("[%d]\n", -2147483647);
	ft_printf("[%d]\n", -2147483647);
	printf("\n==============================\n\n");
	unsigned int a10 = 2147483648;
	printf("printf(\"[%%u]\", a10);\n");
	printf("[%u]\n", a10);
	ft_printf("[%u]\n", a10);
	printf("\n==============================\n\n");
	printf("printf(\"[%%.d]\", 0);\n");
	printf("[%.d]\n", 0);
	ft_printf("[%.d]\n", 0);
	printf("\n==============================\n\n");
	printf("printf(\"[%%.d]\", 10);\n");
	printf("[%.d]\n", 10);
	ft_printf("[%.d]\n", 10);
	printf("\n==============================\n\n");
	printf("printf(\"[%%.d]\", -10);\n");
	printf("[%.d]\n", -10);
	ft_printf("[%.d]\n", -10);
	printf("\n==============================\n\n");
	printf("printf(\"[%%-12d]\", 10);\n");
	printf("[%-12d]\n", 10);
	ft_printf("[%-12d]\n", 10);
	printf("\n==============================\n\n");
	printf("printf(\"[%%-10d]\", 0);\n");
	printf("[%-10d]\n", 0);
	ft_printf("[%-10d]\n", 0);
	printf("\n==============================\n\n");
	printf("printf(\"[%%---10d]\", 10);\n");
	printf("[%---10d]\n", 10);
	ft_printf("[%---10d]\n", 10);
	printf("\n==============================\n\n");
	printf("printf(\"[%%10.3s]\", \"ab\");\n");
	printf("[%10.3s]\n", "ab");
	ft_printf("[%10.3s]\n", "ab");
	printf("\n==============================\n\n");
	printf("printf(\"[%%10.2x]\", 32);\n");
	printf("[%10.2x]\n", 32);
	ft_printf("[%10.2x]\n", 32);
	printf("\n==============================\n\n");
	printf("printf(\"[%%d %%d]\", 32, 42);\n");
	printf("[%d %d]\n", 32, 42);
	ft_printf("[%d %d]\n", 32, 42);
	printf("\n==============================\n\n");
	printf("printf(\"[%%10.5s]\", \"a\");\n");
	printf("[%10.5s]\n", "a");
	ft_printf("[%10.5s]\n", "a");
	printf("\n==============================\n\n");
	printf("printf(\"[%%10.5s]\", \"abcdef\");\n");
	printf("[%10.5s]\n", "abcdef");
	ft_printf("[%10.5s]\n", "abcdef");
	printf("\n==============================\n\n");
	printf("printf(\"[%%5.10s]\", \"abcdef\");\n");
	printf("[%5.10s]\n", "abcdef");
	ft_printf("[%5.10s]\n", "abcdef");
	printf("\n==============================\n\n");
	printf("printf(\"[%%5.10s]\", \"a\");\n");
	printf("[%5.10s]\n", "a");
	ft_printf("[%5.10s]\n", "a");
	printf("\n==============================\n\n");
	void *p = NULL;
	printf("printf(\"[%%10.p]\", p);\n");
	printf("[%10.p]\n", p);
	ft_printf("[%10.p]\n", p);
	printf("\n==============================\n\n");
	void *p2 = NULL;
	printf("printf(\"[%%10p]\", p2);\n");
	printf("[%10p]\n", p2);
	ft_printf("[%10p]\n", p2);
	printf("\n==============================\n\n");
	void *p3 = NULL;
	printf("printf(\"[%%10p]\", p3);\n");
	printf("[%10p]\n", p3);
	ft_printf("[%10p]\n", p3);
	printf("\n==============================\n\n");
	printf("printf(\"[%%4.4d]\", -1);\n");
	printf("[%4.4d]\n", -1);
	ft_printf("[%4.4d]\n", -1);
	printf("\n==============================\n\n");
	printf("printf(\"[%%4.3d]\", -1);\n");
	printf("[%4.3d]\n", -1);
	ft_printf("[%4.3d]\n", -1);
	printf("\n==============================\n\n");
	printf("printf(\"[%%5.3d]\", -1);\n");
	printf("[%5.3d]\n", -1);
	ft_printf("[%5.3d]\n", -1);
	printf("\n==============================\n\n");
	printf("printf(\"[%%-5.3d]\", -1);\n");
	printf("[%-5.3d]\n", -1);
	ft_printf("[%-5.3d]\n", -1);
	printf("\n==============================\n\n");
	printf("printf(\"[%%10.4d]\", 123456);\n");
	printf("[%10.4d]\n", 123456);
	ft_printf("[%10.4d]\n", 123456);
	printf("\n==============================\n\n");
	/* code */
	return 0;
}
