import java.util.Scanner;
//하노이의 탑
public class Hanoi {
		
	//move 메소드 : num개의 원반을 x번 기둥에서 y번 기둥으로 옮김
	static void move(int num,int x,int y) {
		if(num>1)
			move(num-1, x, 6-x-y);
		
		System.out.println("원반["+num+"]을 "+x+"기둥에서 "+y+"기둥으로 옮김");
		
		if(num>1)
			move(num-1,6-x-y, y);
		
	}
	
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("하노이의 탑");
		System.out.print("원반 개수 : ");
		int n= scanner.nextInt();
		
		move(n,1,3); //n개의 원반을 1번 기둥에서 3번 기둥으로 옮기겠다.

	}

}
