/*�����Ҵ�� ������ ����ϴ� ��� */
#include <iostream>
#include <algorithm>  //C++�� sort() �����Լ� ��� ����
#include <stdlib.h> //malloc() �Լ� ��� ����

using namespace std;

int* solution(int arrA[], int arrB[], int sizeA, int sizeB) {  //�Ű������� �����Ͱ� �ƴ� arrA[], arrB[] ��

	/*
	�Ű������� �־����� �迭�� ���̰� ����  -> malloc����϶�� �ǹ�

	��������? or ������ ����? -> ��������? -> C++�� �Լ� ����!

	sort�Լ� ����: (0����, 7����) -> �ε��� ����

	*/
	int sizeC = sizeA + sizeB;

	int* pArrC = (int*)malloc(sizeof(int) *sizeC); //������(��������)�� ���ο� �迭 ������ �Ҵ��ϱ� ���� 
	
	//��ġ��
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


	sort(pArrC, pArrC + sizeC); //������������ ����

	return pArrC;

}

int main() {

	int arrA[] = { -2, 3, 5, 9 };
	int arrB[] = { 0, 1, 5 };

	//�迭�� ���� ����
	int sizeA = sizeof(arrA) / sizeof(int);
	int sizeB = sizeof(arrB) / sizeof(int);

	int* p = solution(arrA, arrB, sizeA, sizeB); //�迭�� ���� �Ѱ��ֱ� 

	//���
	for (int i = 0; i < 7; i++) {
		cout << p[i] << " ";
	}

	cout << endl;

}}