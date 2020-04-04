#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using namespace std;

int solution(int num) {

	//자연수 num에 1을 더한 수를 리턴

	/*
	일단 999를 입력하면..
	숫자로 받아오고 
	1더해서 계산하고 -> 1000
	문자열로 저장해서      ??숫자를 문자로??
	1011 ->  
	*/

	int result = num + 1; //일단 1더해서 계산
	char arr[20]; //1더해서 나올 수 있는 값은 최대 19자리 수 이므로
	_itoa_s(result, arr, 10); //문자열로 arr배열에 10진수로 저장

	for (int i = 0; i <20; i++) {
		
		if (arr[i] == '\0')
			break;

		if (arr[i] == '0') { //0이면 1로 바꾸기
			arr[i] = '1';
			
		}
	}

	
	result = atoi(arr); //문자열을 정수로 변환


	return result; //반환


	/*
	숫자를 문자열로 바꾸는 함수 
	itoa() 

	문자를 정수숫자로 바꾸는 함수 atoi()

	*/
	
}


int main() {

	
	int num;
	cin >> num;  //0을 포함하지 않는 num입력

	int result = solution(num);

	printf("result => %d", result);

}