import java.util.Arrays;
import java.util.Scanner;
//Arrays.binarySearch�� ���� �˻�

public class BinarySearchTester {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("��ڼ� : ");
		int num = scanner.nextInt();
		int[] x = new int[num]; //��ڼ��� num�� �迭
		
		System.out.println("������������ �Է��ϼ���.");
		
		System.out.print("x[0] : "); //�迭�� ù ��Ҹ� ���� �Է��Ѵ�.
		x[0] = scanner.nextInt();
		
		for(int i=1; i<num;i++) {
			do {
				System.out.println("x["+i+"] : ");
				x[i] = scanner.nextInt();
				
			}while(x[i]<x[i-1]); //�ٷ� ���� ��Һ��� ������ �ٽ� �Է��Ѵ�.
		}
		
		System.out.println("�˻��� �� : "); //Ű ���� �Է� ����
		int key = scanner.nextInt();
		
		int index = Arrays.binarySearch(x,key); 
		
		if(index<0)
			System.out.println("�� ���� ��Ұ� �����ϴ�.");
		else
			System.out.println(key+"��(��) x["+index+"]�� �ֽ��ϴ�.");

	}

}
