
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Integer[] intArray = {1, 2,3 ,4 , 5};
		Double[] doubArray = {1.1, 2.2, 3.3, 4.4, 5.5};
		Character[] charArray = {'H', 'E', 'L', 'L', 'O'};
		
		System.out.print("Elements in intArray: ");
		Main.<Integer>printArray(intArray);
		System.out.print("Elements in doubArray: ");
		printArray(doubArray);
		System.out.print("Elements in charArray: ");
		printArray(charArray);
		
		Rectangle rec = new Rectangle(2,10);
		
		Triangle tri = new Triangle(4, 10);
		
		Triangle tri2 = new Triangle(6,10);
		
		System.out.println(equalArea(rec,tri));
		
		
		System.out.println("Biggest size: " + getMax(rec.getArea(), tri.getArea(), tri2.getArea()));
		
		Integer[] arr = {0, 9, 20, 11, 9, 20, 30, 390, 1};
		
		System.out.println("Biggest from int arr: " + getMax(arr));
		
		Double[] doubArr = {1.1,3.3,2.2,9.9,0.2,2.1};
		
		System.out.println("BIggest double from doubArr: " + getMax(doubArr));
		
	}
	
//	public static void printArray(Integer[] intArray) {
//		for(Integer element : intArray) {
//			System.out.print(element + " ");
//		}
//		System.out.println("");
//	}
//	public static void printArray(Character[] array) {
//		for(Character element : array) {
//			System.out.print(element + " ");
//		}
//		System.out.println("");
//	}
//	public static void printArray(Double[] array) {
//		for(Double element : array) {
//			System.out.print(element + " ");
//		}
//		System.out.println("");
//	}
	
	public static <T> void printArray(T[] arr) {
		for(T element : arr) {
			System.out.print(element + " ");
		}
		System.out.println();
	}
	
	public static <E extends Shape> boolean equalArea(E shape1, E shape2) {
		return shape1.getArea() == shape2.getArea();
	}
	
	public static <T extends Comparable<T> > T getMax(T a, T b, T c) {
		T max = a;
		if(b.compareTo(max) > 0) max = b;
		if(c.compareTo(max) > 0) max = c;
		
		return max;
	}
	
	public static <T extends Comparable<T> > T getMax(T[] list) {
		T max = list[0];
		int size = list.length;
		for(int i=1; i<size; i++) {
			if(max.compareTo(list[i]) < 0) max = list[i];
		}
		
		return max;
	}
	
	
}
