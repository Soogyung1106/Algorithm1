import java.util.Arrays;
import java.util.Scanner;
//���ڿ��� �迭(Java�� Ű����)���� �˻� -> �ڿ� ���ķ� ���ĵ� �迭���� �˻��ϱ�

public class StringBinarySearch {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		//Java���� ����ϴ� Ű�����Դϴ�.
		String[] x = {
				"abstract", "assert", "boolean", "break", 
				"case", "catch", "char", "class",
				"continue", "default", "do", "double",
				"enum", "extends", "final", "finally",
				"for", "goto", "if", "implements", "import",
				"instanceof", "int", "interface", "long", "native",
				
				
				"new", "package", "private", "protected", "public",
		};
		
		System.out.println("���ϴ� Ű���带 �Է��ϼ��� : ");//Ű ���� �Է�
		
		String key = scanner.next();
		
		int index = Arrays.binarySearch(x, key); //�迭 x���� ���� key�� ��Ҹ� �˻�
		
		if(index<0)
			System.out.println("�ش� Ű���尡 �����ϴ�.");
		else
			System.out.println("�ش� Ű����� x["+index+"]�� �ֽ��ϴ�.");

	}

}
