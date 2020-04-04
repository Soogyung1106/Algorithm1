/*���� ���Ḯ��Ʈ ���� 
������ ���� : ��Ʃ�� Gunny's Algorithm Together
https://www.youtube.com/watch?v=iSdEHxVJ5vk
*/
#include <stdio.h>
#include <stdlib.h> //?
//#include<malloc.h>

struct NODE { //���߿��Ḯ��Ʈ�� ��� ����
	int data; //������ 
	struct NODE* Llink; //Left link�� ���� ��带 ����Ų��.
	struct NODE* Rlink; //Right link�� ���� ��带 ����Ų��.
};

/* (����1)�����ؾ� �� �Լ�
��� ����, ã��, �߰��� �߰�, ����, ���
(����2) ���Ǵ� �߿� ������
head, tail, horse, temp, remove, cur
*/

//addNode�� insertAfter�� ����? �̾���̴� �Ͱ� �߰��� �����ϴ� ��
NODE* createNode(int); //��� ����
void addNode(NODE**, NODE*); //�ռ� ������ ��� �ڿ� �������� �߰� (2���� ���)  
void insertAfter(NODE*, NODE*); //��� �߰��� ����(3���� ���) 

NODE* getNodeAt(NODE*, int);//���ϴ� �ε����� ��带 �������� �ϴ� �Լ� -> Ȱ�� : ���� Ȥ�� ���� ��
int  countNode(NODE*); //����Ʈ�� ���� 

//deleteNode�� removeNode�� ���� �ָ�
void deleteNode(NODE*); //heap �޸� �������� �����Ҵ� ���� -> Ȱ�� : removeNode�Լ� �ȿ��� ȣ��� 
void removeNode(NODE**, NODE*); // ��� ���� ���� �� �����Ҵ� ����
/*
??���� �����͸� ����ϴ� ���� : head�� ��ȭ�� �Ͼ�� �ϱ� ������? 
??�׷� �׳� ������ ���� ��ȭ�� �� �Ͼ?? �װ� �ƴѵ�..
*/

int main() {
	
	int i = 0;
	int count = 0; //����� ����

	NODE* list = NULL; //������ ����Ʈ�� ����Ű�� ������ 
	NODE* newNode = NULL; //���ο� ��带 ����Ű�� ������
	NODE* curr = NULL; //���� ���

	for (i = 0; i < 5; i++) {
		newNode = createNode(i); // ��� �����ϱ�
		addNode(&list, newNode); // ������ ��带 �̾���̱� 
								//(���� ����)�Լ� ȣ��� �Ű������� ���������� �κ��� &�� ǥ��!    
	}

	//���� ������ ���
	count = countNode(list); // ����� ���� 
	for (i = 0; i < count; i++) {
		curr = getNodeAt(list, i);
		printf("list[%d] = %d\n", i, curr->data); 
	}

	printf("--------5���� ��尡 �����Ǿ����ϴ�.------------\n");

	newNode = createNode(99); //newNode : 99�� �����͸� ���� ��带 �����ϱ� 
	curr = getNodeAt(list, 0); //curr ��� : �ε���0��°�� ��带 ��������
	insertAfter(curr, newNode); //0��° ����� curr������ 

	newNode = createNode(444);
	curr = getNodeAt(list, 4);
	insertAfter(curr, newNode);
	printf("����1\n");

	//���� ������ ���
	count = countNode(list);
	for (i = 0; i < count; i++) {
		curr = getNodeAt(list, i);
		printf("list[%d] = %d\n", i, curr->data); 
	}
	printf("����2\n");

	printf("---------2���� ��尡 ���ԵǾ����ϴ�.------------\n");

	newNode = getNodeAt(list, 1);
	removeNode(&list, newNode); //1��° ��� ����
	
	newNode = getNodeAt(list, 0);
	removeNode(&list, newNode); //0��° ��� ����
	
	printf("����2\n");
	//���� ������ ���
	count = countNode(list);
	for (i = 0; i < count; i++) {
		curr = getNodeAt(list, i);
		printf("list[%d] = %d\n", i, curr->data); //���� ������ ���
	}

	printf("------2���� ��尡 �����Ǿ����ϴ�.---------\n");


	return 0;
}


NODE * createNode(int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	//���� �ʱ�ȭ
	newNode->data = data;
	newNode->Llink = NULL;
	newNode->Rlink = NULL;
	
	return newNode;	
}


void deleteNode(NODE * Node)
{
	free(Node); //�޸𸮻󿡼� �����ִ� ���Ҹ� ����?
	
	/*(����)
	??��� ������ ���������� �����ϴ� ���� �ƴ϶�
	�޸𸮻󿡼��� '�ǹ̾���' ����� ��??
	*/
}

void removeNode(NODE** head, NODE* remove)
{
	/*3���� ��� : remove�� ��尡
	(1) head�� ���
	�߰��� ��ġ�� ���		?? �� �̷��� ����ؾ� �ϴ°�??
		(2) �� �ڿ� ��尡 ���� ���
		(3) �� �տ� ��尡 ���� ���
	*/

	if (*head == remove)//(1)
		*head = remove->Rlink; //�ǹ� : head�� ���������� �� �Ǳ� ������ remove������ �ִ� ������ ���� ��Ų �� ����
	
	if(remove->Rlink != NULL) //(2) remove�� ��� �ڿ� ��尡 ���� ���
		remove->Rlink->Llink = remove->Llink; //�ǹ� : remove�� ����� �� ���� ��带 ���� ��������ֱ�
	
	if (remove->Llink != NULL)//(3) remove�� ��� �տ� ��尡 ���� ���
		remove->Llink->Rlink = remove->Rlink; //�ǹ� : (2)�� ����

	deleteNode(remove); //������ ����������ν� ���� ������ ����� remove��带 heap�޸𸮿��� ������Ű�鼭 ������ �����ϱ�

}

NODE * getNodeAt(NODE * head, int index)
{
	NODE* horse = head; //��� : �˻��� ���� ����Ʈ�� ��ȸ�ϴ� ����, '��'
	int count = 0; //��� : for���� ��� �� �ϰ� �˻��ϰ� �ִ� �ε��� ���� 

	while (horse != NULL) {//horse : ���� �ƴҶ����� �޷��� -> �� ����Ʈ�� ���� �����ϸ� while���� ���������� ��
		if (count++ == index) //index : ã���� �ϴ� �ε���
			return horse;
		horse = horse->Rlink; //(���� ����) horse = (*horse).Rlink;
	}
	 
	return NULL;
}

int countNode(NODE *head)
{
	int count = 0;
	NODE* horse = head; 

	while (horse != NULL) { //horse : ���� �ƴϸ� �޸��� �ϱ�
		horse = horse->Rlink;
		count++;
	}

	return count; //���̸� count ����
}

void addNode(NODE ** head, NODE *newNode) //(����)?����� �� ���������͸� �Ű������� �־��ֳ�??
{
	/*(����)��� �߰��� �� ���� ��Ȳ ����
	(1) ����Ʈ�� �ƹ��͵� ���� ���
	(2) ����Ʈ�� ��尡 ������ �� -> �� �ڿ� �߰�
	*/

	//(1) ���
	if ((*head) == NULL)
		*head = newNode;
	//(2) ���
	else {
		NODE* horse = (*head);

		while (horse->Rlink != NULL)
			horse = horse->Rlink;
		
		horse->Rlink = newNode;
		newNode->Llink = horse;

	}
}
/*? addNode()�� insertAfter()�� ����?

*/

void insertAfter(NODE* current, NODE* newNode)
{

	/*(����)������ ��� �� ���� ���
	(1) head�� ������(����Ʈ�� �ƹ��͵� ���� ���)
	(2) tail�� ������
	(3) middle�� ������
	*/
	
	//(1)
	if (current->Rlink == NULL && current->Llink == NULL){
		current->Rlink = newNode; 
		newNode->Llink = current;
	}
	//(2) current�� �� ���� ���
	if (current->Rlink == NULL) {
		current->Rlink = newNode;
		newNode->Llink = current;
	}
	else { //(3) �߰��� �ִ� current �ڿ� newNode ����

		/*�ؾ� �� �۾�
		 : ������ �ڸ��� ���� link�� ���� newNode�� ����
		*/
		current->Rlink->Llink = newNode; 
		newNode->Llink = current;
		newNode->Rlink = current;
		current->Rlink = newNode;
		//(����)current�� newNode ��� ������ ������!
	}


}
