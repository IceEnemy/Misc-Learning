package Objects;

public class testOverloading {
	public int calculate() {
		return 0;
	}
	
	public int calculate(int a) {
		return a;
	}
	
	public int calculate(String s) {
		return s.length();
	}
	
	public int calculate (int a, int b) {
		return a + b;
	}
	
	public int calculate (String a, int b) {
		return a.length() + b;
	}
	
	public int calculate(int b, String a) {
		return a.length() + b;
	}
	
//	public int calculate (int x, int z) {
//		return x + z;
//	} --> nah this is plagiarism
	
	/*
	 Differences:
	 1. number of parameters
	 2. type of parameters
	 3. the order of parameters
	 */
}
