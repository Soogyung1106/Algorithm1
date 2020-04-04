//1차원 배열로 스택 구현 (데이터 삭제 부분 생략되어 있음)
//-> 데이터 삭제한다고 해도 삭제하고 대신 넣을 값도 애매함 0?? 그것도 데이터이다.

#include<stdio.h>
#include<malloc.h> //malloc() free()
#define SIZE 5

void push(int * stack, int * top, int data);//데이터 입력 함수
void pop(int * stack, int * top);//데이터 추출 함수
void peek(int * stack, int * top);

int main(void)
{
	int * stack = (int *)malloc(sizeof(int)*SIZE); //stack 포인터 변수 : heap영역에 메모리 동적 할당을 한 공간을 포인팅 
	int top = 0;

	//1. push()로 데이터 입력
	push(stack, &top, 10); //동적할당 포인팅 변수, top의 주소, 투입할 데이터 값
	push(stack, &top, 20);
	push(stack, &top, 30);
	push(stack, &top, 40);
	push(stack, &top, 50);
	push(stack, &top, 60); //안 집어넣어짐 -> stack overflow이기 때문에 

	//2. top의 위치 파악
	peek(stack, &top);

	//3. 데이터 추출
	pop(stack, &top); // top의 위치 가지고 데이터 추출
	pop(stack, &top);
	pop(stack, &top);
	pop(stack, &top);
	pop(stack, &top);
	pop(stack, &top); //더 이상 메모리 공간에서 추출할 것 없기 때문에  stack underflow 

	//2. top의 위치 파악
	peek(stack, &top);

	return 0;
}

void push(int * stack, int * top, int data) //(포인트) 2번째 매개변수에 'top의 주소'가 전달됨
{
	/*int top으로 매개변수를 넣어주지 않은 이유?
	->call by value의 문제점, 함수가 종료되었을 떄 main에 값이 변경 x됨

	어떤 공간에 직접적으로 접근해서 데이터를 바꿔줘야 하는 경우 -> call by reference *사용
	*/

	if (*top == SIZE) //만약에 동적할당한 메모리 공간 초과시 stack overflow
	{
		printf("stack overflow!!!\n");  //(생각의 흐름)들어갈 공간이 있는지부터 생각
		return;
	}
	stack[*top] = data;
	(*top)++; //데이터 저장했으므로 top의 위치 하나 증가
}

void pop(int * stack, int * top)
{
	if (*top == 0)  //정의한 함수에서 코드 제어문은 주로 위쪽에 작성한다.
	{
		printf("stack underflow!!!\n");
		return;
	}
	(*top)--;
	printf("%d 삭제\n", stack[*top]);
}

void peek(int * stack, int * top)
{
	if (*top == 0) //top의 위치 맨 처음 데이터 입력하기 전처럼 위치 0인 경우
	{
		printf("no data!!!\n");
		return;
	}
	printf("현재 top 위치의 data : %d\n", stack[*top - 1]);
}