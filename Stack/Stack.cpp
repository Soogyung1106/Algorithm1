/*
���� : ����ü ������ + ���������� + �����Ҵ�
*/
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node * link; // ���� ����ü�� ���� ���� ������ �ּҸ� �����ϴ� ������ ����

}node, Stack; //??����??

Stack * getNode(); //�������Լ�
void push(Stack **top, int data); // ������ �Է� �Լ�
void pop(Stack **top); //������ ���� �Լ�
void peek(Stack **top);//������ ����Լ� �������� �����͸�
void Allpeek(Stack **top); //��ü ������ ���

int main(void){

	Stack * top = NULL; // top�� ��ġ �ʱ�ȭ

	push(&top, 10);
	peek(&top);

	push(&top, 20);
	peek(&top);
	
	push(&top, 30);
	peek(&top);
	Allpeek(&top);

	
	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);
	
	return 0;
}

//��� �����Լ�
Stack * getNode() 
{
	Stack * tmp = (Stack *)malloc(sizeof(Stack)); //�����Ҵ�
	tmp->link = NULL; //��ũ �κ� �ʱ�ȭ
	return tmp;
}

// ������ �Է� �Լ�
void push(Stack **top, int data)
{	
	//(1) (����)getNode()�� ���� �޾ƿ� ������ ����ü�� �޾ƿ� ���� �ڷ����� ���� ����!!!
	Stack* tmp = NULL; //�ʱ�ȭ

	//(2)��� �����Լ��� ���� �����Ҵ�� �ּҸ� �����ִ� ����ü ������ tmp �������
	tmp =getNode(); // �����Ҵ�� ������ �������ϰ� �ִ� ȭ��ǥ�� tmp�� �Űܳ���
	//(����) ������ tmp�� heap������ �����Ҵ�� ������ ����Ű�� ����

	//(3)�Ű������� ���� �޾ƿ� ������ �Է�
	tmp->data = data;

	//(4) ��� ���� // ���� �߰��� ��带 �� �� ����� �ּҿ� ����
	tmp->link =*top; //(����)�� ���� ����� �ּҸ� ������ ���� top�� ���� �߰��� ����� �ּҿ� �����ν� ����

	//(5) top�� ��ġ ���� : ���� �߰��� ����� �ּ�(tmp�� ����Ǿ� ����)�� top�� link �κп� ����
	*top = tmp;  //(����Ʈ) ������������ ����ü ���� ���
	
	

}

//������ ���� �Լ�
void pop(Stack **top)
{	

	if (*top == NULL) {
		printf("Stack UnderFlow!!!\n");
		return;
	}
	Stack * tmp = *top;
	*top = (*top)->link;
	free(tmp);

}

//������ ����Լ� �������� �����͸�
void peek(Stack **top)     
{
	printf("���� �ֱ��� �����ʹ� %d �Դϴ�.\n", (*top)->data);//(����Ʈ) (*top).data�� �ٸ���! �����������̱� ������!
	return;
}

//��ü ������ ���
void Allpeek(Stack **top)
{
	if ((*top) == NULL)
	{
		printf("DATA��¿Ϸ�\n");
		return;
	}

	printf("%d -> ", (*top)->data);
	Allpeek(&(*top)->link);
}


/*���� �ʱ�

**����Ʈ**

- �Լ��̸� ������ ���� -> push() �Է�, pop() ����
- LIFO

- top�� �׻� ���� ���߿� ���� �����͸� �������ϰԲ� ���� -> top�� ���ؼ� ����


(������ ǥ�� ���)
=> 1���� �迭 ǥ�� : ���� ������ �ǹ̿� �� �����
=> ���� ����Ʈ�� ǥ�� : ������ �ִ� ũ�⸦ �� �� ������??

(������ �뵵)
=> ���ͳݿ��� �ڷ� ���� ������ ����


-> stack overflow �־��� ���� ������� �뷮 �ʰ��� �߻��ϴ� ����
//����Լ� ���������� ������ ��� �߻�


* ����Լ� : �Լ� �ȿ��� �ڱ� �ڽ��� ȣ��



*/