/*static ������ ����ϴ� ��� */

#include <iostream>
#include <algorithm>  //sort() �����Լ� ��� ����
#include <stdlib.h> //malloc() �Լ� ��� ����

using namespace std;

int* solution(int arrA[], int arrB[], int sizeA, int sizeB) {  //�Ű������� �����Ͱ� �ƴ� arrA[], arrB[] ��

	/*
	�Ű������� �־����� �迭�� ���̰� ����  -> malloc����϶�� �ǹ�
	
	��������? or ������ ����? -> ��������? -> C++�� �Լ� ����!

	sort�Լ� ����: (0����, 7����) -> �ε��� ����

	*/
	int sizeC = sizeA + sizeB;

	static int arrC[7]; //��ġ�� ���� ���ο� ������ �迭

	//��ġ��
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


	sort(arrC, arrC + sizeC); //������������ ����

	return arrC;

}

int main() {

	int arrA[] = { -2, 3, 5, 9 };
	int arrB[] = {0, 1, 5};

	//�迭�� ���� ����
	int sizeA = sizeof(arrA) / sizeof(int); 
	int sizeB = sizeof(arrB) / sizeof(int);

	int* p = solution(arrA, arrB, sizeA, sizeB); 

	//���
	for (int i = 0; i < 7; i++) {
		cout << p[i] << " ";  
	}

	cout << endl;

}