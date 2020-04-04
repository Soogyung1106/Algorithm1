/*���� �˻�*/
import java.util.Scanner;

public class BinSearch {
	
	static int binSearch(int[] array, int num, int key) {
		int left=0; //�˻� ������ ù �ε��� (�� ó�� left�� �翬�� �迭�� ù �����) 
		int right = num-1; //�˻� ������ �� �ε��� (�� ó�� right�� �翬�� �迭�� �� �����)
		
		do {
			int middle = (left+right)/2; //�߾� ����� �ε���
			
			//3���� ��� ����
			if(array[middle]==key)
				return middle; //�˻� ����!
			else if(array[middle]<key)
				left = middle +1; //�˻� ������ ���� �������� ����!
			else //array[middle]>key
				right = middle -1; //�˻� ������ �������� ����
		
		}while(left<=right);
			
		return -1; //�˻� ����!	
		
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("��ڼ� : ");
		int num = scanner.nextInt(); 
		int[] array = new int[num]; //��ڼ��� num�� �迭
		
		System.out.println("������������ �Է��ϼ���.");
		
		System.out.println("array[0] : "); //ù ��� �Է�
		array[0] = scanner.nextInt();
		
		for(int i=1;i<num;i++) {
			do {
				System.out.print("array["+i+"] : ");
				array[i] = scanner.nextInt(); 
			}while(array[i]<array[i-1]); //�ٷ� ���� ��Һ��� ������ �ٽ� �Է�
		}
		
		System.out.print("�˻��� �� : "); //Ű ���� �Է�
		int key = scanner.nextInt();
		
		int index = binSearch(array, num, key); //�迭 array���� Ű ���� key�� ��Ҹ� �Է� -> index : ã���� �ϴ� ���� �ִ� �ε��� ��ġ
		
		if(index == -1)
			System.out.println("�� ���� ��Ұ� �����ϴ�.");
		else
			System.out.println(key+"��(��) array["+index+"]�� �ֽ��ϴ�.");
			
	}

}
