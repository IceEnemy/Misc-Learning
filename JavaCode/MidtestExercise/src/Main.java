import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Main {
	
//	static void printSimple(ArrayList<SimpleVirus> simpleList) {
//		int size = simpleList.size();
//		for(int i=0; i<size; i++) {
//			SimpleVirus virus = simpleList.get(i);
//			System.out.println(i + " " + virus.getName() + " " + virus.getPopulation());
//		}
//	}
//	
//	static void printResistant(ArrayList<ResistantVirus> resistantList) {
//		int size = resistantList.size();
//		for(int i=0; i<size; i++) {
//			ResistantVirus virus = resistantList.get(i);
//			System.out.println(i + " " + virus.getName() + " " + virus.getPopulation() + " " + virus.getDrug());
//		}
//	}
	
	public static void printVirusList(ArrayList<? extends SimpleVirus> virusList) {
	    int size = virusList.size();
	    for (int i = 0; i < size; i++) {
	        SimpleVirus virus = virusList.get(i);
	        System.out.println(i + " " + virus); // Uses virus's overridden toString method
	    }
	}
	
	static boolean experiment() {
		Random random = new Random();
		
		int result = random.nextInt(101);
		System.out.println("result: " + result);
		if(result > 50) {
			System.out.println("Virus becomes resistant");
			return true;
		}
		else {
			System.out.println("Virus doesn't become resistant");
			return false;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<SimpleVirus> virusList = new ArrayList<SimpleVirus>(); 
		ArrayList<ResistantVirus> resistantList = new ArrayList<ResistantVirus>();
		virusList.indexOf(resistantList);
		try (Scanner in = new Scanner(System.in)) {
			int choice;
			do {
				System.out.println("Virus Treatment Simulation");
				System.out.println("1. Generate Simple Virus");
				System.out.println("2. Experiment with Simple Virus");
				System.out.println("3. List of Resistant Virus");
				System.out.println("4. Exit");
				System.out.print("Choose menu: ");
				choice = in.nextInt();
				if(choice == 1) {
					String name;
					int population;
					System.out.print("Input virus name: ");
					in.nextLine();
					name = in.nextLine();
					System.out.print("Input population number: ");
					population = in.nextInt();
					virusList.add(new SimpleVirus(name,population));
					System.out.println("Simple virus successfully added!\n");
				}
				else if(choice == 2) {
					printVirusList(virusList);
					String drug;
					int idx;
					System.out.print("Input index of simple virus for experiment: ");
					
					idx = in.nextInt();
					in.nextLine();
					System.out.print("Input drug name: ");
					drug = in.nextLine();
					
					SimpleVirus virus = virusList.get(idx);
					virusList.remove(idx);
					if(experiment()) {
						resistantList.add(new ResistantVirus(virus.getName(),virus.getPopulation(),drug));
					}				
				}
				else if(choice == 3) {
					printVirusList(resistantList);
					System.out.println("");
				}
			}while(choice != 4);
		}
	}

}
