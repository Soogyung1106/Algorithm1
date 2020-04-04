/*
해밍 거리 문제 

-> 배열에서 서로 다른 문자의 개수

for문 돌려서 처음부터 돌면서 요소가 같은지 비교


strlen함수 -> 문자열 배열의 경우 

*/


#include <iostream>
#include <string>

using namespace std;

int solution(char binaryA[], char binaryB[]) {
	
	//(1)길이가 더 긴 2진수 문자열의 길이를 구하기
	
	int a = strlen(binaryA);
	int b = strlen(binaryB);
	
	int length = 0; //두 문자열 중 더 긴 문자열의 길이를 저장
	int hamming = 0; //해밍거리

	/*
	길이 2<5
	a의 길이를 5로 맞춰주기 
	앞에서부터 채우기 
	10010
	10  -> 0번째 위치를 (5-2)번째 위치로 이동
	*/
	
	//(2) 길이가 짧은 이진수 배열 앞에 0으로 채워주기
	
	if (a < b) {  
		length = b; 
		int idx1 = b - a; //첫 번째 for문에서 사용 
		int idx2 = idx1;  //두 번째 for문에서 사용
		
		/*
		...그 전까지는 모두 0으로 채워주기
		binaryA[idx] = binaryA[0];
		binaryA[idx+1] = binaryA[1];
		...
		*/

		for (int i = 0; i< a; i++) { //시작 위치 변경
			binaryA[idx1] = binaryA[i];
			idx1++;
		}

		for (int i = 0; i < idx2; i++) { //앞에 0으로 채워넣기
			binaryA[i] = '0';
		}

	}
	else if (a > b) {
		length = a;
		int idx1 = a - b; 
		int idx2 = idx1;  

		for (int i = 0; i < a; i++) { 
			binaryB[idx1] = binaryB[i];
			idx1++;
		}

		for (int i = 0; i < idx2; i++) { 
			binaryB[i] = '0';
		}
	}
	else { //a==b 길이가 같을 경우
		length = a; //둘 중 아무거나 대입
	}

	
	//(3)해밍 거리 구하기 -> for문 돌려서 요소 같고 다름 비교 

	for (int i = 0; i < length; i++){
		if (binaryA[i] == binaryB[i])
			hamming++;
	}
	return hamming;

}

int main() {

	char a[10]; 
	char b[10];

	cout << "2진수 문자열을 입력: "; 
	cin >> a;
	cout << "2진수 문자열을 입력: ";
	cin >> b;

	int hamming = solution(a, b);
	printf("두 2진수 문자열의 해밍거리는 %d입니다.", hamming);
	


}