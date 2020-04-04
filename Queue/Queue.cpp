#include<stdio.h>
#include<malloc.h>

//����ü ����
struct node
{
	int data;
	struct node * link;
};
typedef struct node Queue;

Queue * getNode();//��� ����
void enqueue(Queue **front, Queue **rear, int data);  //������ �Է�
void dequeue(Queue **front, Queue **rear);//������ ����
void peek(Queue **front); //���� �����ɵ�����
void Allpeek(Queue **front); //��ü ������ ���

int main(void)
{
	Queue *front = NULL, *rear = NULL;

	enqueue(&front, &rear, 10);
	enqueue(&front, &rear, 20);
	enqueue(&front, &rear, 30);
	enqueue(&front, &rear, 40);
	Allpeek(&front);
	peek(&front);

	dequeue(&front, &rear); //10����
	peek(&front);
	dequeue(&front, &rear); //20����
	peek(&front);
	dequeue(&front, &rear); //30����
	peek(&front);
	dequeue(&front, &rear); //40����
	peek(&front); //No Data
	dequeue(&front, &rear); //No Data -> ����ó�� �κ�
	peek(&front); //No Data -> ����ó�� �κ�
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
	//(1) tmp ����
	Queue* tmp = getNode();
	//(2) tmp�� ���� ������ ����ֱ�
	tmp->data = data;

	//(!*front)
	//(ó������ ��带 �߰��� ���)
	if (*front == NULL) //front�� �� �� ����Ű���� ���� 
		*front = tmp; //front ����

	//(�� ���Ŀ� ��带 �߰��� ���)
	else
		(*rear)->link = tmp; //(3)��� ���� : ���� �߰��� ��带 �� �� ����� �ּҿ� ����
							//(����) ����� ���ǻ��� : ���ð� ������� �ٸ�!	
	*rear = tmp; //(4)rear�� ��ġ �ֱٿ� ���� ���� ����


	/* POINT
	(*rear)->link = tmp; *rear = tmp;  //��???

	-> ���� �����ڴ� �������� ��������!
	*rear = tmp = (*rear)->link = tmp;

	*/

}

void dequeue(Queue **front, Queue **rear)
{

	//�����غ��� �ϴ� ��� : data�� ���� ��, 1�� ���� ��, 2�� �̻��� ��
	Queue* tmp = *front; //��� ������ ���� �ӽ� �����ͺ��� tmp

	if (*front == NULL) {			//a. ��尡 ���� �� -> �Լ� ����     //!*front = *front == NULL ���� ǥ��

		printf("No Data!!!\n");
		return; //dequeue�Լ� ����

	}
	else if (tmp->link == NULL) { //b. ��尡 1�� ���� ��      else if (!(*front)->link) ���� ǥ��

		*front = NULL;
		*rear = *front; //���� �� �ϱ� ���� ó���ؾ� �� �� : rear�� front�� ó�� ��ġ��!
	}
	else if ((*front)->link)							//c. ��尡 2�� �̻��� �� 
		*front = (*front)->link; //���� ���� �����Ű��

	free(tmp); //�� ������ �ִ� �޸� ������ ����Ű�� �ִ� tmp �ּ� �����������ν� ���� ������

}

void peek(Queue **front)
{
	if (*front == NULL)
	{
		printf("No Data!!!\n");
		return;
	}
	printf("������ ������ : %d\n", (*front)->data);
}

void Allpeek(Queue **front)
{
	if (*front == NULL)
	{
		printf("DATA ��¿Ϸ� \n");
		return;
	}
	else
	{
		printf("%d -> ", (*front)->data);
		Allpeek(&(*front)->link);
	}
}