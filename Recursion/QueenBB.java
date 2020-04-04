
public class QueenBB {
	
	//필드
	static boolean[] flag = new boolean[8]; //각 행에 퀸을 배치했는지 체크
	static int[] pos = new int[8]; //각 열의 퀸의 위치
	
	//메서드
	static void print() { //각 열의 퀸의 위치 출력
		for(int i=0;i<8;i++)
			System.out.printf("%2d", pos[i]);
		System.out.println();
	}
	
	static void set(int i) { //i열의 알맞은 위치에 퀸 배치
		for(int j=0;j<8;j++) {
			if(flag[j]=false) 
				
		}
			
	}
	
	//메인
	public static void main(String[] args) {
		set(0);
	}

}
