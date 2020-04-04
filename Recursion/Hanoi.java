import java.util.Scanner;
//�ϳ����� ž
public class Hanoi {
		
	//move �޼ҵ� : num���� ������ x�� ��տ��� y�� ������� �ű�
	static void move(int num,int x,int y) {
		if(num>1)
			move(num-1, x, 6-x-y);
		
		System.out.println("����["+num+"]�� "+x+"��տ��� "+y+"������� �ű�");
		
		if(num>1)
			move(num-1,6-x-y, y);
		
	}
	
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("�ϳ����� ž");
		System.out.print("���� ���� : ");
		int n= scanner.nextInt();
		
		move(n,1,3); //n���� ������ 1�� ��տ��� 3�� ������� �ű�ڴ�.

	}

}
