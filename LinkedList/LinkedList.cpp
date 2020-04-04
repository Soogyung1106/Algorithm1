/* 전광일 교수님 이중연결리스트 구현
*/
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node * next;
}Node;

Node * getNode(); //노드 할당함수
void insertNode(Node ** head, int data); //데이터 처음 또는 끝 삽입   
//Node * seletedeleteNode(Node ** head, int data); //데이터 선택 삭제 -> 데이터 검색 함수 사용
//void addNode(Node **head, int data, int adddata); //데이터 중간 삽입 -> 데이터 검색 함수 사용
//Node * getSearchNode(Node **head, int data); //데이터 검색
//void print(Node **head); //데이터 전체 출력
//void AllDeleteNode(Node **head); //데이터 전체 삭제

int main(void)
{
	Node * head = NULL;

	insertNode(&head, 10);
	insertNode(&head, 20);
	insertNode(&head, 30);
	//print(&head);
	/*addNode(&head, 10, 15);
	addNode(&head, 20, 25);
	addNode(&head, 40, 25);
	seletedeleteNode(&head, 20);
	print(&head);
	seletedeleteNode(&head, 25);
	AllDeleteNode(&head);*/
	return 0;
}

Node * getNode()
{
	Node * tmp = (Node *)malloc(sizeof(Node));
	tmp->next = NULL;
	return tmp;
}
void insertNode(Node ** head, int data)
{
	/*
	tmp의 용도 잘 이해하기!
	*/

	//(1) 노드를 처음으로 추가할 경우
	if (head) { //head==NULL 인 경우
		*head = getNode();
		(*head)->data = data; //(주의) 이중 포인터이기 때문에 *(* ).data = (* )->data
	}
	//(2) 노드 두 번째부터 추가할 경우	   -> tmp의 link필드가 NULL이냐 아니냐 생각해봐야!!
	else {

		//a. 노드의 맨 뒤에 삽입시 
		Node * tmp = NULL;
		if ((*head)->next)  //head는 null이 아니면서도 노드의 링크필드가 null인 경우
			tmp = *head; //tmp의 위치 변경	

		else //노드 세 번째부터 
			tmp = tmp->next;  //tmp의 위치 변경   *tmp.next : tmp가 참조하고 있는 값 중 next부분(간접 + 멤버) 

		tmp->next = getNode(); //노드 생성과 동시에 연결  (*tmp).next  = getnode()
		(tmp->next)->data = data; //데이터 받기


		//b. 노드의 맨 앞에 삽입시
		//if(tmp->next) //NULL 인 경우 : 맨 끝이라는 뜻


	}





}
Node * seletedeleteNode(Node ** head, int data)
{

}
void addNode(Node **head, int data, int adddata)
{

}
Node * getSearchNode(Node **head, int data)
{

}
void print(Node **head)
{

}
void AllDeleteNode(Node **head)
{

}