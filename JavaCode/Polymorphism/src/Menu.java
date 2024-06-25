import java.util.Scanner;

public class Menu implements MenuOption{
	Scanner sc = new Scanner(System.in);
	
	public void display() {
		System.out.println("1. Add rectangle");
		System.out.println("2. Add triangle");
		System.out.println("3. See all shapes");
		System.out.println("4. Exit");
	}
	
	public int inputSize() {
		System.out.println("Input size please");
		int size = sc.nextInt();
		return size;
	}
	
	public int inputChoice() {
		System.out.println("Input choice please");
		int choice = sc.nextInt();
		return choice;
	}
}
