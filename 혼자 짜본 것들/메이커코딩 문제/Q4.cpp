#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using namespace std;

int solution(int num) {

	//�ڿ��� num�� 1�� ���� ���� ����

	/*
	�ϴ� 999�� �Է��ϸ�..
	���ڷ� �޾ƿ��� 
	1���ؼ� ����ϰ� -> 1000
	���ڿ��� �����ؼ�      ??���ڸ� ���ڷ�??
	1011 ->  
	*/

	int result = num + 1; //�ϴ� 1���ؼ� ���
	char arr[20]; //1���ؼ� ���� �� �ִ� ���� �ִ� 19�ڸ� �� �̹Ƿ�
	_itoa_s(result, arr, 10); //���ڿ��� arr�迭�� 10������ ����

	for (int i = 0; i <20; i++) {
		
		if (arr[i] == '\0')
			break;

		if (arr[i] == '0') { //0�̸� 1�� �ٲٱ�
			arr[i] = '1';
			
		}
	}

	
	result = atoi(arr); //���ڿ��� ������ ��ȯ


	return result; //��ȯ


	/*
	���ڸ� ���ڿ��� �ٲٴ� �Լ� 
	itoa() 

	���ڸ� �������ڷ� �ٲٴ� �Լ� atoi()

	*/
	
}


int main() {

	
	int num;
	cin >> num;  //0�� �������� �ʴ� num�Է�

	int result = solution(num);

	printf("result => %d", result);

}