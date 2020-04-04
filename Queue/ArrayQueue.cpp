#include<stdio.h>
#include<malloc.h>

#define SIZE 5

void enqueue(int * queue, int * front, int *rear, int data); //»ðÀÔ
void dequeue(int * queue, int * front, int *rear); //»èÁ¦

int main(void)
{
	int * queue = (int *)malloc(sizeof(int)*SIZE);
	int front = 0, rear = 0;

	dequeue(queue, &front, &rear);
	enqueue(queue, &front, &rear, 10);
	enqueue(queue, &front, &rear, 20);
	enqueue(queue, &front, &rear, 30);
	dequeue(queue, &front, &rear);
	dequeue(queue, &front, &rear);
	dequeue(queue, &front, &rear);
	enqueue(queue, &front, &rear, 40);
	enqueue(queue, &front, &rear, 50);
	enqueue(queue, &front, &rear, 60);


	return 0;
}

void enqueue(int * queue, int * front, int *rear, int data)
{
	if (*rear == SIZE)
	{
		printf("full data!!!\n");
		return;
	}
	queue[*rear] = data;
	(*rear)++;
	printf("data : %d\t rear : %d\t front : %d\n", queue[*rear - 1], *rear, *front);
}
void dequeue(int * queue, int * front, int *rear)
{
	if (*rear == 0)
	{
		printf("no data!!!\n");
		return;
	}
	(*front)++;
	printf("deldata : %d\t rear : %d\t front : %d\n", queue[*front - 1], *rear, *front);
	if (*front == *rear)
	{
		printf("no data!!!Queue reset!!\n");
		*front = 0;
		*rear = 0;
	}
}