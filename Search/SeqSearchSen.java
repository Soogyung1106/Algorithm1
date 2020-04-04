import java.util.Scanner;
//선형 검색(보초법)
public class SeqSearchSen {
	
	static int seqSearchSen(int[] x, int num, int key) {
		int i=0;
		x[num] = key; //인덱스 맨끝에 보초를 추가
		
		while(true) {
			if(x[i] == key)
				break;
			i++;
		}
		
		return i == num ? -1 : i; // 만약에 i 인덱스 위치가 맨 끝에 있으면 -1 반환 
		
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("요솟수 : ");
		int num = scanner.nextInt();
		int[] x = new int[num+1]; //요솟수 num+1 -> 보초값 때문에 공간 한 개 추가
		
		for(int i=0;i<num;i++) {
			System.out.print("x[" +i+"] : ");
			x[i] = scanner.nextInt();
		}
		
		System.out.print("검색할 값 : "); //키 값을 입력
		int key = scanner.nextInt();
		
		int idx = seqSearchSen(x, num, key); //배열 x에서 값이 key인 요소를 검색해서 그 위치의 인덱스 반환
		
		if(idx==-1)
			System.out.println("그 값의 요소가 없습니다.");
		else
			System.out.println(key+"은(는) x["+idx+"]에 있습니다.");

		
	}

}
