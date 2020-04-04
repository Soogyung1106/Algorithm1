//아이디를 부여하는 클래스
public class Id {
	//필드
	private static int counter =0; //아이디를 몇 개 부여했는지 저장 (클래스 변수)
	private int id; //아이디 (인스턴스 변수)
	
	
	//생성자
	public Id() {
		id = ++ counter;
	}
	
	//메소드
	public int getId() { //아이디를 반환하는 인스턴스 메소드
		return id;
	}
	
	public static int getCounter() { //카운터를 반환하는 클래스 메소드
		return counter;
	}

}

//클래스
class IdTester{
		public static void main(String[] args) {
			Id a = new Id(); //아이디1
			Id b = new Id(); //아이디2
			
			System.out.println("a의 아이디 : "+a.getId()); //인스턴스 메소드 호출되는 방식에 집중
			System.out.println("b의 아이디 : "+b.getId());
			
			System.out.println("부여한 아이디의 개수 : "+Id.getCounter()); //클래스 메소드 호출되는 방식에 집중
		}
	}
