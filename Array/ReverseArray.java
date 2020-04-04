/* < �迭 ��ҿ� ���� �о� �鿩 �������� ���� �˰��� > 
 * ũ��� x, �������� ���� -> swap �Լ� �̿�
 * */
import java.util.Scanner;

public class ReverseArray {
	//�迭 ��� a[idx1]�� a[idx2]�� ���� �ٲ�
	
	static void swap(int[] a, int idx1, int idx2) {
		int t = a[idx1]; //idx1 = i
		
		
		a[idx1] = a[idx2]; //idx2 = a.length-i-1
		a[idx2] = t;
		
	}
	
	static void reverse(int[] a) {
		for(int i=0;i<a.length/2;i++) {
			swap(a, i, a.length-i-1); // reverse �޼��� �ȿ��� swap ȣ��
		}
	}
	
	public static void main(String[] args) {
		Scanner scanner  = new Scanner(System.in);
		
		System.out.print("��ڼ� : ");
		int num = scanner.nextInt(); //��ڼ�
		
		int[] x = new int[num]; //��ڼ��� num�� �迭 ����
		
		for(int i=0;i<num;i++) {
			System.out.print("x["+i+"] : ");
			x[i] = scanner.nextInt();
		}
		
		reverse(x); //�迭 a�� ��Ҹ� �������� ����
		
		System.out.println("��Ҹ� �������� �����߽��ϴ�.");
		
		for(int i=0;i<num;i++) 
			System.out.println("x["+i+"] = "+x[i]);
		
	}

}
