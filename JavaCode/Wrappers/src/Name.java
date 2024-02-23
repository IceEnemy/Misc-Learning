import java.util.InputMismatchException;
import java.util.Scanner;

public class Name {

	public static void main(String[] args) {
//		Integer a = 5;
//		Integer b = 7;
//		String c = "20";
//		System.out.println("a = " + a);
//		System.out.println("b = " + b);
//		System.out.println("doublevalue a = " + a.doubleValue());
//		System.out.println("max(a,b) = " + Integer.max(a,b));
//		System.out.println("Number of Trailing Zeroes = " + Integer.numberOfTrailingZeros(4)); //trailing zeroes from binary digits
//		System.out.println("ParseInt c = " + Integer.parseInt(c));
//		int result = a + b + Integer.parseInt(c);
//		int result2 = a + b + Integer.valueOf(c);
//		System.out.println("Result = " + result);
//		System.out.println("Result2 = " + result2);
//		System.out.println("a + b = " + Integer.sum(a, b));
//		System.out.println("Binary of 5 = " + Integer.toBinaryString(a));
//		
//		String s1 = "Hello";
//		String s2 = new String("Hello"); //research what new does and why its different
//		String s3 = "Hello";
//		
//		System.out.println("s1 = " + s1);
//		System.out.println("s2 = " + s2);
//		
//		System.out.println("s1 charAt 1 = " + s1.charAt(1));
//		System.out.println("s2 charAt 1 = " + s2.charAt(1));
//		
//		System.out.println("s1 and s2");
//		if(s1 == s2) {
//			System.out.println("Same (==)");
//		}
//		else {
//			System.out.println("Different (==)");
//		}
//		
//		if(s1.equals(s2)) {
//			System.out.println("Same (equals)\n");
//		}
//		else {
//			System.out.println("Different (equals)\n");
//		}
//		
//		System.out.println("s1 and s3");
//		if(s1 == s3) {
//			System.out.println("Same (==)");
//		}
//		else {
//			System.out.println("Different (==)");
//		}
//		
//		if(s1.equals(s3)) {
//			System.out.println("Same (equals)\n");
//		}
//		else {
//			System.out.println("Different (equals)\n");
//		}
//		
//		String s4 = "World";
//		
//		System.out.println("s1 and s4");
//		System.out.println(s1.compareTo(s4)+ "\n");
//		
//		System.out.println("s1 and s2");
//		System.out.println(s1.compareTo(s2) + "\n");
//		
//		System.out.println("s1 toUpper = " + s1.toUpperCase() + "\n");
		
//		System.out.println("PI = " + Math.PI);
//		System.out.println("sin 90 =" + Math.sin(Math.toRadians(90))); //this accepts radians
//		
//		double r = Math.random() * 100;
//		System.out.println("random number(double) = " + r);
//		
//		int r2 = (int) (Math.random() * 100);
//		
//		System.out.println("random number(int) = " + r2);
//		
//		double x = 5.8;
//		int test = (int) x;
//		System.out.println("test = " + test);
		
		System.out.println("Start");
		Scanner in = new Scanner(System.in);
		
		try {
			double z,y;
			System.out.println("Input First Number");
			z = in.nextDouble();
			System.out.println("Input Second Number");
			y = in.nextDouble();
			double div = z/y;
			System.out.println(z + "/" + y + "=" + div);
		}
		catch(ArithmeticException ex) {
			System.out.println("Cannot be divided by zero");
			ex.printStackTrace();
		}
		catch(InputMismatchException ex) {
			System.out.println("Wrong input type");
		}
		
		
		System.out.println("End");
	}

}
