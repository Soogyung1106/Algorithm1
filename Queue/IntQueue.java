//int�� ť

public class IntQueue {
	
	//1. �ʵ�
	private int max; //ť�� �뷮
	private int front; //ù ��° ��� Ŀ��
	private int rear; //������ ��� Ŀ��
	private int num; //���� ������ ��
	private int[] que; //ť ��ü
	
	//2. Ŭ����
	
	//���� �� ���� : ť�� �������
	public class EmptyIntQueueException extends RuntimeException{
		public EmptyIntQueueException() { }
	}
	
	//���� �� ���� : ť�� ���� ��
	public class OverflowIntQueueException extends RuntimeException{
		public OverflowIntQueueException() { }
	}
	
	//3. ������
	public IntQueue(int capacity) {
		num = front = rear = 0;
		max = capacity;
		try {
			que = new int[max]; //ť ��ü�� �迭�� ����
		}catch(OutOfMemoryError e) { //������ �� ����
			max=0;
		}
	}
	
	//4. �޼ҵ�
	
	//ť�� �����͸� ��ť
	public int enque(int x) throws OverflowIntQueueException{
		
		if(num>=max)
			throw new OverflowIntQueueException(); //ť�� ���� ��
		 
		que[rear++] =x;
		num++;
		 
		 if(rear==max) //�� ������ rear = 0���� �������� ���ư�
			 rear=0;
		 
		 return x;
	}
	
	//ť���� �����͸� ��ť
	public int deque() throws EmptyIntQueueException{		
		
		if(num<=0)
			throw new EmptyIntQueueException(); //ť�� �������
		
		int x = que[front++];
		num--;
		
		if(front == max)
			front=0;
		
		return x;	
	}
	
	//ť���� �����͸� ��ũ(����Ʈ �����͸� �鿩�ٺ�)
	public int peek() throws EmptyIntQueueException{
		if(num<=0)
			throw new EmptyIntQueueException(); //ť�� �������
		return que[front];
	}
	
	//ť���� x�� �˻��Ͽ� �ε���(ã�� ���ϸ� -1�� ��ȯ)
	public int search(int x) {
		
		for(int i=0;i<num;i++) {
			int idx=(i+front)%max;
			if(que[idx]==x) //�˻� ����
				return idx;
		}
		return -1; //�˻� ����
	}
	
	//ť�� ���
	public void clear() {
		num=front=rear=0;
	}
	
	//ť�� �뷮�� ��ȯ
	public int capacity() {
		return max;
	}
	
	//ť�� �׿� �ִ� ������ ���� ��ȯ
	public int size() {
		return num;
	}
	
	//ť�� ��� �ֳ���?
	public boolean inEmpty() {
		return num<=0;
	}
	
	//ť�� ���� á����?
	public boolean isFull() {
		return num>=max;
	}
	
	//ť ���� ��� �����͸� ����Ʈ -> ���� ������ ���
	public void dump() {
		if(num<=0)
			System.out.println("ť�� ��� �ֽ��ϴ�.");
		else
			for(int i=0;i<num;i++)
				System.out.println(que[(i+front)%max]+" ");
		System.out.println();
	}
	
	
}