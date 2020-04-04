/*
개념 : 구조체 포인터 + 이중포인터 + 동적할당
*/
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node * link; // 현재 구조체와 같은 형태 공간의 주소를 저장하는 포인터 영역

}node, Stack; //??무엇??

Stack * getNode(); //노드생성함수
void push(Stack **top, int data); // 데이터 입력 함수
void pop(Stack **top); //데이터 삭제 함수
void peek(Stack **top);//데이터 출력함수 가장위에 데이터만
void Allpeek(Stack **top); //전체 데이터 출력

int main(void){

	Stack * top = NULL; // top의 위치 초기화

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

//노드 생성함수
Stack * getNode() 
{
	Stack * tmp = (Stack *)malloc(sizeof(Stack)); //동적할당
	tmp->link = NULL; //링크 부분 초기화
	return tmp;
}

// 데이터 입력 함수
void push(Stack **top, int data)
{	
	//(1) (생각)getNode()를 통해 받아올 포인터 구조체를 받아올 같은 자료형의 변수 선언!!!
	Stack* tmp = NULL; //초기화

	//(2)노드 생성함수를 통해 동적할당된 주소를 갖고있는 구조체 포인터 tmp 갖고오기
	tmp =getNode(); // 동적할당된 공간을 포인팅하고 있는 화살표를 tmp로 옮겨놓기
	//(생각) 이제는 tmp가 heap영역의 동적할당된 공간을 가리키고 있음

	//(3)매개변수를 통해 받아온 데이터 입력
	tmp->data = data;

	//(4) 노드 연결 // 새로 추가한 노드를 그 전 노드의 주소와 연결
	tmp->link =*top; //(생각)그 전에 노드의 주소를 저장해 놓은 top을 새로 추가한 노드의 주소에 줌으로써 연결

	//(5) top의 위치 변경 : 새로 추가한 노드의 주소(tmp에 저장되어 있음)를 top의 link 부분에 저장
	*top = tmp;  //(포인트) 이중포인터의 구조체 참조 방법
	
	

}

//데이터 삭제 함수
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

//데이터 출력함수 가장위에 데이터만
void peek(Stack **top)     
{
	printf("가장 최근의 데이터는 %d 입니다.\n", (*top)->data);//(포인트) (*top).data와 다르다! 이중포인터이기 때문에!
	return;
}

//전체 데이터 출력
void Allpeek(Stack **top)
{
	if ((*top) == NULL)
	{
		printf("DATA출력완료\n");
		return;
	}

	printf("%d -> ", (*top)->data);
	Allpeek(&(*top)->link);
}


/*스택 필기

**포인트**

- 함수이름 정해져 있음 -> push() 입력, pop() 삭제
- LIFO

- top은 항상 가장 나중에 들어온 데이터를 포인팅하게끔 설정 -> top을 통해서 삭제


(스택의 표현 방법)
=> 1차원 배열 표현 : 원래 스택의 의미에 더 가까움
=> 연결 리스트로 표현 : 스택의 최대 크기를 알 수 없을때??

(스택의 용도)
=> 인터넷에서 뒤로 가기 앞으로 가기


-> stack overflow 주어지 스택 저장공간 용량 초과시 발생하는 에러
//재귀함수 무한정으로 실행할 경우 발생


* 재귀함수 : 함수 안에서 자기 자신을 호출



*/