
public class IntStack {
	//1. �ʵ�
	private int max; //���� �뷮
	private int ptr; //���� ������(���ÿ� �׿��� �������� ����) -> push(), pop()�� ��
	private int[] stk; //���� ��ü
	
	//2. Ŭ����
	
	//���� �� ���� : ������ ��� ����
	public class EmptyIntStackException extends RuntimeException{
		//������
		public EmptyIntStackException() {}
	}
	
	
	//���� �� ���� : ������ ���� ��
	public class OverflowIntStackException extends RuntimeException{
		//������
		public OverflowIntStackException() {}
		
	}
	
	//3. ������ -> ����� �ʱ�ȭ
	public IntStack(int capacity) {
		ptr=0;
		max =capacity;
		try {
			stk = new int[max];	//���� ��ü�� �迭�� ����
		}catch(OutOfMemoryError e) { //������ �� ����
			max=0;
		}
	}
	
	//4. �޼ҵ�
	
	//���ÿ� x�� Ǫ��
	public int push(int x) throws OverflowIntStackException{
		if(ptr>=max)
			throw new OverflowIntStackException();
		return stk[ptr++] =x; //����ִ� ������ ���� : 3 -> ptr
	}
	
	//���ÿ��� �����͸� ��(���� �ִ� �����͸� ����)
	public int pop() throws EmptyIntStackException{
		if(ptr<=0)
			throw new EmptyIntStackException();
		return stk[--ptr]; //����ִ� ������ ���� : 3 -> �� ���� �ִ� �� : stk[2] �׸��� ptr ���ҽ�Ű��
	}
	
	//���ÿ��� �����͸� ��ũ(���� �ִ� �����͸� �鿩�ٺ�)
	public int peek() throws EmptyIntStackException{
		if(ptr<=0)
			throw new EmptyIntStackException();
		return stk[ptr-1];
	}
	
	//���ÿ��� x�� ã�� �ε���(������ -1)�� ��ȯ
	public int search(int x) {
		for(int i=ptr-1;i>=0;i--) //���� �ʿ��� ���� �˻�
			 if(stk[i]==x)
				 return i; //�˻� ����
		return -1; //�˻� ����
	}
	
	//������ ���
	public void clear() {
		ptr=0; //���ÿ� ���� �������� ���� 0���� �ʱ�ȭ
	}
	
	//������ �뷮�� ��ȯ
	public int capacity() {
		return max;
	}
	
	//���ÿ� �׿� �ִ� ������ ���� ��ȯ
	public int size() {
		return ptr;
	}
	
	//������ ��� �ִ°�?
	public boolean isEmpty() {
		return ptr<=0;
	}
	
	//������ ���� á�°�?
	public boolean isFull() {
		return ptr>=max;
	}
	
	//���� ���� ��� �����͸� �ٴ� -> ����� ������ ���
	public void dump() {
		if(ptr<=0)
			System.out.println("������ ��� �ֽ��ϴ�.");
		else {
			for(int i=0;i<ptr;i++)
				System.out.print(stk[i]+" ");
			System.out.println();
		}
	}
	
}
	
	
