/*
"123+12" = 135로 계산

-> atoi(문자열 배열 혹은 string 변수) 함수 쓸 줄 아느냐 

atoi(s), atoi(arr)

*/

#include <iostream>
#include <string>
using namespace std;

int solution(char expression[]) {
	
	//(1) 연산자의 위치를 찾기

	int idx = 0; //연산자가 있는 위치
	char oper = ' '; //연산자 종류를 저장

	for (int i = 0; i < strlen(expression); i++) {
		if (expression[i] == '+') {
			idx = i; 
			oper = '+';
			break; 
		}
		else if (expression[i] == '-') {
			idx = i;
			oper = '-';
			break;
		}
		else if (expression[i] == '*') {
			idx = i;
			oper = '*';
			break;
		}


	}

	//(2) 연산자의 앞과 뒤에 있는 문자열 -> 숫자로 변환

	char a[7]; char b[7];
	int num1 = 0 ; int num2 = 0; //문자열에서 변환된 숫자를 담을 변수 2개

	//첫번째 수
	for (int i = 0; i < idx; i++) {  
		a[i] = expression[i];
	}

	num1 = atoi(a); //숫자로 변환
	
	//두번째 수 
	int i = idx + 1;

	for (int j = 0; j < strlen(b); j++) {
		if (i == strlen(expression))
			break;
		b[j] = expression[i];
		i++;
	}

	num2 = atoi(b); //숫자로 변환


	//(3) 연산 수행
	int result = 0;
	
	if (oper == '+') {
		result = num1 + num2;
	}
	else if (oper == '-') {
		result = num1 - num2;
	}
	else if (oper == '*') {
		result = num1 * num2;
	}

	return result; //반환

}


int main() {
	char expression[14]; //1~100,000 입력 가능
	cin >> expression;

	int result = solution(expression);
	printf("%d\n", result);

}

