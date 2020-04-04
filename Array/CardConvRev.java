/*< 기수 변환을 수행하는 프로그램 >
 * 입력받은 10진수를 2진수~36진수로 기수 변환하여 나타냄
 */
import java.util.Scanner;

public class CardConvRev {
	//정숫값 x를 r진수로 변환하여 배열 d에 아랫자리부터 넣어두고 자릿수를 반환합니다.
	static int change(int num, int x, char[] changed_num) {
		int index = 0;	//변환 후의 자릿수
		String ref = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		
		do {
			changed_num[index++] = ref.charAt(num % x); //입력받은 '10진수 숫자'를 '기수'로 나누기 -> n진수로 표현하는 방법
			num/=x; // num = num/x -> num은 기수로 나누고 나온 '몫'으로 초기화됨
		}while(num!=0); //0이 아닐 때까지 나누기 = 몫이 0이 될 때 끝난다는 소리
		
		return index;
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int num; //사용자로부터 입력받은 10진수 정수
		int x; // 기수
		int index; //변환 후의 배열의 인덱스 현위치
		int retry; //다시 한 번의 여부
		char[] changed_num = new char[32]; //변환 후 각 자리의 숫자를 넣어두는 문자의 배열
		
		System.out.println("10진수를 기수 변환합니다.");
		do {
			do {
				System.out.print("변환하는 음이 아닌 정수 : ");
				num = scanner.nextInt();
			}while(num<0); //이 조건식이 참이라면 위에 반복
			
			do {
				System.out.print("어떤 진수로 변환할까요?(2~36) : ");
				x = scanner.nextInt();
			}while(x <2 || x> 36); //이 조건식이 참이라면 위에 반복
			
			//기수 변환하는 메서드 호출
			index = change(num, x, changed_num);  //입력받은 num을 x진수로 변환해서 cnum_array에 거꾸로 저장
			
			System.out.print(x+"진수로는 ");
			for(int i=index-1 ; i>=0 ; i--) //윗자리부터 차례로 나타냄 (초, 조, 증), index 현상태는 요소가 마지막으로 넣어져있는 위치 그다음 번째 위치임
				System.out.print(changed_num[i]);
			System.out.println("입니다.");
			
			System.out.println("한 번 더 할까요? (1. 예/ 0.아니오) : ");
			retry = scanner.nextInt();
			
		}while(retry==1);  //참일 경우 위에 식 반복
	}
	
	
}
