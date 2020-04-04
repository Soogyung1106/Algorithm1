
public class Test {

	public static void main(String[] args) {
		String array2[] = new String[5];
		
		array2[0] = "<-";
		
		for(int i=0;i<5;i++) {
			if(i!=0)
				array2[i]=" ";
		}
		
		for(int i=0;i<5;i++)
			System.out.print(array2[i]);

	}

}
