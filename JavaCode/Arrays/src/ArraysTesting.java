import java.util.Arrays;


public class ArraysTesting {

	public static void main(String[] args) {
		int[] num = {5,8,2,9,3};
		
		printArr(num);
		
		int[] x = num;
		num[0] = 1;
		
		printArr(x);

		int[] y = new int[5];
		System.arraycopy(num, 0, y, 0, 5);
		x[1] = 2;
		
		printArr(x);
		printArr(y);
		
		int[] z = (int[])num.clone();
		num[2]=3;
		printArr(num);
		printArr(z);
		
		String[] nameList = {"Budi", "Susi", "Gery", "Charlie"};
		for(String name : nameList ) {
			System.out.println(name);
		}
		
		int[] unsortedNum = {8,4,6,2,9,3};
		System.out.println("Before: " + Arrays.toString(unsortedNum));
		Arrays.sort(unsortedNum);
		System.out.println("After: " + Arrays.toString(unsortedNum));
		
		System.out.println("\nExample fill:");
		System.out.println("Before: " + Arrays.toString(num));
		Arrays.fill(num, 23);
		System.out.println("After: " + Arrays.toString(num));
		
		System.out.println("\nExample partial fill:");
		System.out.println("Before: " + Arrays.toString(num));
		Arrays.fill(num,0,2, 20);
		System.out.println("After: " + Arrays.toString(num));
	}
	
	public static void printArr(int[] arr) {
		for(int i=0; i< arr.length*2; i++) {
			System.out.print("=");
		}
		System.out.println("");
		System.out.println();
		for(int i=0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println("");
		for(int i=0; i< arr.length*2; i++) {
			System.out.print("=");
		}
		System.out.println("");
	}

}
