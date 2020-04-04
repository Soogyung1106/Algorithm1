import java.util.Arrays;
import java.util.Scanner;
//문자열의 배열(Java의 키워드)에서 검색 -> 자연 정렬로 정렬된 배열에서 검색하기

public class StringBinarySearch {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		//Java에서 사용하는 키워드입니다.
		String[] x = {
				"abstract", "assert", "boolean", "break", 
				"case", "catch", "char", "class",
				"continue", "default", "do", "double",
				"enum", "extends", "final", "finally",
				"for", "goto", "if", "implements", "import",
				"instanceof", "int", "interface", "long", "native",
				
				
				"new", "package", "private", "protected", "public",
		};
		
		System.out.println("원하는 키워드를 입력하세요 : ");//키 값을 입력
		
		String key = scanner.next();
		
		int index = Arrays.binarySearch(x, key); //배열 x에서 값이 key인 요소를 검색
		
		if(index<0)
			System.out.println("해당 키워드가 없습니다.");
		else
			System.out.println("해당 키워드는 x["+index+"]에 있습니다.");

	}

}
