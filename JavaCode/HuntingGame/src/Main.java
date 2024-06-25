import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		ArrayList<Hunter> hunterList = new ArrayList<Hunter>();
		ArrayList<Animals> animalList = new ArrayList<Animals>();
		
		animalList.add(new Duck());
		animalList.add(new Elk());
		animalList.add(new WildBoar());
		
		try (Scanner sc = new Scanner(System.in)) {
			System.out.print("Create how many hunters? ");
			int hNum = sc.nextInt();
			sc.nextLine();
			
			for(int i=1; i<=hNum; i++) {
				System.out.print("hunter"+i+"\'s name: ");
				String name = sc.nextLine();
				hunterList.add(new Hunter(name));
			}
			
			System.out.print("Hunting for how many days? ");
			int huntNum = sc.nextInt();
			sc.nextLine();
			
			Random rand = new Random();
			
			for(int i=1; i<= huntNum; i++) {
				System.out.println("Day " + i);
				for(Hunter h : hunterList) {
					Animals caught = animalList.get(rand.nextInt(3));
					caught.makeSound();
					System.out.println(h.getName() + " has caught " + caught.getName());
					h.addScore(caught.getPoints());
				}
				System.out.println();
			}
		}
		
		hunterScore scoring = new hunterScore(hunterList);
		
		scoring.calculateScore();
	}

}
