import java.util.Arrays;
import java.util.Scanner;
//Arrays.binarySearch로 이진 검색

public class BinarySearchTester {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("요솟수 : ");
		int num = scanner.nextInt();
		int[] x = new int[num]; //요솟수가 num인 배열
		
		System.out.println("오름차순으로 입력하세요.");
		
		System.out.print("x[0] : "); //배열의 첫 요소를 먼저 입력한다.
		x[0] = scanner.nextInt();
		
		for(int i=1; i<num;i++) {
			do {
				System.out.println("x["+i+"] : ");
				x[i] = scanner.nextInt();
				
			}while(x[i]<x[i-1]); //바로 앞의 요소보다 작으면 다시 입력한다.
		}
		
		System.out.println("검색할 값 : "); //키 값을 입력 받음
		int key = scanner.nextInt();
		
		int index = Arrays.binarySearch(x,key); 
		
		if(index<0)
			System.out.println("그 값의 요소가 없습니다.");
		else
			System.out.println(key+"은(는) x["+index+"]에 있습니다.");

	}

}
