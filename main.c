#include <stdio.h>
#include "ft_printf.h"

// int main(void)
// {
	// int return_val;
	// printf("return : %d\n", printf("%2147483646s", "hello\n"));
	// return :2147483646 , 출력가능.
	// printf("int : %d\n", printf("%2147483647s", "hello\n"));
	// return : -1, 출력안됨.
	// printf("int : %d\n", printf("%9399999999999999991s\n", "ss"));
	// "ss\n" return : 3, 매우 많은 공백문자 출력 후 ss출력.
	// printf("int : %d\n", printf("%10000000000000000000s\n", "ss"));
	// "ss\n" return : 3, flag무시하고 일반출력.
	// return (0);
// }

int main(void)
{
	// int return_val;
    
	ft_printf("%d", ft_printf("first : %d\nsecond : %d\nthird : %d\n", 100, 200, 300));
	// return_val = printf("%d", 1234);
	// printf("%");
	//printf("%d", return_val);
	return (0);
}