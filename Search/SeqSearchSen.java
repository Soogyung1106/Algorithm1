import java.util.Scanner;
//���� �˻�(���ʹ�)
public class SeqSearchSen {
	
	static int seqSearchSen(int[] x, int num, int key) {
		int i=0;
		x[num] = key; //�ε��� �ǳ��� ���ʸ� �߰�
		
		while(true) {
			if(x[i] == key)
				break;
			i++;
		}
		
		return i == num ? -1 : i; // ���࿡ i �ε��� ��ġ�� �� ���� ������ -1 ��ȯ 
		
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("��ڼ� : ");
		int num = scanner.nextInt();
		int[] x = new int[num+1]; //��ڼ� num+1 -> ���ʰ� ������ ���� �� �� �߰�
		
		for(int i=0;i<num;i++) {
			System.out.print("x[" +i+"] : ");
			x[i] = scanner.nextInt();
		}
		
		System.out.print("�˻��� �� : "); //Ű ���� �Է�
		int key = scanner.nextInt();
		
		int idx = seqSearchSen(x, num, key); //�迭 x���� ���� key�� ��Ҹ� �˻��ؼ� �� ��ġ�� �ε��� ��ȯ
		
		if(idx==-1)
			System.out.println("�� ���� ��Ұ� �����ϴ�.");
		else
			System.out.println(key+"��(��) x["+idx+"]�� �ֽ��ϴ�.");

		
	}

}
