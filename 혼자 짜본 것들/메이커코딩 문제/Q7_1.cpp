/*static 변수를 사용하는 방법 */

#include <iostream>
#include <algorithm>  //sort() 정렬함수 사용 목적
#include <stdlib.h> //malloc() 함수 사용 목적

using namespace std;

int* solution(int arrA[], int arrB[], int sizeA, int sizeB) {  //매개변수로 포인터가 아닌 arrA[], arrB[] 줌

	/*
	매개변수로 주어지는 배열의 길이가 가변  -> malloc사용하라는 의미
	
	삽입정렬? or 삽입후 정렬? -> 직접구현? -> C++은 함수 있지!

	sort함수 사용법: (0부터, 7까지) -> 인덱스 기준

	*/
	int sizeC = sizeA + sizeB;

	static int arrC[7]; //합치기 위한 새로운 공간의 배열

	//합치기
	for (int i = 0; i < sizeA; i++) {
		arrC[i] = arrA[i];
	}


	int j = 0;
	for (int i = 4; i < sizeA+sizeB; i++) {

		if (j == sizeB)
			break;
		else {
			arrC[i] = arrB[j];
			j++;
		}

	}


	sort(arrC, arrC + sizeC); //오름차순으로 정렬

	return arrC;

}

int main() {

	int arrA[] = { -2, 3, 5, 9 };
	int arrB[] = {0, 1, 5};

	//배열의 길이 저장
	int sizeA = sizeof(arrA) / sizeof(int); 
	int sizeB = sizeof(arrB) / sizeof(int);

	int* p = solution(arrA, arrB, sizeA, sizeB); 

	//출력
	for (int i = 0; i < 7; i++) {
		cout << p[i] << " ";  
	}

	cout << endl;

}