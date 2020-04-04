/*
�ع� �Ÿ� ���� 

-> �迭���� ���� �ٸ� ������ ����

for�� ������ ó������ ���鼭 ��Ұ� ������ ��


strlen�Լ� -> ���ڿ� �迭�� ��� 

*/


#include <iostream>
#include <string>

using namespace std;

int solution(char binaryA[], char binaryB[]) {
	
	//(1)���̰� �� �� 2���� ���ڿ��� ���̸� ���ϱ�
	
	int a = strlen(binaryA);
	int b = strlen(binaryB);
	
	int length = 0; //�� ���ڿ� �� �� �� ���ڿ��� ���̸� ����
	int hamming = 0; //�عְŸ�

	/*
	���� 2<5
	a�� ���̸� 5�� �����ֱ� 
	�տ������� ä��� 
	10010
	10  -> 0��° ��ġ�� (5-2)��° ��ġ�� �̵�
	*/
	
	//(2) ���̰� ª�� ������ �迭 �տ� 0���� ä���ֱ�
	
	if (a < b) {  
		length = b; 
		int idx1 = b - a; //ù ��° for������ ��� 
		int idx2 = idx1;  //�� ��° for������ ���
		
		/*
		...�� �������� ��� 0���� ä���ֱ�
		binaryA[idx] = binaryA[0];
		binaryA[idx+1] = binaryA[1];
		...
		*/

		for (int i = 0; i< a; i++) { //���� ��ġ ����
			binaryA[idx1] = binaryA[i];
			idx1++;
		}

		for (int i = 0; i < idx2; i++) { //�տ� 0���� ä���ֱ�
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
	else { //a==b ���̰� ���� ���
		length = a; //�� �� �ƹ��ų� ����
	}

	
	//(3)�ع� �Ÿ� ���ϱ� -> for�� ������ ��� ���� �ٸ� �� 

	for (int i = 0; i < length; i++){
		if (binaryA[i] == binaryB[i])
			hamming++;
	}
	return hamming;

}

int main() {

	char a[10]; 
	char b[10];

	cout << "2���� ���ڿ��� �Է�: "; 
	cin >> a;
	cout << "2���� ���ڿ��� �Է�: ";
	cin >> b;

	int hamming = solution(a, b);
	printf("�� 2���� ���ڿ��� �عְŸ��� %d�Դϴ�.", hamming);
	


}