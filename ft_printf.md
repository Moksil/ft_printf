[-] 좌측정렬
[0] 너비에 맞게 빈 곳을 0으로 패딩
[.] 프리시전 = 정밀도 (= 숫자 서식에만 관여)
[ ] 너비에 맞게 빈 곳을 ‘ ‘로 채움
[#] 0, 0x, 0X 붙이기
[+] +,- 부호 표시하기
<!-- [*] 숫자 와일드카드. 가변인자로 값이 들어옴 -->

-+
It will manage any combination of the following flags: ‘-0.*’ and minimum field width with
all conversions
>printf 플래그 중에서 '-' '0' '.'을 사용 할 수 있어야 한다
>필드에서 값을 왼쪽으로 정렬한다. 기본은 오른쪽 정렬 
>0 숫자 값이 오른쪽 정렬일 때 남게 되는 빈 공간을 공백이 아닌 0 으로 채운다.
>. 의 경우에는 일부 specifier 에서만 사용 가능하고 그 외의 값에서는 무시. (실수형, 문자열, 정수
형에서 사용가능)
>기본 구현에서는 %p %c %%말고는 사용 가능할꺼에요
>- . 0 *(width | precision -> ft_printf(“|%*.*d|”, 20, 10, 12345)) 4 개가 전부 다 플래그임.
Original printf 에서는 결과를 출력하기위해 고정 버퍼를 사용. 버퍼가 다 차면 출력하고 버퍼를 비우는 식
으로 최적화를 함. But, 우리가 과제할땐 nope.
1) 처음부터 끝까지 출력할 길이 계산 -> malloc -> 출력
2) 한글자씩 출력, (format 형식)% 만나면 중단, malloc -> 출력
3) Etc..
printf 의 return value: -1 인 경우
>Malloc fail.
>유효하지 않은 specifier
>정의되지 않은 방식으로 사용되는 플래그
Original printf의 undefined를 만나면 (-1이든 무엇이든) 결과가 있어야 함. 이 과정에서 
segfault, memory leaks가 발생하면 안됨.
Original printf 의 내부: sanity check
>Stdout 에 에러가 있는지, format string 이 NULL 인지 체크함. 여기서 걸리면 -1 return.
>printf("%d %z %s\n", 20, 50, "123"); 이런식으로 중간에 이상한 specifier 값이 있으면 아
무것도 출력하지 않고 -1 을 리턴. 유효성 검사쪽에서 str 을 한번 순환하고 시작하면 됨.
%[flags][width][.precision][length][specifier]
Printf 의 동작 Debugging
1. arg sanity check (인자 유효성검사)
2. 스트링안에 %찾기
3. %전까지 write
4. %가 없었으면 리턴(null 만나면)
5. get current characters (%지시자랑 플래그 읽어오기인듯.)
6. 지시자 옵션 체크
7. conversion 처리한것 write
8. 위에 무한 반복
가변인자에 대한 설명
https://norux.me/19
printf(“%p”)
메모리 주소값: 포인터 인자로 주소를 받은 뒤 16 진수로 변환. putnbr_base 활용.
주소값의 자료형은 unsigned long 으로 처리. (unsigned int 로 하면 오류발생 가능)
*의 경우 width 를 의미. [flag] 다음에 width 값은 두 가지 방식으로 주어질 수 있는데, 하나는 숫자이고 
하나는 *. *가 올 경우 va_arg 로 가변 인자 하나를 받아서 그 안에 있는 값을 width 로 처리해야 함. 이 경
우에 예외적으로 format 안에 있는 %의 개수와 가변 인자의 개수가 달라질 수 있음. 또한 *의 경우 width
만이 아니라 precision 자리를 대체할 수도 있음. 일반적으로는 [.decimal]이나 [.]로 쓰이지만, [.*]과 같
은 방식으로도 쓰일 수 있고, 이 경우 인자를 가져와 percision value 로 쓸 수 있음. (*.2d || 2.*d 모두 가
능)
서식지정자의 수보다 주어진 매개변수의 개수가 적은 경우
>어쩔 수 없음. 컴파일 시 -W 을 주지 않으면 warning 만 나오기 때문에 동일한 결과를 얻을 수는 있
음. 
>유닛 테스트들에서 매개변수의 개수를 체크하는 테스트는 없었음.
Printf 의 테스트 관련
>https://github.com/curquiza/curqui_test
가독성 good. But, option 최신화가 안 되어 있어서 z, j, o 같은 것들이 끼어있으면 test 를 
바꿔주어야 함.
>Clang 과 gcc 가 허용하는 에러가 다르기에, clang 으로 비교하는 것이 좋음. (0 이나 -플래그
반복 시 gcc 에서는 에러 but clang 에서는 문제없음. + gcc 에서는 precision 과 0 플래그
를 같이 사용할 때 에러 발생. clang 에서는 에러 없이 0 플래그 무시하고 precision 을 취함.)
>https://github.com/gavinfielder/pft
>https://github.com/cclaude42/PFT_2019(위에랑 똑 같은 테스트 툴을 2019 버전으로 
개편한 것)
>https://42born2code.slack.com/archives/CU6MTFBNH/p1583659224342800
자동 casting 이 되는 환경에서 출력중이라서 ((unsigned int)-1 => 4298...) 해당 케이스
가 있는데 그런 부분이 안된다면 무시하셔도 됩니다. 트리키 케이스들은 아직 크게 넣은 것이 
없고 bonus 의 flag 까지만 적용된 케이스입니다. fng 라던가 ll 은 아직 적용이 안되었습니다.
>테스트케이스 공유 스레드
https://42born2code.slack.com/archives/CU6MTFBNH/p1583568289272400
서식지정자가 %s 일 때, 인자가 null 인 경우.
>(null) : 
>빈문자열 : 포맷 문자열에 %s 와 라인피드 외 다른 문자가 없고, precision 이 있으면, 5 이하일 때
출력함.
Glibc 의 pritf: 5 이하의 presicion 값에서 아무것도 출력되지 않음.
Libc 의 printf: (null) 이 잘려서 출력됨.   Mac 에서는 libc 사용.
Printf(“%p”, null)일 때, (nil)이 출력되지만, 맥에서는 잘려서 나오니 안해도 됨.
Printf(“%p”, 0) -> 0x0 프린트.
Printf(“%c”, 0)일 때, null 캐릭터(‘\0’ 출력시 ^@) 프린트 해야함. (./a.out | cat -e 로 확인)
!!!스튜디오에서 확인하는 것이 제일 안전!!!
*** width 가 음수일때: 왼쪽정렬. *로 음수를 받으면 – flag 활성화.
makefile 이 lib/libft 폴더에 있는 또다른 makefile 를 실행해서 컴파일하는 예제
NAME = program_name
FLAGS = -Wall -Wextra -Werror
SRC_NAME = main.c
SRC_PATH = ./srcs
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC_LINK = -I./includes
LIBFT = -L./lib/libft -lft
all : $(NAME)
$(NAME) : $(OBJ) libft
gcc $(FLAGS) $(OBJ) $(INC_LINK) $(LIBFT) -o $(NAME) 
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
@mkdir $(OBJ_PATH) 2> /dev/null || true
gcc $(FLAGS) $(INC_LINK) -o $@ -c $<
# libft compile
libft :
@$(MAKE) -C ./lib/libft all
clean :
@$(MAKE) -C ./lib/libft clean
@rm -rf ./obj
fclean :
@$(MAKE) -C ./lib/libft fclean
@rm -rf ./obj $(NAME)
re : fclean all
.PHONY: all clean fclean re
$(MAKE) -C
이걸 쓰면 다른 makefile 을 불러올수 있음
0 옵션 => number 에만 적용
* 옵션 => 전체 적용 다만 최소크기는 출력으로 처리
- 옵션 -> 전체 적용 좌측정렬
.* 옵션 -> str 만 적용? => str 은 f d 로 처리되나?
  . 뒤에 숫자가 없으면 0 으로 처리되는 듯?
f 에서 .* 이 먼저 적용되고 *이 나중에 적용됨
이는 s 에서도 마찬가지 따라서 s 는 f 와 동일 취급되는 듯 하다.
%d
-0 => 0 옵션을 무시함 (순서 관계없음)
prinf("%-05d\n", 555) => "555  "
.* => 0*과 같은 동작
printf("%.5d\n", 555) => "00555"
*.* => .*옵션을 적용 후 앞선 *옵션을 적용
printf("%6.5d\n", 555) => " 00555"
0*.* => 위와 동일 (0 옵션을 무시함)
printf("%06.5d\n", 555) => " 00555"
%s
0 => 적용되지 않음
printf("%05s\n", "555") => "  555"
.* => f 와 동일하게 적용됨
printf("%.5s\n", "1234567") => "12345"
*.* => %d 와 마찬가지로 뒤부터 .*부터 적용되고 *이 적용됨
printf("%6.5s\n", "1234567") => " 12345"
%f
 : 대부분 문자열과 동일하게 작동하나 잘리는 부분에서 반올림이 있고 0 옵션의 영향을 받음
printf("%8.5f\n", 0.1234567) => " 0.12346"
printf("%08.5f\n", 0.1234567) => "00.12346"
숫자가 출력되는 diuxX 는 전부 동일하게 영향을 받고 p 또한 0x 의 위치를 제외하곤 전부 동일하게 영향을 
받음.
%d 에서 .가 0 역할도 함.
printf("%p")에서 0 옵션의 여부에 따라 0x 의 위치가 바뀜. 0 옵션이 .*과 어디에서든 거의 동일하게 동작
하는 듯.
printf("%7p") => "   0x16"
printf("%07p") => "0x00016"
맥환경에서는 %%도 width precision 영향받음!
다시 컴파일 해보니 precision 옵션을 p 에 거는 경우, x 에 0 옵션을 주는 경우, 컴파일러가 아래와 같은 오
류 문구를 띄운다.
precision used with ‘p’ conversion specifier, resulting in undefined behavior
우선 warning 이 뜨는 케이스들은 undefined behavior 인 걸로 생각하고 작업하면 됨.
>아무거나 출력, 아무거나 리턴해도 됨. 다만 그 과정에서 메모리누수나 세그폴트 X
printf 형식 지정자 g 에 관한 정확하고 자세한 설명 링크
https://stackoverflow.com/a/54162153
va_arg 를 char 타입을 제외하고는, 각자 타입에 맞게 처리 해주어야 함. (특히 char 타입을 int 로 받지 않
으면 컴파일 에러.) 아래 링크 참고.
http://www.cplusplus.com/reference/cstdio/printf/?kw=printf
