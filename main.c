#include "ft_printf.h"

#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main(void)
{
	// printf("|, return : %d\n", printf("lib |><) -5);
	// printf("|, return : %d\n", ft_printf("ft_ |><) -5);

	printf("|, return : %d\n", printf("lib |%d", INT_MIN) -5);
	printf("|, return : %d\n", ft_printf("ft_ |%d", INT_MIN) -5);
	printf("|, return : %d\n", printf("lib |%d", INT_MAX + 1) -5);
	printf("|, return : %d\n", ft_printf("ft_ |%d", INT_MAX + 1) -5);
	printf("|, return : %d\n", printf("lib |%i", INT_MIN) -5);
	printf("|, return : %d\n", ft_printf("ft_ |%i", INT_MIN) -5);
	printf("|, return : %d\n", printf("lib |%i", INT_MAX + 1) -5);
	printf("|, return : %d\n", ft_printf("ft_ |%i", INT_MAX + 1) -5);
	printf("|, return : %d\n", printf("lib |%%-d 42 == %-d\n", INT_MIN) -5);
	printf("|, return : %d\n", ft_printf("ft_ |%%-d 42 == %-d\n", INT_MIN) -5);

	return (0);
}
// g%% *.% ft_printf.h in%lufes/libft.h libft/libft.a
