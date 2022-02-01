# flag : [-], [0], [#], [ ], [+]
### 이상의 5개만 flag로 정의하고 width와 [.]및 precision은 별도로 정의.
## 각 flag별 기본 기능

- [-] :	width가 주어진 경우, 좌측부터 출력.(width가 주어진 경우 기본 출력은 우측 정렬)
	- 해당하는 인자 값을 먼저 출력한 후 출력된 인자의 길이가 width 보다 작은 만큼 공백문자 출력
	- width가 주어 지고, 해당하는 인자를 출력했을 때의 길이가 width보다 작은 경우에만 동작
	- width가 주어지지 않았거나, 출력된 인자의 길이가 주어진 width보다 크면 warning 없이 [-]flag 무시 됨.
	<br> => width가 주어진 경우, fadding용 공백의 출력과 인자 값 출력의 실행 순서를 변경
<br>
<br>

- [0] : width가 주어진 경우, 출력될 인자의 길이가 width 값보다 작은만큼 '0' 출력 후 인자 출력.
	- [-]flag와 함께 사용되면 warning과 함께 [-]flag의 기능만 적용되며 [0]flag의 기능 무시됨.
	- width가 주어 지고, 해당하는 인자를 출력했을 때의 길이가 width보다 작은 경우에만 동작
	- width가 주어지지 않았거나, 출력된 인자의 길이가 주어진 width보다 크면 warning 없이 [0]flag 무시 됨.
<br>
<br>

- [+] : 출력하는 숫자가 양수인 경우, fadding 0와 해당 인자 출력 전 '+' 출력
	- width가 인자 출력 길이보다 커서 fadding을 위한 공백이나 0이 발생하는 경우 그 공간 1칸을 대신함.
<br>
<br>

- [ ] : 출력하는 숫자가 양수인 경우, fadding 0와 해당 인자 출력 전 ' ' 출력
	- width가 인자 출력 길이보다 커서 fadding을 위한 공백이나 0이 발생하는 경우 그 공간 1칸을 대신함.
	- [+]flag와 함께 사용되면 warning과 함께 [+]flag의 기능만 적용되며 [ ]flag의 기능 무시됨.
<br>
<br>

- [#] : %x, %X의 경우 진법표기 구분자 출력. (16진수 인자 및 fadding 0 출력 이전에 0x, 0X 출력)
	- %x, %X를 제외한 경우 (%c, %s, %p, %d, %i, %u) [#]flag가 사용시 warning과 함께 [#]flag 무시됨.
		<br>(subject에서 구현 안하는 %o(8진수 출력)에도 사용 됨 -> 숫자 출력 이전에 '0'출력)

<br>
<br>

# width 및 [.]과 precision

- width : 해당 인자의 출력 너비 지정.
	- 인자의 출력 길이 값이 width보다 큰 경우 width 값 무시됨.
<br><br>
- [.] 및 이하 precision : 최소 정확도 지정.
	- [.]이후 바로 다음 칸 숫자가 등장하지 않으면 precision을 0으로 인식.
	- specifier별로 다르게 동작하므로 specifier별 flag 구현에서 설명.

<br><br>

# flag 와 width, precision의 결합 조건

- flag인 [0] or [-], [+] or [ ], [#] 간에는 순서 상관 없이 조합 가능해야함.
	- 5개의 flag를 동시에 사용하여 컴파일 시, warning으로 실행은 가능하지만, 동시 사용 불가능한 기능은 무시 됨.	<br>
	->	'+' overrides a ' ' if both are used
		'-' overrides a '0' if both are used) in man printf
	- ft_printf 에서는 함께 사용해서 출력 결과가 바뀔 수 있는 최대 동시 사용 가능 flag의 갯수  2개.<br>
	-> subject를 한정하여 생각할 경우 [#]는 %x와 %X에만 적용되고,<br> %x, %X에는 [+] or [ ]가 기능무시 warning이므로, %x, %X에는 [#]과 [-] or [0]의 조합만 가능.<br> 이외 형식지정자의 경우 가능한 flag의 조합은 [-] or [0] 와 [+] or [ ] 의 조합 밖에 없음.
	- 같은 flag가 중복되어 나타나더라도 warning 없이 정상출력. ex) ft_printf("|%#000#0##08x|", 255"); -> |0x0000ff|

	- specifier를 제외한 모든 flag([-], [0], [+] , [ ], [#])와 width number 그리고 [.]와 그에 해당하는 precision number는 optional
	- [.]를 사용한 경우 이후 precision을 나타내는 숫자 또한 optional이지만 [.]이후 숫자가 없이 사용될 경우 .0으로 처리됨.
	- flag와 width를 나타내는 숫자와 [.] 및 이하 precision을 나타내는 숫자를 기재한다면 아래와 같은 순서대로 사용해야함.<br>
	-> [%(flag)(width number)(.(precision number))specifier] 이 순서로 적히지 않으면 warning(나타난 flag의 기능이 모두 동작은 함)

<br><br>

 # __specifier 별 flag [-], [0], [+] , [ ], [#]와 width, [.] 이하 precision의 적용__
	출력 길이: 현재 처리하고있는 specifier에 상응하는 가변인자가 별도 flag 없이 출력 될 경우의 길이
	ex)	printf("%d", 1000) : 4	/	printf("%s", "abcdefg") : 7

	width는 모든 specifier에서 동일하게 적용 됨.
	-> [-] or [0]에 따라 달라지는 부분은 specifier별 [-] flag, [0] flag의 설명 참조.

### __%%__

	[-] : (정상실행)
		width 주어지지 않은경우 or 인자의 출력 길이 보다 작은 width 주어진 경우 무시 됨
	[0] : (warning)  but 수행은 함
		[-] flag가 무시되는 경우 [0]도 무시 됨
		with [-] : (warning) 동시 사용 불가 동시 사용시 warning 출력 후 [-]만 인식 됨
		-> " '-' overrides a '0' if both are used " in man printf
	[+] : (warning) and [+] flag 무시됨 
	[ ] : (warning) and [ ] flag 무시됨 
	[#] : (warning) and [#] flag 무시됨 

	[. + precision] : (warning) and [. + precision] 무시 됨


### __%c (%C 사용 가능)__

	[-] : (정상 실행)
		width 주어지지 않은 경우,
		인자의 출력 길이 보다 작거나 같은 width 주어진 경우 무시 됨.
	[0] : (warning)  but 수행은 함
		[-] flag가 무시되는 경우 [0]도 무시 됨
		with [-] : (warning) 동시 사용 불가 동시 사용시 warning 출력 후 [-]만 인식 됨
		-> " '-' overrides a '0' if both are used " in man printf
	[+] : (warning) and [+] flag 무시됨 
	[ ] : (warning) and [ ] flag 무시됨 
	[#] : (warning) and [#] flag 무시됨 

	[. + precision] : (warning) and [. + precision] 무시 됨

### __%s__

	[-] : (정상 실행)
		width 주어지지 않은 경우,
		인자의 출력 길이 보다 작거나 같은 width 주어진 경우 무시 됨.
	[0] : (warning) but 수행은 함
		[-] flag가 무시되는 경우 [0]도 무시 됨
		with [-] : (warning) 동시 사용 불가 동시 사용시 warning 출력 후 [-]만 인식 됨
		-> " '-' overrides a '0' if both are used " in man printf
	[+] : (warning) and [+] flag 무시됨
	[ ] : (warning) and [ ] flag 무시됨
	[#] : (warning) and [#] flag 무시됨

	[. + precision] : (정상 실행)
		precision이 해당 인자 출력 길이 값 보다 큰 경우 무시 됨
		해당 인자 출력 길이 값 보다 작은 경우 동작. 문자열이 앞에서부터 precision number 칸만큼만 출력 됨
			ex)	문자열 "1234567890"의 인자 길이 : 10
			printf("%.15s", "1234567890") -> 1234567890 (무시된 경우)
			printf("%.5s", "1234567890") -> 12345 (동작한 경우)


### __%d, %i (%D 사용 가능)__

	[-] : (정상 실행)
		1. width 주어 지지 않은 경우
		2. 인자의 출력 길이 보다 작거나 같은 width 주어진 경우(-, +, ' ' 부호 포함 길이).
		3. precision보다 작은 width	가 주어진 경우.
		이상 3가지 경우 무시됨.
	[0] : (정상 실행)
		[-] flag가 무시되는 경우 [0]도 무시 됨
		with [-] : (warning) 동시 사용 불가 동시 사용시 warning 출력 후 [-]만 인식 됨
		-> " '-' overrides a '0' if both are used " in man printf
		with [.] : [0] flag 무시 됨 (중요!) (precision이 무엇이든 상관 없음) (point!!)
	[+] : (정상실행)
		width가 인자 길이보다 큰 경우 fadding 되는 ' ' or '0' 한칸을 부호 표시를 공간으로 대체
		width가 인자 길이와 같거나 작은 경우 부호 표시용 공간 추가 되어 인자가 양수일 때 인자 출력 전 '+' 출력
	[ ] : (정상 실행)
		width가 인자 길이보다 큰 경우 fadding 되는 ' ' or '0' 한칸을 부호 표시를 공간으로 대체
		width가 인자 길이와 같거나 작은 경우 부호 표시용 공간 추가 되어 인자가 양수일 때 인자 출력 전 ' ' 출력
	[#] : (warning) and [#] flag 무시됨 

	[. + precision] : (정상 실행)
		부호 '-', '+', ' ' 제외한 인자 길이보다 작은 precision이 주어진 경우 무시 됨
		부호 출력 이후 precision과 부호 제외 인자의 길이의 차 만큼 '0' fadding 이후 인자 출력.

### __%u (%U 사용 가능)__

	[-] : (정상 실행)
		1. width 주어 지지 않은 경우
		2. 인자의 출력 길이 보다 작거나 같은 width 주어진 경우
		3. precision보다 작은 width	가 주어진 경우.
		이상 3가지 경우 무시됨.
	[0] : (정상 실행)
		[-] flag가 무시되는 경우 [0]도 무시 됨
		with [-] : (warning) 동시 사용 불가 동시 사용시 warning 출력 후 [-]만 인식 됨
		-> " '-' overrides a '0' if both are used " in man printf
		with [.] : [0] flag 무시 됨 (중요!) (precision이 무엇이든 상관 없음)
	[+] : (warning) and [+] flag 무시됨
	[ ] : (warning) and [ ] flag 무시됨
	[#] : (warning) and [#] flag 무시됨

	[. + precision] : (정상 실행)
		인자 길이보다 작은 precision이 주어진 경우 무시 됨
		precision과 인자의 길이의 차 만큼 '0' fadding 이후 인자 출력.

### __%p__

	[-] : (정상실행) 
		1. width 주어지지 않은 경우
		2. 인자의 출력 길이 보다 작거나 같은 width 주어진 경우("0x" 포함한 길이)
		3. precision보다 작은 width	가 주어진 경우.
		이상 3가지 경우 무시됨.
	[0] : (warning) but 수행은 함
		[-] flag가 무시되는 3가지 경우 [0]도 무시됨.
		with [-] : (warning) 동시 사용 불가 동시 사용시 warning 출력 후 [-]만 인식 됨
		-> " '-' overrides a '0' if both are used " in man printf
		with [.] : [0] flag 무시 됨 (중요!) (precision이 무엇이든 상관 없음)
	[+] : (warning) and [+] flag 무시됨 
	[ ] : (warning) and [ ] flag 무시됨 
	[#] : (정상 실행) and [#] flag 무시됨 

	[. + precision] : (warning) but 수행은 함
		"0x" 제외 인자 길이보다 작은 precision이 주어진 경우 무시 됨.
		"0x"출력 이후 precision과 "0x"제외 인자의 길이의 차 만큼 '0' fadding 이후 인자 출력.


### __%x, %X__

	[-] : (정상실행) 
		1. width 주어지지 않은 경우
		2. 인자의 출력 길이 보다 작거나 같은 width 주어진 경우([#] flag ON인 경우 "0x" 포함한 길이)
		3. precision보다 작은 width	가 주어진 경우.
		이상 3가지 경우 무시됨.
	[0] : (warning) but 수행은 함
		[-] flag가 무시되는 3가지 경우 [0]도 무시됨.
		with [-] : (warning) 동시 사용 불가 동시 사용시 warning 출력 후 [-]만 인식 됨
		-> " '-' overrides a '0' if both are used " in man printf
		with [.] : [0] flag 무시 됨 (중요!) (precision이 무엇이든 상관 없음)
	[+] : (warning) and [+] flag 무시됨 
	[ ] : (warning) and [ ] flag 무시됨 
	[#] : fadding 0 및 16진수 인자 출력 이전 진법표기 구분자(0x, 0X) 출력.

	[. + precision] : (warning) but 수행은 함
		"0x" 제외 인자 길이보다 작은 precision이 주어진 경우 무시 됨.
		precision과 "0x"제외 인자의 길이의 차 만큼 '0' fadding 이후 인자 출력.

---

<br><br>

# flag, width, precision 파싱 방법

### %부터 specifier까지의 string에서 char형 문자 한칸씩 탐색.

	[-] flag ON 조건
	1. 현재 탐색하는 칸이 첫번째 칸이고, [-]이다.
	2. 현재 탐색하는 칸이 [-]일 때, 앞칸이 [0], [ ], [+], [#]이거나 숫자이다.
	-> 만약 [0] flag가 ON이면 [0] flag 를 OFF로 변경.

	[0] flag ON 조건
	1. 현재 탐색하는 칸이 첫번째 칸이고, [0]이다.
	2. 현재 탐색하는 칸이 [0]일 때, [-] flag 가 OFF이고 앞칸이 [ ], [+], [#]이다.

	[+] flag ON 조건
	1. 현재 탐색하는 칸이 첫번째 칸이고, [+]이다.
	2. 현재 탐색하는 칸이 [+]일 때, 앞칸이 [-], [0], [ ], [#]이다.
	-> 만약 [ ] flag가 ON이면 [ ] flag 를 OFF로 변경.

	[ ] flag ON 조건
	1. 현재 탐색하는 칸이 첫번째 칸이고, [ ]이다.
	2. 현재 탐색하는 칸이 [ ]일 때, [+] flag가 OFF일 이고 앞 칸이 [-], [0], [#]이거나 숫자이다.

	[#] flag ON 조건
	1. 현재 탐색하는 칸이 첫번째 칸이고, [#]이다.
	2. 현재 탐색하는 칸이 [#]일 때, 앞 칸이 [-], [0], [+], [ ]이거나 숫자이다.

	width값 초기화 방법
	현재 탐색하는 칸이 0을 제외한 숫자일 때, 앞 칸이 [-], [ ], [+], [#]이다.
	현재 칸에서 숫자가 아니거나 %를 만날 때 까지 왼쪽으로 한칸씩 이동했을 때의 멈춘 값이 '.'이면 width가 아님.
	위 조건을 만족하면 현재 칸에서 atoi수행, 그 값으로 width로 초기화.

	precision값 초기화 방법
	현재 탐색하고있는 칸이 [.]이다.
	 - [.]다음칸이 숫자인 경우 (0포함) : [.] 다음칸 숫자에서 atoi()하여 precision초기화.
		- [.]다음칸이 숫자가 아닌 경우 : precision = 0으로 초기화
	[.]이 없는 경우 : 
		- precision = 인자의 출력 길이 값 혹은 별도의 값으로 지정하여 구분.
