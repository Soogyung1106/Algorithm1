/* <배열 요소의 최댓값 구하는 알고리즘> 
 * 첫 번째를 max로 두기
 * 두 번째부터 max와 비교하여  max보다 크면 두 번째 요소를 max로 재설정해주기
 * 계속 max와 비교해서 max의 값 재설정해주기
 * */
import java.util.Scanner;

public class MaxOfArray {
	
	//maxOf() 
	static int maxOf(int[] a) { //??static이 뭐였더라??
		int max = a[0]; //첫 번째를 큰 거로 설정
		for(int i=1;i<a.length;i++) {
			if(a[i]>max)
				max = a[i];
		}
		return max;
	}

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		System.out.println("키의 최댓값을 구합니다.");
		System.out.println("사람 수 : ");
		int num = stdIn.nextInt(); //배열의 요솟수를 입력 받음
		
		int[] height = new int[num]; //요솟수가 num인 배열을 생성함
		
		for(int i=0;i<num;i++) {
			System.out.print("height["+i+"] : ");
			height[i] = stdIn.nextInt();
		}
		
		System.out.println("최댓값은 "+maxOf(height)+"입니다.");
	}
		
}
