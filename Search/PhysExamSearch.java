import java.util.Arrays;
import java.util.Scanner;
import java.util.Comparator; //
//��ü�˻� ������ �迭���� ���� �˻��ϱ�

public class PhysExamSearch {
	
	//Ŭ���� -> ��ü�˻� �����͸� �����մϴ�.	
	static class PhyscData{
		private String name; //�̸�
		
		private int height; //Ű
		private double vision; //�÷�
	
		//������
		public PhyscData(String name, int height, double vision) {
			this.name=name; 
			this.height = height; 
			this.vision=vision;
		}
		
		//���ڿ��� ��ȯ�ϴ� �޼���(���� Ȯ�ο�)
		public String toString() {
			return name + " " + height + " "+vision;
		}
	
		//������������ �����ϱ� ���� comparator
		public static final Comparator<PhyscData> HEIGHT_ORDER = new HeightOrderComparator();
		
		//HeightOrderComparator Ŭ����
		private static class HeightOrderComparator implements Comparator<PhyscData>{
			public int compare(PhyscData d1, PhyscData d2) {
				return (d1.height > d2.height) ? 1 : 
					(d1.height < d2.height) ? -1 : 0;
			}
		}
	
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		PhyscData[] x = { //Ű�� ������������ ���ĵǾ� �ֽ��ϴ�.
				new PhyscData("�̳���", 162, 0.3),
				new PhyscData("������", 168, 0.4),
				new PhyscData("���Ѱ�", 169, 0.8),
				new PhyscData("ȫ�ر�", 171, 1.5),
				new PhyscData("������", 173, 0.7),
				new PhyscData("��ȣ��", 174, 1.2),
				new PhyscData("�̼���", 175, 2.0),
		};
		
		System.out.print("�� cm�� ����� ã�� �ֳ���? : ");
		int height = scanner.nextInt(); //Ű �� �Է�
		int index = Arrays.binarySearch(x, new PhyscData("", height, 0.0), PhyscData.HEIGHT_ORDER);
		
		if(index<0)
			System.out.print("��Ұ� �����ϴ�.");
		else {
			System.out.println("x["+index+"]�� �ֽ��ϴ�.");
			System.out.println("ã�� ������ : "+x[index]);
		}
	}

}
