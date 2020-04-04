/*이진 검색*/
import java.util.Scanner;

public class BinSearch2 {
	
	static int binSearch(int[] array, int num, int key) {
		int left=0; //검색 범위의 첫 인덱스 (맨 처음 left는 당연히 배열의 첫 요소임) 
		int right = num-1; //검색 범위의 끝 인덱스 (맨 처음 right는 당연히 배열의 끝 요소임)
		String[] array2 = new String[num];
		
		System.out.print("  |");
		for(int i=0;i<num;i++) {
			System.out.print(" "+i+" ");
		}
		System.out.println();
		System.out.println("-------------------------");
		
		
		do {
			int middle = (left+right)/2; //중앙 요소의 인덱스
			
			
			
			//3가지 경우 있음
			if(array[middle]==key) {
				
				for(int i=0;i<=right;i++) {
					if(i==left)
						array2[i] = "<-";
					else if(i==right)
						array2[i]="->";
					else if(i==middle)
						array2[i] = "+";
					else
						array2[i] = " ";
				}
				
				//(1) 방향 출력
				System.out.print("  |");
				for(int i=0;i<=right;i++) {
					System.out.print(array2[i]+"  ");
				}
				System.out.println();
				
				//(2) middle값 및 배열의  요소 출력 
				System.out.print(middle+" |");
				for(int i=0;i<num;i++) {
					System.out.print(" "+array[i]+" ");
				}
				System.out.println();
				return middle; //검색 성공!
			}
			else if(array[middle]<key) {
				//(1) 방향 출력
				for(int i=0;i<=right;i++) {
					if(i==left)
						array2[i] = "<-";
					else if(i==right)
						array2[i]="->";
					else if(i==middle)
						array2[i] = "+";
					else
						array2[i] = " ";
				}
				System.out.print("  |");
				for(int i=0;i<=right;i++) {
					System.out.print(array2[i]+"  ");
				}
				System.out.println();
				
				//(2) middle값 및 배열의  요소 출력 
				System.out.print(middle+" |");
				for(int i=0;i<num;i++) {
					System.out.print(" "+array[i]+" ");
				}
				
				System.out.println();
				
				left = middle +1; //검색 범위를 뒤쪽 절반으로 좁힘!
				
				
				for(int i=0;i<=right;i++) {
					if(i==left)
						array2[i] = "<-";
					else if(i==right)
						array2[i]="->";
					else if(i==middle)
						array2[i] = "+";
					else
						array2[i] = " ";
				}
				
				//(1) 방향 출력
				System.out.print("  |");
				for(int i=0;i<=right;i++) {
					System.out.print(array2[i]+"  ");
				}
				System.out.println();
				
				//(2) middle값 및 배열의  요소 출력 
				System.out.print(middle+" |");
				for(int i=0;i<num;i++) {
					System.out.print(" "+array[i]+" ");
				}
				System.out.println();
			}
			else {//array[middle]>key
				right = middle -1; //검색 범위를 절반으로 줄임
				
				for(int i=0;i<=right;i++) {
					if(i==left)
						array2[i] = "<-";
					else if(i==right)
						array2[i]="->";
					else if(i==middle)
						array2[i] = "+";
					else
						array2[i] = " ";
				}
				
				//(1) 방향 출력
				System.out.print("  |");
				for(int i=0;i<=right;i++) {
					System.out.print(array2[i]+"  ");
				}
				System.out.println();
				
				//(2) middle값 및 배열의  요소 출력 
				System.out.print(middle+" |");
				for(int i=0;i<num;i++) {
					System.out.print(" "+array[i]+" ");
				}
				System.out.println();
			}	
		}while(left<=right);
			
		return -1; //검색 실패!	
		
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("요솟수 : ");
		int num = scanner.nextInt(); 
		int[] array = new int[num]; //요솟수가 num인 배열
		
		System.out.println("오름차순으로 입력하세요.");
		
		System.out.println("array[0] : "); //첫 요소 입력
		array[0] = scanner.nextInt();
		
		for(int i=1;i<num;i++) {
			do {
				System.out.print("array["+i+"] : ");
				array[i] = scanner.nextInt(); 
			}while(array[i]<array[i-1]); //바로 앞의 요소보다 작으면 다시 입력
		}
		
		System.out.print("검색할 값 : "); //키 값을 입력
		int key = scanner.nextInt();
		
		int index = binSearch(array, num, key); //배열 array에서 키 값이 key인 요소를 입력 -> index : 찾고자 하는 값이 있는 인덱스 위치
		
		if(index == -1)
			System.out.println("그 값의 요소가 없습니다.");
		else
			System.out.println(key+"은(는) array["+index+"]에 있습니다.");
			
	}

}
