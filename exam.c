#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// printf("%d\n", atoi("-5"));
	// printf("%d\n", atoi("05"));
	// printf("%d\n", atoi("+5"));
	// printf("%d\n", atoi(" 5"));
	// printf("%d\n", atoi("#5"));

// "cspdiuxX%"
// "[-], [0], [+], [ ], [#] / [.]"
	int 	a;
	void * ptr  = &a;

// width, precision, arglength
// s제외하면 precision > arglength인 경우에만 동작.
// width > arglength

// 
// width > precision > arglenth


// if (precision > arglength)
// {
// 	if(width > precision)
// 	{
// 		i = 0; 
// 		while (i++ < width - precision)
// 			write(1, " ", 1);
// 	}
// 	i = 0; 
// 	while (i++ < width - precision)
// 		write(1, "0", 1);
// }

// d - [width > precision > arglenth]
// -> ' ' width - precision칸 출력,
// -> '0' precision - arglength칸 출력
// -> 인자 출력 (arglength칸 차지 함.)
// => return == width

// d - [precision > arglenth]
// -> '0' precision - arglength칸 출력
// -> 인자 출력 (arglength칸 차지 함.)
// => return == precision

	// printf(", return : %d\n", printf("|%05s|", "1234567890"));
	// printf("|, return : %d\n", printf("printf(\"%%-10.5d\", 100) : |%-10.3.5d", 100) - 26);
	// printf("|, return : %d\n", printf("printf(\"%%-10. d\", 100) : |%+5.0d", 100) - 26);
	// printf("|, return : %d\n", printf("|%-15.13p", ptr) -1);
	// printf("|, return : %d\n", printf("|%-10.3s", "12345") -1);
	printf("|, return : %d\n", printf("|%5%") -1);
	// printf("|, return : %d\n", printf("|%05.4d", 512) -1);
	// printf("|, return : %d\n", printf("|%-5.11p", 10) -1);
	// printf("|, return : %d\n", printf("|%p", ptr) -1);
	// printf("|, return : %d\n", printf("|%2c", 100) -1);
	// printf("|, return : %d\n", printf("|%2p", (void *)0) -1);
	// printf("|, return : %d\n", printf("|%2d", 1234567890) -1);
	// printf("|, return : %d\n", printf("|%2i", 1234567890) -1);
	// printf("|, return : %d\n", printf("|%2u", 1234567890) -1);
	// printf("|, return : %d\n", printf("|%2x", 1234567890) -1);
	// printf("|, return : %d\n", printf("|%2X", 1234567890) -1);
	// printf("|, return : %d\n", printf("|%2%") -1);
	// printf("|, return : %d\n", printf("printf(\"%%-7.0d\", 100) : |% -7d", 100) - 25);
	// printf("|, return : %d\n", printf("printf(\"%%010.5d\", 100) : |%010.5d", 100) - 26);
	// printf("|, return : %d\n", printf("printf(\"%%10.05d\", 100) : |%10.05d", 100) - 26);
	// printf("|, return : %d\n", printf("printf(\"%%+10.5d\", 100) : |%+10.5d", 100) - 26);
	// printf("|, return : %d\n", printf("printf(\"%%10.+5d\", 100) : |%10.+5d", 100) - 26);
	// printf("|, return : %d\n", printf("printf(\"%% 10.5d\", 100) : |% 10.5d", 100) - 26);
	// printf("|, return : %d\n", printf("printf(\"%%10. 5d\", 100) : |%10. 5d", 100) - 26);
	// printf("|, return : %d\n", printf("printf(\"%%#10.5d\", 100) : |%#10.5d", 100) - 26);
	// printf("|, return : %d\n", printf("printf(\"%%10.#5d\", 100) : |%10.#5d", 100) - 26);
	// printf("|");
	// printf("|, return : %d\n", printf("%10.05d", 100));
	// printf("|");
	// printf("|, return : %d\n", printf("%10-.5d", 100));
	// printf("|");
	// printf("|, return : %d\n", printf("%10-0.5-00d", 100));
	// printf("|");
	// printf("|, return : %d\n", printf("%-10.5d", 100));
	// printf("|");
	// printf("|, return : %d\n", printf("%30I", "123"));

	// printf("|, return : %d\n", printf("%#-s", "1234567890"));

	return (0);
}

// flag : [-], [0], [#], [ ], [+]
// 5개만 flag로 정의하고 width와 [.]및 그 이후의 precision은 별도로 정의.

// warning이지만 실행은 함.
// warning이고 무시 됨.

// 각 flag별 기본 기능
// [-] :	width가 주어진 경우, 좌측부터 출력. (width가 주어진 경우 기본 출력은 우측 정렬)
// 		해당하는 인자 값을 먼저 출력한 후 출력된 인자의 길이가 width 보다 작은 만큼 공백문자 출력
// 		width가 주어 지고, 해당하는 인자를 출력했을 때의 길이가 width보다 작은 경우에만 동작
// 		width가 주어지지 않았거나, 출력된 인자의 길이가 주어진 width보다 크면 warning 없이 [-]flag 무시 됨.
// 		-> width가 주어진 경우, fadding용 공백 출력과 인자값 출력의 실행 순서를 변경
// 		ex)	("|%-6d|", 123) ->	|100   |	/ ("|%10s|", "123456")  ->	|    123456|	/ ("|%3s|", "12345")  ->	|12345|
// 			("|%6d|", 123)  ->	|   100|	/ ("|%-10s|", "123456") ->	|123456    |	/ ("|%-3s|", "12345") ->	|12345|
// 			 [-] flag를 사용해 좌측정렬(숫자)	/ [-] flag를 사용해 좌측정렬(문자열)			/ 출력된 인자의 크기(5)가 주어진 width(3) 보다 커서 [-]flag 무시됨
// [0] : width가 주어진 경우, 출력될 인자의 길이가 width 값보다 작은만큼 '0' 출력 후 인자 출력.
// 		[-]flag와 함께 사용되면 warning과 함께 [-]flag의 기능만 적용되며 [0]flag의 기능 무시됨.
// 		width가 주어 지고, 해당하는 인자를 출력했을 때의 길이가 width보다 작은 경우에만 동작
// 		width가 주어지지 않았거나, 출력된 인자의 길이가 주어진 width보다 크면 warning 없이 [0]flag 무시 됨.
// [+] : 출력하는 숫자가 양수인 경우, 해당 인자 출력 전 '+' 출력
// [ ] : 출력하는 숫자가 양수인 경우, 해당 인자 출력 전 ' ' 출력
// 		 [+]flag와 함께 사용되면 warning과 함께 [+]flag의 기능만 적용되며 [ ]flag의 기능 무시됨.
// [#] : %x, %X인 경우 진법표기 구분자 출력, 숫자 출력 이전에 0x, 0X 출력
// 		 %x, %X를 제외한 경우 (%c, %s, %p, %d, %i, %u) [#]flag가 사용시 warning과 함께 [#]flag 무시됨.
// 		(subject에서 구현 안하는 %o(8진수 출력)에도 사용 됨 -> 숫자 출력 이전에 '0'출력)
// width : 인자의 출력 길이 값이 width보다 큰 경우 width 값 무시됨.
// 			[-] or [0] flag의 option에 맞게 ' ' 혹은 '0'으로 fadding되고, fadding과 flag로 인한 변화를 포함한 최종 출력 길이가 width와 같아짐.
			

// [.] 및 이하 precision : specifier별로 다르게 동작하므로 specifier별 flag 구현에서 설명.



// flag 와 width, precision의 결합 조건

// flag인 [0] or [-], [+] or [ ], [#] 간에는 순서 상관 없이 조합 가능해야함.
// 5개의 flag를 모두 동시에 사용하여 컴파일 시, warning으로 실행은 가능하지만, 동시 사용 불가능한 기능은 무시 됨.
// ->	'+' overrides a ' ' if both are used
// 		'-' overrides a '0' if both are used) in man printf
// 함께 사용해서 출력 결과가 바뀔 수 있는 최대 동시 사용 가능 flag의 갯수 ft_printf subject 내에서는 2개.
// -> subject를 한정하여 생각할 경우 [#]는 %x와 %X에만 적용되고 %x, %X에는 [+] or [ ]가 기능무시 warning이므로,
// -> %x, %X에는 [#]과 [-] or [0]의 조합만 가능하고 이외 형식지정자의 경우 가능한 flag의 조합은 [-] or [0] 와 [+] or [ ] 의 조합 밖에 없음.
// 같은 flag가 중복되어 나타나더라도 warning 없이 정상출력. ex) ft_printf("|%#000#0##08x|", 255"); -> |0x0000ff|

// specifier를 제외한 모든 flag([-], [0], [+] , [ ], [#])와 width number 그리고 [.]와 그에 해당하는 precision number는 optional
// [.]를 사용한 경우 이후 precision을 나타내는 숫자 또한 optional이지만 [.]이후 숫자가 없이 사용될 경우 .0으로 처리됨.
// flag와 width를 나타내는 숫자와 [.] 및 [.] 이하 precision을 나타내는 숫자를 사용한다면 아래와 같은 순서대로 사용해야함.
// %(flag)(width number)(.(precision number))(specifier) 이 순서로 적히지 않으면 warning



//  specifier 별 flag [-], [0], [+] , [ ], [#]와 width, [.] 이하 precision의 적용

// 해당 인자의 출력 길이 값 : 현재 처리하고있는 specifier에 상응하는 가변인자가 별도 flag 없이 출력 될 경우의 길이
// ex)	printf("%d", 1000) : 4	/	printf("%s", "abcdefg") : 7
// 		printf("%%") : 1		/	printf("%c", 'a') : 1

// width는 모든 specifier에서 동일하게 적용 됨.
// -> [-] or [0]에 따라 달라지는 부분은 specifier별 [-] flag, [0] flag의 설명 참조.

// ____________________%c____________________
// [-] : (정상실행) (width 주어지지 않은경우 무시 됨)
// [0] : (warning)  but 수행은 함, (width 주어지지 않은 경우 무시 됨) -> 0 fadding
// 		 + [-] : (warning) 동시 사용 불가 동시 사용시 warning 출력 후 [-]만 인식 됨
// 			-> " '-' overrides a '0' if both are used " in man printf
// [+] : (warning) and [+] flag 무시됨 
// [ ] : (warning) and [ ] flag 무시됨 
// [#] : (warning) and [#] flag 무시됨 

// [. + precision] : (warning) and [.] 및 이하 precision 무시 됨

// warning 없이 사용 가능한 flag 조합 : %-(width)c
// __________________________________________

// ____________________%s____________________
// [-] : (정상실행) (width 주어지지 않은경우, 해당 인자의 출력 길이 값보다 작은 width 주어진 경우 무시 됨)
// [0] : (warning) but 수행은 함, (width 주어지지 않은 경우 무시 됨) -> 0 fadding
// 		 + [-] : (warning) 동시 사용 불가 동시 사용시 warning 출력 후 [-]만 인식 됨
// 			-> " '-' overrides a '0' if both are used " in man printf
// [+] : (warning) and [+] flag 무시됨
// [ ] : (warning) and [ ] flag 무시됨
// [#] : (warning) and [#] flag 무시됨

// [. + precision] : (정상실행) precision이 해당 인자 출력 길이 값 보다 큰 경우 무시 됨
// 					해당 인자 출력 길이 값 보다 작은 경우 동작. 문자열이 앞에서부터 precision number 칸만큼만 출력 됨
// 					ex)	문자열 "1234567890"의 해당 인자 출력 길이 값 : 10
// 						printf("%.15s", "1234567890") -> 1234567890 (무시된 경우)
// 						printf("%.5s", "1234567890") -> 12345 (동작한 경우)

// warning 없이 사용 가능한 flag 조합 : %-(width)(. precision)s
// __________________________________________

// ____________________%p____________________
// [-] : (정상실행) (width 주어지지 않은경우 무시 됨)
// [0] : (warning)  but 수행은 함, (width 주어지지 않은 경우 무시 됨) -> 0 fadding
// 		 + [-] : (warning) 동시 사용 불가 동시 사용시 warning 출력 후 [-]만 인식 됨
// 			-> " '-' overrides a '0' if both are used " in man printf
// [+] : (warning) and [+] flag 무시됨 
// [ ] : (warning) and [ ] flag 무시됨 
// [#] : (warning) and [#] flag 무시됨 

// [. + precision] : (warning) and [.] 및 이하 precision 무시 됨

// warning 없이 사용 가능한 flag 조합 : %-(width)c
// __________________________________________

// "cspdiuxX%"

// 	flag, width, precision 파싱 방법
// 	%부터 specifier사이의 string을 한칸씩 탐색.

// 	[-] flag ON 조건
// 	현재 탐색하는 칸이 [-]일 때, 앞칸이 [0], [ ], [+], [#]이다.
// 	-> 만약 [0] flag가 ON이면 [0] flag 를 OFF로 변경.

// 	[0] flag ON 조건
// 	현재 탐색하는 칸이 [0]일 때, [-] flag 가 OFF이고 앞칸이 [ ], [+], [#]이다.

// 	[+] flag ON 조건
// 	현재 탐색하는 칸이 [+]일 때, 앞칸이 [-], [0], [ ], [#]이다.
// 	-> 만약 [ ] flag가 ON이면 [ ] flag 를 OFF로 변경.

// 	[ ] flag ON 조건
// 	현재 탐색하는 칸이 [ ]일 때, [+] flag가 OFF일 이고 앞칸이 [-], [0], [#]이다.

// 	[#] flag ON 조건
// 	현재 탐색하는 칸이 [#]일 때, [-], [0], [+], [ ]이다.

// 	width값 초기화 방법
// 	현재 탐색하는 칸이 0을 제외한 숫자일 때, 앞 칸이 [-], [ ], [+], [#]이다.
// 	현재 칸에서 atoi수행, 그 값으로 width로 초기화.

// 	precision값 초기화 방법
// 	현재 탐색하고있는 칸이 [.]이다.
// 	 - [.]다음칸이 숫자인 경우 (0포함) : [.] 다음칸 숫자에서 atoi()하여 precision초기화.
// 		- [.]다음칸이 숫자가 아닌 경우 : precision = 0으로 초기화
// 	[.]이 없는 경우 : 
// 		- precision = 인자의 출력 길이 값.
// 	* string의 경우 인자의 출력 길이 값보다 작은 경우에만 동작, 숫자 값의 경우 인자의 출력 길이 값보다 큰 경우에만 동작.


// printf(" -> return : %d\n", printf("%.3s", (char *)0));
// ㄴ> |(nu|, return : 3, warning
// printf("%.3s", (char *)0) :  |(nu|, return : 3, clang OK
// ㄴ> |(nu|, return : 3, clang, gcc OK 
