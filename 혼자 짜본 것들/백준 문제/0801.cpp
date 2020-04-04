/*
<���� 1181�� ����>
input: ���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ� 
(��, 1<=N<=20,000)
output:
���� 
1. ���̰� ª�� �ͺ���
2. ���̰� ������ ���������� 
(��, ���� �ܾ �ߺ��� -> �� ���� ���)
*/
#define _CRT_SECURE_NO_WARNINGS  //scanf_s ���x
#include <stdio.h>
#include <stdlib.h> //malloc()�Լ� 
#include <string.h> //strlen(), strcmp(), strcpy()�Լ� 

int main() {

	int n; //����ڰ� �Է��� �ܾ��� ����
	char tmp[50]; //�ܾ��� ���� ���� �� ���� �ӽ� �迭
	int min; //���������� ���Ľ� �ʿ�

	
	//(1) �� ���� �ܾ �Է����� ����
	printf("�ܾ� N�� �Է�: ");
	scanf("%d", &n);

	//���� 20¥���� char�� N���� 2���� �迭 �����Ҵ� 
	char **arr = (char**)malloc(sizeof(char*)*n); //�ܾ� n��(�迭 n��)�� �����ϱ� ���� ������ n�� 

	for (int i = 0; i < n; i++) {
		arr[i] = (char*)malloc(sizeof(char) * 50);//(����: �־��� ���ڿ��� ���̴� 50�� ���� �ʴ´�.)
	}

	//(2) n���� �ܾ� �Է� ����
	for (int i = 0; i < n;i++) {
		scanf("%s", arr[i]); //arr[i]�� �� ���� �ּҰ� ����� ���� 
	}


	//(3)���̺��� ���������� �켱 ����
	//(����2: ���̰� ������ ���������� )

	for (int i = 0; i < n - 1; i++) {
		
		min = i;  //min�� ������ i��° ��ġ�� ����

		for (int k = i + 1; k < n; k++) {  //�ε��� 0�� 1,2,3,4,...���ؼ� ������ 0�� ��ġ ã�� / �ε��� 1�� 2,3,4,5...���ؼ� ������ 1�� ��ġ ã�� 

			if (strcmp(arr[min], arr[k]) > 0) //arr[k]�� arr[min] ���� ���������� �տ� �� ���
				min = k; //�ε��� k�� ����
		}
		
		//������ i�� ��ġ�� �ִ� �ܾ i�� ��ġ�� �ֵ��� �ڸ� �ٲ��ֱ�
		strcpy(tmp, arr[i]);
		strcpy(arr[i], arr[min]);
		strcpy(arr[min], tmp);
			
	}

	//(4) ���̼����� ����
	//(����1: ���̰� ª�� �ͺ���)
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {

			//���� ��
			if (strlen(arr[j]) > strlen(arr[j + 1])) { //�� �ܾ �� �ܾ�� �� �ܾ��� ���

				//�� ª�� �ܾ �տ� ��ġ�ϵ��� ���ġ
				strcpy(tmp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], tmp);

			}
		}
	}


	//(5) ���
	printf("\n");

	for (int i = 0; i < n; i++) {

		//(����: ���� �ܾ ���� �� �Էµ� ��� �� ������ ���)
		if (i != n - 1) { 

			if (strcmp(arr[i], arr[i + 1]) == 0) { //�� �ܾ ������ �ܾ��� ���
				//���� �ε����� ��ŵ
			}
			else {
				printf("%s\n", arr[i]); //���
			}
		} 
		else { //i = n-1 �� ���
			printf("%s\n", arr[i]); //���
		}

	}

	//(6) �����Ҵ� ����
	free(arr);// <����> �����������̹Ƿ� arr[0], arr[1], arr[2]..������ ���� �ʿ�x

	return 0;
}
