/* <�� �迭�� �������� �Ǵ�>
 * 
 */
import java.util.Scanner;

public class ArrayEqual {
	
	static boolean equals(int[] a, int[] b) {
		//�迭�� ���̺��� ���� üũ
		if(a.length != b.length)
			return false;
		
		for(int i=0;i<a.length;i++) 
			if(a[i] != b[i])
				return false;
		
		return true;
	
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("�迭 a�� ��ڼ� : ");
		int na = scanner.nextInt(); //�迭 a�� ��ڼ�
		
		int[] a = new int[na];  //��ڼ��� na�� �迭
		
		for(int i = 0 ; i < na ; i++) {
			System.out.print("a["+i+"] : ");
			a[i] = scanner.nextInt();
		}
		
		System.out.print("�迭 b�� ��ڼ� : ");
		int nb = scanner.nextInt();
		
		int[] b = new int[nb];
		
		for(int i=0; i<nb;i++) {
			System.out.print("b[" + i + "] : ");
			b[i] = scanner.nextInt();
		}
		
		System.out.print("�迭 a�� b�� "+(equals(a, b) ? "�����ϴ�." : "���� �ʽ��ϴ�."));
		

	}

}
