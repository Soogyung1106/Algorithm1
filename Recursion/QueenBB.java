
public class QueenBB {
	
	//�ʵ�
	static boolean[] flag = new boolean[8]; //�� �࿡ ���� ��ġ�ߴ��� üũ
	static int[] pos = new int[8]; //�� ���� ���� ��ġ
	
	//�޼���
	static void print() { //�� ���� ���� ��ġ ���
		for(int i=0;i<8;i++)
			System.out.printf("%2d", pos[i]);
		System.out.println();
	}
	
	static void set(int i) { //i���� �˸��� ��ġ�� �� ��ġ
		for(int j=0;j<8;j++) {
			if(flag[j]=false) 
				
		}
			
	}
	
	//����
	public static void main(String[] args) {
		set(0);
	}

}
