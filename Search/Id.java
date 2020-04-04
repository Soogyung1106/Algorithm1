//���̵� �ο��ϴ� Ŭ����
public class Id {
	//�ʵ�
	private static int counter =0; //���̵� �� �� �ο��ߴ��� ���� (Ŭ���� ����)
	private int id; //���̵� (�ν��Ͻ� ����)
	
	
	//������
	public Id() {
		id = ++ counter;
	}
	
	//�޼ҵ�
	public int getId() { //���̵� ��ȯ�ϴ� �ν��Ͻ� �޼ҵ�
		return id;
	}
	
	public static int getCounter() { //ī���͸� ��ȯ�ϴ� Ŭ���� �޼ҵ�
		return counter;
	}

}

//Ŭ����
class IdTester{
		public static void main(String[] args) {
			Id a = new Id(); //���̵�1
			Id b = new Id(); //���̵�2
			
			System.out.println("a�� ���̵� : "+a.getId()); //�ν��Ͻ� �޼ҵ� ȣ��Ǵ� ��Ŀ� ����
			System.out.println("b�� ���̵� : "+b.getId());
			
			System.out.println("�ο��� ���̵��� ���� : "+Id.getCounter()); //Ŭ���� �޼ҵ� ȣ��Ǵ� ��Ŀ� ����
		}
	}
