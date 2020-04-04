#include<stdio.h>
#include<malloc.h>

//구조체 형성
struct node
{
	int data;
	struct node * link;
};
typedef struct node Queue;

Queue * getNode();//노드 생성
void enqueue(Queue **front, Queue **rear, int data);  //데이터 입력
void dequeue(Queue **front, Queue **rear);//데이터 삭제
void peek(Queue **front); //먼저 삭제될데이터
void Allpeek(Queue **front); //전체 데이터 출력

int main(void)
{
	Queue *front = NULL, *rear = NULL;

	enqueue(&front, &rear, 10);
	enqueue(&front, &rear, 20);
	enqueue(&front, &rear, 30);
	enqueue(&front, &rear, 40);
	Allpeek(&front);
	peek(&front);

	dequeue(&front, &rear); //10삭제
	peek(&front);
	dequeue(&front, &rear); //20삭제
	peek(&front);
	dequeue(&front, &rear); //30삭제
	peek(&front);
	dequeue(&front, &rear); //40삭제
	peek(&front); //No Data
	dequeue(&front, &rear); //No Data -> 예외처리 부분
	peek(&front); //No Data -> 예외처리 부분
	return 0;
}

Queue * getNode()
{
	Queue * node = (Queue *)malloc(sizeof(Queue));
	node->link = NULL;
	return node;
}

void enqueue(Queue **front, Queue **rear, int data)
{
	//(1) tmp 생성
	Queue* tmp = getNode();
	//(2) tmp를 통해 데이터 집어넣기
	tmp->data = data;

	//(!*front)
	//(처음으로 노드를 추가할 경우)
	if (*front == NULL) //front가 맨 앞 가리키도록 설정 
		*front = tmp; //front 설정

	//(그 이후에 노드를 추가할 경우)
	else
		(*rear)->link = tmp; //(3)노드 연결 : 새로 추가한 노드를 그 전 노드의 주소와 연결
							//(생각) 연결시 주의사항 : 스택과 연결방향 다름!	
	*rear = tmp; //(4)rear의 위치 최근에 들어온 노드로 변경


	/* POINT
	(*rear)->link = tmp; *rear = tmp;  //왜???

	-> 대입 연산자는 우측에서 좌측으로!
	*rear = tmp = (*rear)->link = tmp;

	*/

}

void dequeue(Queue **front, Queue **rear)
{

	//생각해봐야 하는 경우 : data가 없을 때, 1개 있을 때, 2개 이상일 때
	Queue* tmp = *front; //노드 삭제를 위한 임시 포인터변수 tmp

	if (*front == NULL) {			//a. 노드가 없을 때 -> 함수 종료     //!*front = *front == NULL 같은 표현

		printf("No Data!!!\n");
		return; //dequeue함수 종료

	}
	else if (tmp->link == NULL) { //b. 노드가 1개 있을 때      else if (!(*front)->link) 같은 표현

		*front = NULL;
		*rear = *front; //삭제 다 하기 전에 처리해야 할 것 : rear과 front를 처음 위치로!
	}
	else if ((*front)->link)							//c. 노드가 2개 이상일 때 
		*front = (*front)->link; //다음 노드로 연결시키기

	free(tmp); //힙 영역에 있는 메모리 공간을 가리키고 있는 tmp 주소 전달해줌으로써 공간 날리기

}

void peek(Queue **front)
{
	if (*front == NULL)
	{
		printf("No Data!!!\n");
		return;
	}
	printf("삭제될 데이터 : %d\n", (*front)->data);
}

void Allpeek(Queue **front)
{
	if (*front == NULL)
	{
		printf("DATA 출력완료 \n");
		return;
	}
	else
	{
		printf("%d -> ", (*front)->data);
		Allpeek(&(*front)->link);
	}
}