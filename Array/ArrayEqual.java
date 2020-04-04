/* <두 배열이 같은가를 판단>
 * 
 */
import java.util.Scanner;

public class ArrayEqual {
	
	static boolean equals(int[] a, int[] b) {
		//배열의 길이부터 먼저 체크
		if(a.length != b.length)
			return false;
		
		for(int i=0;i<a.length;i++) 
			if(a[i] != b[i])
				return false;
		
		return true;
	
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("배열 a의 요솟수 : ");
		int na = scanner.nextInt(); //배열 a의 요솟수
		
		int[] a = new int[na];  //요솟수가 na인 배열
		
		for(int i = 0 ; i < na ; i++) {
			System.out.print("a["+i+"] : ");
			a[i] = scanner.nextInt();
		}
		
		System.out.print("배열 b의 요솟수 : ");
		int nb = scanner.nextInt();
		
		int[] b = new int[nb];
		
		for(int i=0; i<nb;i++) {
			System.out.print("b[" + i + "] : ");
			b[i] = scanner.nextInt();
		}
		
		System.out.print("배열 a와 b는 "+(equals(a, b) ? "같습니다." : "같지 않습니다."));
		

	}

}
