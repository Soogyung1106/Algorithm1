/* <�迭 ����� �ִ� ���ϴ� �˰���> 
 * ù ��°�� max�� �α�
 * �� ��°���� max�� ���Ͽ�  max���� ũ�� �� ��° ��Ҹ� max�� �缳�����ֱ�
 * ��� max�� ���ؼ� max�� �� �缳�����ֱ�
 * */
import java.util.Scanner;

public class MaxOfArray {
	
	//maxOf() 
	static int maxOf(int[] a) { //??static�� ��������??
		int max = a[0]; //ù ��°�� ū �ŷ� ����
		for(int i=1;i<a.length;i++) {
			if(a[i]>max)
				max = a[i];
		}
		return max;
	}

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		System.out.println("Ű�� �ִ��� ���մϴ�.");
		System.out.println("��� �� : ");
		int num = stdIn.nextInt(); //�迭�� ��ڼ��� �Է� ����
		
		int[] height = new int[num]; //��ڼ��� num�� �迭�� ������
		
		for(int i=0;i<num;i++) {
			System.out.print("height["+i+"] : ");
			height[i] = stdIn.nextInt();
		}
		
		System.out.println("�ִ��� "+maxOf(height)+"�Դϴ�.");
	}
		
}
