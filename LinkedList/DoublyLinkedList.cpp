/*이중 연결리스트 구현 
참고한 영상 : 유튜브 Gunny's Algorithm Together
https://www.youtube.com/watch?v=iSdEHxVJ5vk
*/
#include <stdio.h>
#include <stdlib.h> //?
//#include<malloc.h>

struct NODE { //이중연결리스트의 노드 구조
	int data; //데이터 
	struct NODE* Llink; //Left link로 이전 노드를 가리킨다.
	struct NODE* Rlink; //Right link로 다음 노드를 가리킨다.
};

/* (생각1)구현해야 할 함수
노드 생성, 찾기, 중간에 추가, 삭제, 출력
(생각2) 사용되는 중요 변수들
head, tail, horse, temp, remove, cur
*/

//addNode와 insertAfter의 차이? 이어붙이는 것과 중간에 삽입하는 것
NODE* createNode(int); //노드 생성
void addNode(NODE**, NODE*); //앞서 생성한 노드 뒤에 차곡차곡 추가 (2가지 경우)  
void insertAfter(NODE*, NODE*); //노드 중간에 삽입(3가지 경우) 

NODE* getNodeAt(NODE*, int);//원하는 인덱스의 노드를 가져오게 하는 함수 -> 활용 : 삭제 혹은 삽입 시
int  countNode(NODE*); //리스트의 길이 

//deleteNode와 removeNode의 차이 주목
void deleteNode(NODE*); //heap 메모리 영역에서 동적할당 해제 -> 활용 : removeNode함수 안에서 호출됨 
void removeNode(NODE**, NODE*); // 노드 연결 끊은 후 동적할당 해제
/*
??이중 포인터를 사용하는 이유 : head에 변화가 일어나야 하기 때문에? 
??그럼 그냥 포인터 쓰면 변화가 안 일어남?? 그건 아닌뎅..
*/

int main() {
	
	int i = 0;
	int count = 0; //노드의 길이

	NODE* list = NULL; //생성될 리스트를 가리키는 포인터 
	NODE* newNode = NULL; //새로운 노드를 가리키는 포인터
	NODE* curr = NULL; //현재 노드

	for (i = 0; i < 5; i++) {
		newNode = createNode(i); // 노드 생성하기
		addNode(&list, newNode); // 생성한 노드를 이어붙이기 
								//(문법 공부)함수 호출시 매개변수의 이중포인터 부분은 &로 표시!    
	}

	//현재 데이터 출력
	count = countNode(list); // 노드의 길이 
	for (i = 0; i < count; i++) {
		curr = getNodeAt(list, i);
		printf("list[%d] = %d\n", i, curr->data); 
	}

	printf("--------5개의 노드가 생성되었습니다.------------\n");

	newNode = createNode(99); //newNode : 99의 데이터를 가진 노드를 생성하기 
	curr = getNodeAt(list, 0); //curr 기능 : 인덱스0번째의 노드를 가져오기
	insertAfter(curr, newNode); //0번째 노드인 curr다음에 

	newNode = createNode(444);
	curr = getNodeAt(list, 4);
	insertAfter(curr, newNode);
	printf("진행1\n");

	//현재 데이터 출력
	count = countNode(list);
	for (i = 0; i < count; i++) {
		curr = getNodeAt(list, i);
		printf("list[%d] = %d\n", i, curr->data); 
	}
	printf("진행2\n");

	printf("---------2개의 노드가 삽입되었습니다.------------\n");

	newNode = getNodeAt(list, 1);
	removeNode(&list, newNode); //1번째 요소 삭제
	
	newNode = getNodeAt(list, 0);
	removeNode(&list, newNode); //0번째 요소 삭제
	
	printf("진행2\n");
	//현재 데이터 출력
	count = countNode(list);
	for (i = 0; i < count; i++) {
		curr = getNodeAt(list, i);
		printf("list[%d] = %d\n", i, curr->data); //현재 데이터 출력
	}

	printf("------2개의 노드가 삭제되었습니다.---------\n");


	return 0;
}


NODE * createNode(int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	//변수 초기화
	newNode->data = data;
	newNode->Llink = NULL;
	newNode->Rlink = NULL;
	
	return newNode;	
}


void deleteNode(NODE * Node)
{
	free(Node); //메모리상에서 없애주는 역할만 해줌?
	
	/*(참고)
	??노드 삭제는 실질적으로 삭제하는 것이 아니라
	메모리상에서만 '의미없게' 만드는 것??
	*/
}

void removeNode(NODE** head, NODE* remove)
{
	/*3가지 경우 : remove될 노드가
	(1) head일 경우
	중간에 위치할 경우		?? 왜 이렇게 사고해야 하는거??
		(2) 그 뒤에 노드가 있을 경우
		(3) 그 앞에 노드가 있을 경우
	*/

	if (*head == remove)//(1)
		*head = remove->Rlink; //의미 : head를 날려버리면 안 되기 때문에 remove다음에 있는 것으로 연결 시킨 후 삭제
	
	if(remove->Rlink != NULL) //(2) remove할 노드 뒤에 노드가 있을 경우
		remove->Rlink->Llink = remove->Llink; //의미 : remove될 노드의 양 쪽의 노드를 서로 연결시켜주기
	
	if (remove->Llink != NULL)//(3) remove할 노드 앞에 노드가 있을 경우
		remove->Llink->Rlink = remove->Rlink; //의미 : (2)과 동일

	deleteNode(remove); //연결을 끊어버림으로써 방향 감각이 사라진 remove노드를 heap메모리에서 해제시키면서 완전히 삭제하기

}

NODE * getNodeAt(NODE * head, int index)
{
	NODE* horse = head; //기능 : 검색을 위해 리스트를 순회하는 변수, '말'
	int count = 0; //기능 : for문을 사용 안 하고 검색하고 있는 인덱스 증가 

	while (horse != NULL) {//horse : 널이 아닐때까지 달려라 -> 즉 리스트의 끝에 도달하면 while문을 빠져나가게 됨
		if (count++ == index) //index : 찾고자 하는 인덱스
			return horse;
		horse = horse->Rlink; //(문법 공부) horse = (*horse).Rlink;
	}
	 
	return NULL;
}

int countNode(NODE *head)
{
	int count = 0;
	NODE* horse = head; 

	while (horse != NULL) { //horse : 널이 아니면 달리게 하기
		horse = horse->Rlink;
		count++;
	}

	return count; //널이면 count 리턴
}

void addNode(NODE ** head, NODE *newNode) //(생각)?여기는 왜 이중포인터를 매개변수로 넣어주나??
{
	/*(생각)노드 추가시 두 가지 상황 존재
	(1) 리스트에 아무것도 없는 경우
	(2) 리스트에 노드가 존재할 때 -> 맨 뒤에 추가
	*/

	//(1) 경우
	if ((*head) == NULL)
		*head = newNode;
	//(2) 경우
	else {
		NODE* horse = (*head);

		while (horse->Rlink != NULL)
			horse = horse->Rlink;
		
		horse->Rlink = newNode;
		newNode->Llink = horse;

	}
}
/*? addNode()와 insertAfter()의 차이?

*/

void insertAfter(NODE* current, NODE* newNode)
{

	/*(생각)삽입할 경우 두 가지 경우
	(1) head로 낄건지(리스트에 아무것도 없을 경우)
	(2) tail로 낄건지
	(3) middle로 낄건지
	*/
	
	//(1)
	if (current->Rlink == NULL && current->Llink == NULL){
		current->Rlink = newNode; 
		newNode->Llink = current;
	}
	//(2) current가 맨 뒤일 경우
	if (current->Rlink == NULL) {
		current->Rlink = newNode;
		newNode->Llink = current;
	}
	else { //(3) 중간에 있는 current 뒤에 newNode 삽입

		/*해야 할 작업
		 : 삽입할 자리에 기존 link를 끊고 newNode와 연결
		*/
		current->Rlink->Llink = newNode; 
		newNode->Llink = current;
		newNode->Rlink = current;
		current->Rlink = newNode;
		//(생각)current와 newNode 모두 포인터 변수다!
	}


}
