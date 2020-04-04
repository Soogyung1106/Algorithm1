/*동적할당된 변수를 사용하는 방법 */
#include <iostream>
#include <algorithm>  //C++의 sort() 정렬함수 사용 목적
#include <stdlib.h> //malloc() 함수 사용 목적

using namespace std;

int* solution(int arrA[], int arrB[], int sizeA, int sizeB) {  //매개변수로 포인터가 아닌 arrA[], arrB[] 줌

	/*
	매개변수로 주어지는 배열의 길이가 가변  -> malloc사용하라는 의미

	삽입정렬? or 삽입후 정렬? -> 직접구현? -> C++은 함수 있지!

	sort함수 사용법: (0부터, 7까지) -> 인덱스 기준

	*/
	int sizeC = sizeA + sizeB;

	int* pArrC = (int*)malloc(sizeof(int) *sizeC); //힙영역(동적영역)에 새로운 배열 공간을 할당하기 위한 
	
	//합치기
	for (int i = 0; i < sizeA; i++) {
		*(pArrC+i) = arrA[i];
	}


	int j = 0;
	for (int i = 4; i < sizeA + sizeB; i++) {

		if (j == sizeB)
			break;
		else {
			*(pArrC+i) = arrB[j];
			j++;
		}

	}


	sort(pArrC, pArrC + sizeC); //오름차순으로 정렬

	return pArrC;

}

int main() {

	int arrA[] = { -2, 3, 5, 9 };
	int arrB[] = { 0, 1, 5 };

	//배열의 길이 저장
	int sizeA = sizeof(arrA) / sizeof(int);
	int sizeB = sizeof(arrB) / sizeof(int);

	int* p = solution(arrA, arrB, sizeA, sizeB); //배열의 길이 넘겨주기 

	//출력
	for (int i = 0; i < 7; i++) {
		cout << p[i] << " ";
	}

	cout << endl;

}}