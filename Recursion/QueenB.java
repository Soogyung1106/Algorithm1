//�� ���� 1���� ���� ��ġ�ϴ� ������ ��������� �����մϴ�.

public class QueenB {
	
	static int[] pos = new int[8]; //�� ������ ���� ��ġ
	
	//�� ���� ���� ��ġ�� �����
	static void print() {
		for(int i=0;i<8;i++)
			System.out.printf("%2d", pos[i]);
		System.out.println();
	}
	
	
	//i���� ���� �����ϴ�.
	static void set(int i) {
		for(int j=0;j<8;j++) {
			pos[i]=j;
			if(i==7)
				print();
			else
				set(i+1);
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		set(0);
	}

}
