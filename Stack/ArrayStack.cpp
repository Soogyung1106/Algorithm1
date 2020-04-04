//1���� �迭�� ���� ���� (������ ���� �κ� �����Ǿ� ����)
//-> ������ �����Ѵٰ� �ص� �����ϰ� ��� ���� ���� �ָ��� 0?? �װ͵� �������̴�.

#include<stdio.h>
#include<malloc.h> //malloc() free()
#define SIZE 5

void push(int * stack, int * top, int data);//������ �Է� �Լ�
void pop(int * stack, int * top);//������ ���� �Լ�
void peek(int * stack, int * top);

int main(void)
{
	int * stack = (int *)malloc(sizeof(int)*SIZE); //stack ������ ���� : heap������ �޸� ���� �Ҵ��� �� ������ ������ 
	int top = 0;

	//1. push()�� ������ �Է�
	push(stack, &top, 10); //�����Ҵ� ������ ����, top�� �ּ�, ������ ������ ��
	push(stack, &top, 20);
	push(stack, &top, 30);
	push(stack, &top, 40);
	push(stack, &top, 50);
	push(stack, &top, 60); //�� ����־��� -> stack overflow�̱� ������ 

	//2. top�� ��ġ �ľ�
	peek(stack, &top);

	//3. ������ ����
	pop(stack, &top); // top�� ��ġ ������ ������ ����
	pop(stack, &top);
	pop(stack, &top);
	pop(stack, &top);
	pop(stack, &top);
	pop(stack, &top); //�� �̻� �޸� �������� ������ �� ���� ������  stack underflow 

	//2. top�� ��ġ �ľ�
	peek(stack, &top);

	return 0;
}

void push(int * stack, int * top, int data) //(����Ʈ) 2��° �Ű������� 'top�� �ּ�'�� ���޵�
{
	/*int top���� �Ű������� �־����� ���� ����?
	->call by value�� ������, �Լ��� ����Ǿ��� �� main�� ���� ���� x��

	� ������ ���������� �����ؼ� �����͸� �ٲ���� �ϴ� ��� -> call by reference *���
	*/

	if (*top == SIZE) //���࿡ �����Ҵ��� �޸� ���� �ʰ��� stack overflow
	{
		printf("stack overflow!!!\n");  //(������ �帧)�� ������ �ִ������� ����
		return;
	}
	stack[*top] = data;
	(*top)++; //������ ���������Ƿ� top�� ��ġ �ϳ� ����
}

void pop(int * stack, int * top)
{
	if (*top == 0)  //������ �Լ����� �ڵ� ����� �ַ� ���ʿ� �ۼ��Ѵ�.
	{
		printf("stack underflow!!!\n");
		return;
	}
	(*top)--;
	printf("%d ����\n", stack[*top]);
}

void peek(int * stack, int * top)
{
	if (*top == 0) //top�� ��ġ �� ó�� ������ �Է��ϱ� ��ó�� ��ġ 0�� ���
	{
		printf("no data!!!\n");
		return;
	}
	printf("���� top ��ġ�� data : %d\n", stack[*top - 1]);
}