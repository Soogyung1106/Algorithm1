/*< ��� ��ȯ�� �����ϴ� ���α׷� >
 * �Է¹��� 10������ 2����~36������ ��� ��ȯ�Ͽ� ��Ÿ��
 */
import java.util.Scanner;

public class CardConvRev {
	//������ x�� r������ ��ȯ�Ͽ� �迭 d�� �Ʒ��ڸ����� �־�ΰ� �ڸ����� ��ȯ�մϴ�.
	static int change(int num, int x, char[] changed_num) {
		int index = 0;	//��ȯ ���� �ڸ���
		String ref = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		
		do {
			changed_num[index++] = ref.charAt(num % x); //�Է¹��� '10���� ����'�� '���'�� ������ -> n������ ǥ���ϴ� ���
			num/=x; // num = num/x -> num�� ����� ������ ���� '��'���� �ʱ�ȭ��
		}while(num!=0); //0�� �ƴ� ������ ������ = ���� 0�� �� �� �����ٴ� �Ҹ�
		
		return index;
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int num; //����ڷκ��� �Է¹��� 10���� ����
		int x; // ���
		int index; //��ȯ ���� �迭�� �ε��� ����ġ
		int retry; //�ٽ� �� ���� ����
		char[] changed_num = new char[32]; //��ȯ �� �� �ڸ��� ���ڸ� �־�δ� ������ �迭
		
		System.out.println("10������ ��� ��ȯ�մϴ�.");
		do {
			do {
				System.out.print("��ȯ�ϴ� ���� �ƴ� ���� : ");
				num = scanner.nextInt();
			}while(num<0); //�� ���ǽ��� ���̶�� ���� �ݺ�
			
			do {
				System.out.print("� ������ ��ȯ�ұ��?(2~36) : ");
				x = scanner.nextInt();
			}while(x <2 || x> 36); //�� ���ǽ��� ���̶�� ���� �ݺ�
			
			//��� ��ȯ�ϴ� �޼��� ȣ��
			index = change(num, x, changed_num);  //�Է¹��� num�� x������ ��ȯ�ؼ� cnum_array�� �Ųٷ� ����
			
			System.out.print(x+"�����δ� ");
			for(int i=index-1 ; i>=0 ; i--) //���ڸ����� ���ʷ� ��Ÿ�� (��, ��, ��), index �����´� ��Ұ� ���������� �־����ִ� ��ġ �״��� ��° ��ġ��
				System.out.print(changed_num[i]);
			System.out.println("�Դϴ�.");
			
			System.out.println("�� �� �� �ұ��? (1. ��/ 0.�ƴϿ�) : ");
			retry = scanner.nextInt();
			
		}while(retry==1);  //���� ��� ���� �� �ݺ�
	}
	
	
}
