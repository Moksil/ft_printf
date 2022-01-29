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
	int		a, b;
	char	c;
	void	*v_ptr1;
	void	*v_ptr2;
	void	*v_ptr3;
	v_ptr1 = &a;
	v_ptr2 = &b;
	v_ptr3 = &c;
	
	// printf("%s, %d, %d, %d, %d\n", "aaa", 1, 2);
	// ft_printf("%s, %d, %d, %d, %d\n", "aaa", 1, 2);
	// ft_printf("| len :%d\n", ft_printf("%d", 10));
	// ft_printf("aaaaa", "aaa", "bbb");
	// ft_printf("| len :%d\n", ft_printf("%s", "aaa", "bbb"));
	// printf("| len :%d\n", printf("%s", "aaa", "bbb"));
	// printf("| len :%d\n", ft_printf("%d, %s, %d", 10));
	// ft_printf("| len :%d\n", ft_printf("%% : %d%%", 50));
	// printf("| len :%d\n", printf("%% : %d%%", 50));
	// fflush(stdout);
	// ft_printf("| len :%d\n", ft_printf("first : %c, second : %c, third : %c", 'A', 'B', 'C'));
	// printf("| len :%d\n", printf("first : %c, second : %c, third : %c", 'A', 'B', 'C'));
	// fflush(stdout);

	// printf("| len :%d\n", printf("   printf: %p\n", -1));
	// printf("| len :%d\n", ft_printf("ft_printf: %p\n", -1));

	// ft_printf("%S", NULL);
	// write(1, "\b", 1);
	printf("|, return : %d\n", ft_printf("|%0+ 000#+.-5d", 123) -1);

	// printf("| len :%d\n", printf("   printf: %\n"));
	// printf("| len :%d\n", ft_printf("ft_printf: %\n"));

	// printf("   printf: %40.50d\n", 50);
	// ft_printf("ft_printf: %40.50d\n", 50);
	// printf("   printf: %d\n", -589);
	// ft_printf("ft_printf: %d\n", -589);
	// printf("   printf: %-4d\n", -2464);
	// ft_printf("ft_printf: %-4d\n", -2464);
	// printf("   printf: %.5d\n", -2372);
	// ft_printf("ft_printf: %.5d\n", -2372);
	// printf("   printf: %p\n", NULL);
	// ft_printf("ft_printf: %p\n", NULL);
	// printf("   printf: %015p\n", NULL);
	// ft_printf("ft_printf: %015p\n", NULL);
	// printf("   printf: %15p\n", NULL);
	// ft_printf("ft_printf: %15p\n", NULL);
	// printf("   printf: %-15p\n", NULL);
	// ft_printf("ft_printf: %-15p\n", NULL);

	// printf("   printf: ret = %d\n", printf("%%p::[%010d]\n", -8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%010d]\n", -8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%10d]\n", -8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%10d]\n", -8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%.5d]\n", -8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%.5d]\n", -8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%01.1d]\n", -8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%01.1d]\n", -8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%010.1d]\n", -8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%010.1d]\n", -8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%01.50d]\n", -8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%01.50d]\n", -8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%1.50d]\n", -8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%1.50d]\n", -8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%0100.50d]\n", -8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%0100.50d]\n", -8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%010d]\n", 8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%010d]\n", 8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%10d]\n", 8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%10d]\n", 8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%.5d]\n", 8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%.5d]\n", 8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%01.1d]\n", 8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%01.1d]\n", 8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%010.1d]\n", 8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%010.1d]\n", 8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%01.50d]\n", 8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%01.50d]\n", 8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%1.50d]\n", 8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%1.50d]\n", 8473));
	// printf("   printf: ret = %d\n", printf("%%p::[%0100.50d]\n", 8473));
	// ft_printf("ft_printf: ret = %d\n", printf("%%p::[%0100.50d]\n", 8473));

	// printf("   printf: %c\n", 'a');
	// ft_printf("ft_printf: %c\n", 'a');
	// printf("   printf: %10c\n", 't');
	// ft_printf("ft_printf: %10c\n", 't');
	// printf("   printf: %1c\n", 'y');
	// ft_printf("ft_printf: %1c\n", 'y');
	// printf("   printf: %010c\n", 't');
	// ft_printf("ft_printf: %010c\n", 't');
	// printf("   printf: %50.2s\n", "Coucou");
	// ft_printf("ft_printf: %50.2s\n", "Coucou");
	// printf("   printf: %50.2s\n", NULL);
	// ft_printf("ft_printf: %50.2s\n", NULL);
	// printf("   printf: %5.0s\n", "Hello");
	// ft_printf("ft_printf: %5.0s\n", "Hello");
	// printf("   printf: %.1s\n", "Test");
	// ft_printf("ft_printf: %.1s\n", "Test");
	// printf("   printf: %10s\n", NULL);
	// ft_printf("ft_printf: %10s\n", NULL);
	// printf("   printf: %10s\n", "Ok");
	// ft_printf("ft_printf: %10s\n", "Ok");

	// printf("   printf: %d\n", printf("Les bornes :  %d, %d\n", -2147483648, 2147483647));
	// ft_printf("ft_printf: %d\n", printf("Les bornes :  %d, %d\n", -2147483648, 2147483647));
	// printf("   printf: %d\n", printf("Les bornes :  %u, %u\n", 0, 4294967295));
	// ft_printf("ft_printf: %d\n", printf("Les bornes :  %u, %u\n", 0, 4294967295));
	// printf("   printf: %d\n", printf("Les bornes :  %x, %x\n", 0, 4294967295));
	// ft_printf("ft_printf: %d\n", printf("Les bornes :  %x, %x\n", 0, 4294967295));
	// printf("   printf: %d\n", printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));
	// ft_printf("ft_printf: %d\n", printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));
	// printf("   printf: %d\n\n", printf("4chiffre 1 %-12d chiffre 2 %-12d\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("4chiffre 1 %-12d chiffre 2 %-12d\n\n", 42, -42));

	// printf("   printf: %1p\n", &t);
	// ft_printf("ft_printf: %1p\n", &t);
	// printf("   printf: %1p\n", &t);
	// ft_printf("ft_printf: %1p\n", &t);

	// printf("   printf: t1 %050d\n", 10);
	// ft_printf("ft_printf: t1 %050d\n", 10);
	// printf("   printf: t2 %-50d\n", 10);
	// ft_printf("ft_printf: t2 %-50d\n", 10);
	// printf("   printf: t3 %50.0d\n", 10);
	// ft_printf("ft_printf: t3 %50.0d\n", 10);
	// printf("   printf: t4 %50.50d\n", 10);
	// ft_printf("ft_printf: t4 %50.50d\n", 10);
	// printf("   printf: t5 %50.10d\n", 10);
	// ft_printf("ft_printf: t5 %50.10d\n", 10);
	// printf("   printf: t6 %*.*d\n", 50,  5, 10);
	// ft_printf("ft_printf: t6 %*.*d\n", 50,  5, 10);
	// printf("   printf: t7 %1.50d\n", -10);
	// ft_printf("ft_printf: t7 %1.50d\n", -10);
	// printf("   printf: t8 %1.50d\n", 10);
	// ft_printf("ft_printf: t8 %1.50d\n", 10);
	// printf("   printf: t9 %2.2d\n", 10);
	// ft_printf("ft_printf: t9 %2.2d\n", 10);
	// printf("   printf: t10 %2.2d\n", -10);
	// ft_printf("ft_printf: t10 %2.2d\n", -10);
	// printf("   printf: t11 %.0 d\n", 0);
	// ft_printf("ft_printf: t11 %.0 d\n", 0);
	// printf("   printf: t12 %.d\n", 0);
	// ft_printf("ft_printf: t12 %.d\n", 0);
	// printf("   printf: t13 %01d\n", -20);
	// ft_printf("ft_printf: t13 %01d\n", -20);
	// printf("   printf: t14 %10d\n", 1000);
	// ft_printf("ft_printf: t14 %10d\n", 1000);
	// printf("   printf: %d\n\n", printf("5chiffre 1 %0d chiffre 2 %0d\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("5chiffre 1 %0d chiffre 2 %0d\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("6chiffre 1 %012d chiffre 2 %012d\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("6chiffre 1 %012d chiffre 2 %012d\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("8chiffre 1 %*d chiffre 2 %*d\n\n", 42, 6, 6, 6));
	// ft_printf("ft_printf: %d\n\n", printf("8chiffre 1 %*d chiffre 2 %*d\n\n", 42, 6, 6, 6));
	// printf("   printf: %d\n\n", printf("15chiffre 1 %.d chiffre 2 %.d\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("15chiffre 1 %.d chiffre 2 %.d\n\n", 42, -42));

	// printf("   printf: %d\n\n", printf("4caractere 1 %12c caractere 2 %12c\n\n", 'a', 'c'));
	// ft_printf("ft_printf: %d\n\n", printf("4caractere 1 %12c caractere 2 %12c\n\n", 'a', 'c'));
	// printf("   printf: 1caractere 1 %c caractere 2 %c\n\n", 'a', 'c');
	// ft_printf("ft_printf: 1caractere 1 %c caractere 2 %c\n\n", 'a', 'c');
	// printf("   printf: 3caractere 1 %   c caractere 2 % c\n\n", 'a', 'c');
	// ft_printf("ft_printf: 3caractere 1 %   c caractere 2 % c\n\n", 'a', 'c');

	// printf("   printf: %d\n\n", printf("1hexa-maj 1 %X hexa-maj 2 %X\n\n", 42, -42));
	// ft_printf("ft_printf:%d\n\n", printf("1hexa-maj 1 %X hexa-maj 2 %X\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("3hexa-maj 1 %   X hexa-maj 2 % X\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("3hexa-maj 1 %   X hexa-maj 2 % X\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("4hexa-maj 1 %12X hexa-maj 2 %int12X\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("4hexa-maj 1 %12X hexa-maj 2 %int12X\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n\n", 42, 6, 6, 6));
	// ft_printf("ft_printf: %d\n\n", printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n\n", 42, 6, 6, 6));

	// printf("   printf: %d\n\n", printf("1pointeur 1 %p pointeur 2 %p\n\n", &c, &c));
	// ft_printf("ft_printf: %d\n\n", printf("1pointeur 1 %p pointeur 2 %p\n\n", &c, &c));
	// printf("   printf: %d\n\n", printf("3pointeur 1 %   p pointeur 2 % p\n\n", &c, &c));
	// ft_printf("ft_printf: %d\n\n", printf("3pointeur 1 %   p pointeur 2 % p\n\n", &c, &c));
	// printf("   printf: %d\n\n", printf("4pointeur 1 %12p pointeur 2 %12p\n\n", &c, &c));
	// ft_printf("ft_printf: %d\n\n", printf("4pointeur 1 %12p pointeur 2 %12p\n\n", &c, &c));
	// printf("   printf: %d\n\n", printf("4pointeur 1 %-12p pointeur 2 %-12p\n\n", &c, &c));
	// ft_printf("ft_printf: %d\n\n", printf("4pointeur 1 %-12p pointeur 2 %-12p\n\n", &c, &c));
	// printf("   printf: %d\n\n", printf("5pointeur 1 %0p pointeur 2 %0p\n\n", &c, &c));
	// ft_printf("ft_printf: %d\n\n", printf("5pointeur 1 %0p pointeur 2 %0p\n\n", &c, &c));
	// printf("   printf: %d\n\n", printf("6pointeur 1 %012p pointeur 2 %012p\n\n", &c, &c));
	// ft_printf("ft_printf: %d\n\n", printf("6pointeur 1 %012p pointeur 2 %012p\n\n", &c, &c));

	// printf("   printf: %d\n\n", printf("1unsigned 1 %u unsigned 2 %u\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("1unsigned 1 %u unsigned 2 %u\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("3unsigned 1 %   u unsigned 2 % u\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("3unsigned 1 %   u unsigned 2 % u\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("4unsigned 1 %12u unsigned 2 %12u\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("4unsigned 1 %12u unsigned 2 %12u\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("4unsigned 1 %-12u unsigned 2 %-12u\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("4unsigned 1 %-12u unsigned 2 %-12u\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("5unsigned 1 %0u unsigned 2 %0u\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("5unsigned 1 %0u unsigned 2 %0u\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("6unsigned 1 %012u unsigned 2 %012u\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("6unsigned 1 %012u unsigned 2 %012u\n\n", 42, -42));
	// printf("   printf: %d\n\n", printf("8unsigned 1 %*u unsigned 2 %*u\n\n", 42, 6, 6, 6));
	// ft_printf("ft_printf: %d\n\n", printf("8unsigned 1 %*u unsigned 2 %*u\n\n", 42, 6, 6, 6));
	// printf("   printf: %d\n\n", printf("15unsigned 1 %.u unsigned 2 %.u\n\n", 42, -42));
	// ft_printf("ft_printf: %d\n\n", printf("15unsigned 1 %.u unsigned 2 %.u\n\n", 42, -42));

	
	// printf("   printf: %d\n\n", printf("%s", 0));
	// ft_printf("ft_printf: %d\n\n", printf("%s", 0));
	// printf("   printf: %d\n\n", printf("%%\n")); 
	// ft_printf("ft_printf: %d\n\n", printf("%%\n")); 
	// printf("   printf: %d\n\n", printf("%-.12u\n", -20000000));
	// ft_printf("ft_printf: %d\n\n", printf("%-.12u\n", -20000000));
	// printf("   printf: %d\n\n", printf("%-.12i\n", -20000000));
	// ft_printf("ft_printf: %d\n\n", printf("%-.12i\n", -20000000));
	// printf("   printf: %d\n", printf("truc"));
	// ft_printf("ft_printf: %d\n", printf("truc"));
	// printf("   printf: %d\n", printf("bonjour !\n", 42, -42));
	// ft_printf("ft_printf: %d\n", printf("bonjour !\n", 42, -42));
	// printf("   printf: 04 Test de chiffre sans h : %d, et %d\n", 432767, -432767);
	// ft_printf("ft_printf: 04 Test de chiffre sans h : %d, et %d\n", 432767, -432767);
	// printf("   printf: 31 This is an int : %.0d\n\n", 0);
	// ft_printf("ft_printf: 31 This is an int : %.0d\n\n", 0);
	// printf("   printf: 32 This is an int : %0d\n\n", 0);
	// ft_printf("ft_printf: 32 This is an int : %0d\n\n", 0);
	// printf("   printf: percent 1 %012%");
	// ft_printf("ft_printf: percent 1 %012%");
	// printf("   printf: percent 2 %12%");
	// ft_printf("ft_printf: percent 2 %12%");
	// printf("   printf: percent 3 %-12%");
	// ft_printf("ft_printf: percent 3 %-12%");
	// printf("   printf: percent 4 %0%");
	// ft_printf("ft_printf: percent 4 %0%");
	// printf("   printf: percent 5 % %");
	// ft_printf("ft_printf: percent 5 % %");
	// printf("   printf: percent 6 % 15%");
	// ft_printf("ft_printf: percent 6 % 15%");
	// printf("   printf: percent 7 % 12%");
	// ft_printf("ft_printf: percent 7 % 12%");
	// printf("   printf: percent 8 %  *%", 13);
	// ft_printf("ft_printf: percent 8 %  *%", 13);
	// printf("   printf: %n", &t);
	// ft_printf("ft_printf: %n", &t);
	// printf("   printf: %d\n", t);
	// ft_printf("ft_printf: %d\n", t);
	// printf("   printf: %n", NULL);
	// ft_printf("ft_printf: %n", NULL);
	// printf("   printf: %d\n", t);
	// ft_printf("ft_printf: %d\n", t);
	// printf("   printf: test %n", &t);
	// ft_printf("ft_printf: test %n", &t);
	// printf("   printf: %d\n", t);
	// ft_printf("ft_printf: %d\n", t);
	// printf("   printf: %s %n", "hello world", &t);
	// ft_printf("ft_printf: %s %n", "hello world", &t);
	// printf("   printf: %d\n", t);
	// ft_printf("ft_printf: %d\n", t);
	// printf("   printf: % .1s %n", "hey", &t);
	// ft_printf("ft_printf: % .1s %n", "hey", &t);
	// printf("   printf: %d\n", t);
	// ft_printf("ft_printf: %d\n", t);
	// printf("   printf: %40s %n", "co", &t);
	// ft_printf("ft_printf: %40s %n", "co", &t);
	// printf("   printf: %d\n", t);
	// ft_printf("ft_printf: %d\n", t);
	// printf("   printf: %050 d%n", 500, &t);
	// ft_printf("ft_printf: %050 d%n", 500, &t);
	// printf("   printf: %d\n", t);
	// ft_printf("ft_printf: %d\n", t);
	// printf("   printf: %050 u%n", 500, &t);
	// ft_printf("ft_printf: %050 u%n", 500, &t);
	// printf("   printf: %d\n", t);
	// ft_printf("ft_printf: %d\n", t);
	
	
	// ft_printf("| len :%d\n", ft_printf("first : %d, second : %d, third : %d", 2147483647, -2147483648, 2147483648));
	// ft_printf("| len :%d\n", ft_printf("first : %u, second : %u, third : %u", 2147483647, 2147483648, 3147483648));
	// printf("| len :%d\n", printf("first : %u, second : %u, third : %u", 2147483647, 2147483648, 3147483648));
	// printf("| len :%d\n", printf("first : %d, second : %ld, third : %ld", 2147483647, -2147483648, 2147483648));
	// ft_printf("| len :%d\n", ft_printf("first : %s, second : %s, third : %s", "abc", "def", "ghi"));
	// ft_printf("| len :%d\n", ft_printf("first : %x, second : %x, third : %x", 255, 511, 767));
	// ft_printf("| len :%d\n", ft_printf("first : %X, second : %X, third : %X", 255, 511, 767));
	// printf("| len :%d\n", printf("first : %x, second : %x, third : %x", 255, 511, 767));
	// printf("| len :%d\n", printf("first : %X, second : %X, third : %X", 255, 511, 767));
	// ft_printf("| len :%d\n", ft_printf("first : %p, second : %p, third : %p", v_ptr1, v_ptr2, v_ptr3));
	// printf("| len :%d\n", printf("first : %p, second : %p, third : %p", v_ptr1, v_ptr2, v_ptr3));
	return (0);
}
