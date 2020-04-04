/*
추상 클래스 개념, 객체 배열 개념 -> 잘 알고 있니? 
*/

#include <iostream>
#include <cstring>
#include <array>

using namespace std;

class Food {
public:
	string name; //이름
	int price; //가격

	//초기화
	Food(string name, int price) { this->name = name; this->price = price; }
	Food() {};
};

class DeliveryStore { //추상클래스: 배달 음식점
public:
	virtual void set_order_list(string order[]) = 0; // 주문 메뉴의 리스트를 매개변수로 받음
	virtual int get_total_price() = 0; //주문 받은 음식 가격의총합을 return 

};


class PizzaStore : public DeliveryStore{ //피자 배달 전문점 -> DeliveryStore의 파생클래스
	
public:
	string order_list[5]; //주문 받은 리스트 -> 길이 1이상 5이하 
	Food menu_list[5];

	PizzaStore() { //메뉴의 이름과 가격을 초기화

		//메뉴에 있는 음식들에 대한 리스트
		//Food menu_list[5] = { Food("Cheese", 100), Food("Bannana", 400), Food("Pizza", 500), Food("Pineapple", 200),Food("Meatball", 300)};
		menu_list[0] = Food("Cheese", 100);
		menu_list[1] = Food("Bannana", 400);
		menu_list[2] = Food("Pizza", 500);
		menu_list[3] = Food("Pineapple", 200);
		menu_list[4] = Food("Meatball", 300);

	}

	virtual void set_order_list(string order[]){ //주문 메뉴 리스트를 받아 order_list에 저장
		//주문 메뉴를 받아 order_list[]에 저장

		for (int i = 0; i < 3 ; i++) {
			order_list[i] = order[i];
		}

	}

	virtual int get_total_price() { //주문한 메뉴의 전체 가격 리턴
		//order_list[]에 들어있는 음식 가격의 총합을 retrun 

		int sum = 0;

		for (int i = 0; i < 3; i++) { //주문한 음식이 메뉴에 있는지 확인 -> 있다면 가격 누적 
			for (int j = 0; j < 5; j++) {
				if (order_list[i] == menu_list[j].name)
					sum += menu_list[j].price;
			}
			
		}

		return sum;

	}

};




int main() {
	
	string order[] = { "Cheese", "Pineapple", "Meatball" }; //고객이 주문할 음식

	PizzaStore domino;
	PizzaStore *pdomino;
	pdomino = &domino;
	
	pdomino->set_order_list(order); //(1) 주문한 매뉴 전달
	int total_price = pdomino->get_total_price(); //(2) 총 가격 계산

	printf("%d원 입니다.\n", total_price); //(3) 출력

}



