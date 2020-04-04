/*
"123+12" = 135�� ���

-> atoi(���ڿ� �迭 Ȥ�� string ����) �Լ� �� �� �ƴ��� 

atoi(s), atoi(arr)

*/

#include <iostream>
#include <string>
using namespace std;

int solution(char expression[]) {
	
	//(1) �������� ��ġ�� ã��

	int idx = 0; //�����ڰ� �ִ� ��ġ
	char oper = ' '; //������ ������ ����

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

	//(2) �������� �հ� �ڿ� �ִ� ���ڿ� -> ���ڷ� ��ȯ

	char a[7]; char b[7];
	int num1 = 0 ; int num2 = 0; //���ڿ����� ��ȯ�� ���ڸ� ���� ���� 2��

	//ù��° ��
	for (int i = 0; i < idx; i++) {  
		a[i] = expression[i];
	}

	num1 = atoi(a); //���ڷ� ��ȯ
	
	//�ι�° �� 
	int i = idx + 1;

	for (int j = 0; j < strlen(b); j++) {
		if (i == strlen(expression))
			break;
		b[j] = expression[i];
		i++;
	}

	num2 = atoi(b); //���ڷ� ��ȯ


	//(3) ���� ����
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

	return result; //��ȯ

}


int main() {
	char expression[14]; //1~100,000 �Է� ����
	cin >> expression;

	int result = solution(expression);
	printf("%d\n", result);

}

