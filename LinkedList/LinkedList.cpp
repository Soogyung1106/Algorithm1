/* ������ ������ ���߿��Ḯ��Ʈ ����
*/
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node * next;
}Node;

Node * getNode(); //��� �Ҵ��Լ�
void insertNode(Node ** head, int data); //������ ó�� �Ǵ� �� ����   
//Node * seletedeleteNode(Node ** head, int data); //������ ���� ���� -> ������ �˻� �Լ� ���
//void addNode(Node **head, int data, int adddata); //������ �߰� ���� -> ������ �˻� �Լ� ���
//Node * getSearchNode(Node **head, int data); //������ �˻�
//void print(Node **head); //������ ��ü ���
//void AllDeleteNode(Node **head); //������ ��ü ����

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
	tmp�� �뵵 �� �����ϱ�!
	*/

	//(1) ��带 ó������ �߰��� ���
	if (head) { //head==NULL �� ���
		*head = getNode();
		(*head)->data = data; //(����) ���� �������̱� ������ *(* ).data = (* )->data
	}
	//(2) ��� �� ��°���� �߰��� ���	   -> tmp�� link�ʵ尡 NULL�̳� �ƴϳ� �����غ���!!
	else {

		//a. ����� �� �ڿ� ���Խ� 
		Node * tmp = NULL;
		if ((*head)->next)  //head�� null�� �ƴϸ鼭�� ����� ��ũ�ʵ尡 null�� ���
			tmp = *head; //tmp�� ��ġ ����	

		else //��� �� ��°���� 
			tmp = tmp->next;  //tmp�� ��ġ ����   *tmp.next : tmp�� �����ϰ� �ִ� �� �� next�κ�(���� + ���) 

		tmp->next = getNode(); //��� ������ ���ÿ� ����  (*tmp).next  = getnode()
		(tmp->next)->data = data; //������ �ޱ�


		//b. ����� �� �տ� ���Խ�
		//if(tmp->next) //NULL �� ��� : �� ���̶�� ��


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