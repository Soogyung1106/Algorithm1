/* < 배열 요소에 값을 읽어 들여 역순으로 정렬 알고리즘 > 
 * 크기순 x, 역순으로 정렬 -> swap 함수 이용
 * */
import java.util.Scanner;

public class ReverseArray {
	//배열 요소 a[idx1]와 a[idx2]의 값을 바꿈
	
	static void swap(int[] a, int idx1, int idx2) {
		int t = a[idx1]; //idx1 = i
		
		
		a[idx1] = a[idx2]; //idx2 = a.length-i-1
		a[idx2] = t;
		
	}
	
	static void reverse(int[] a) {
		for(int i=0;i<a.length/2;i++) {
			swap(a, i, a.length-i-1); // reverse 메서드 안에서 swap 호출
		}
	}
	
	public static void main(String[] args) {
		Scanner scanner  = new Scanner(System.in);
		
		System.out.print("요솟수 : ");
		int num = scanner.nextInt(); //요솟수
		
		int[] x = new int[num]; //요솟수가 num인 배열 선언
		
		for(int i=0;i<num;i++) {
			System.out.print("x["+i+"] : ");
			x[i] = scanner.nextInt();
		}
		
		reverse(x); //배열 a의 요소를 역순으로 정렬
		
		System.out.println("요소를 역순으로 정렬했습니다.");
		
		for(int i=0;i<num;i++) 
			System.out.println("x["+i+"] = "+x[i]);
		
	}

}
