/*
�߻� Ŭ���� ����, ��ü �迭 ���� -> �� �˰� �ִ�? 
*/

#include <iostream>
#include <cstring>
#include <array>

using namespace std;

class Food {
public:
	string name; //�̸�
	int price; //����

	//�ʱ�ȭ
	Food(string name, int price) { this->name = name; this->price = price; }
	Food() {};
};

class DeliveryStore { //�߻�Ŭ����: ��� ������
public:
	virtual void set_order_list(string order[]) = 0; // �ֹ� �޴��� ����Ʈ�� �Ű������� ����
	virtual int get_total_price() = 0; //�ֹ� ���� ���� ������������ return 

};


class PizzaStore : public DeliveryStore{ //���� ��� ������ -> DeliveryStore�� �Ļ�Ŭ����
	
public:
	string order_list[5]; //�ֹ� ���� ����Ʈ -> ���� 1�̻� 5���� 
	Food menu_list[5];

	PizzaStore() { //�޴��� �̸��� ������ �ʱ�ȭ

		//�޴��� �ִ� ���ĵ鿡 ���� ����Ʈ
		//Food menu_list[5] = { Food("Cheese", 100), Food("Bannana", 400), Food("Pizza", 500), Food("Pineapple", 200),Food("Meatball", 300)};
		menu_list[0] = Food("Cheese", 100);
		menu_list[1] = Food("Bannana", 400);
		menu_list[2] = Food("Pizza", 500);
		menu_list[3] = Food("Pineapple", 200);
		menu_list[4] = Food("Meatball", 300);

	}

	virtual void set_order_list(string order[]){ //�ֹ� �޴� ����Ʈ�� �޾� order_list�� ����
		//�ֹ� �޴��� �޾� order_list[]�� ����

		for (int i = 0; i < 3 ; i++) {
			order_list[i] = order[i];
		}

	}

	virtual int get_total_price() { //�ֹ��� �޴��� ��ü ���� ����
		//order_list[]�� ����ִ� ���� ������ ������ retrun 

		int sum = 0;

		for (int i = 0; i < 3; i++) { //�ֹ��� ������ �޴��� �ִ��� Ȯ�� -> �ִٸ� ���� ���� 
			for (int j = 0; j < 5; j++) {
				if (order_list[i] == menu_list[j].name)
					sum += menu_list[j].price;
			}
			
		}

		return sum;

	}

};




int main() {
	
	string order[] = { "Cheese", "Pineapple", "Meatball" }; //���� �ֹ��� ����

	PizzaStore domino;
	PizzaStore *pdomino;
	pdomino = &domino;
	
	pdomino->set_order_list(order); //(1) �ֹ��� �Ŵ� ����
	int total_price = pdomino->get_total_price(); //(2) �� ���� ���

	printf("%d�� �Դϴ�.\n", total_price); //(3) ���

}



