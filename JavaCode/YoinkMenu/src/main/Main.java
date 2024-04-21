package main;

import java.util.ArrayList;
import java.util.Scanner;

import menuItems.RegularMenu;
import menuItems.SpecialMenu;

public class Main {
	
	static RegularMenu getInfo(int type, Scanner in) {
		String code, name;
		int price;
		System.out.print("input menu code: ");
		code = in.nextLine();
		System.out.print("input menu name: ");
		name = in.nextLine();
		System.out.print("Input menu price: ");
		price = in.nextInt();
		in.nextLine();
		if(type == 1) {
			return new RegularMenu(code, name, price);
		}
		else {
			System.out.print("input menu discount: ");
			double discount = in.nextDouble();
			in.nextLine();
			return new SpecialMenu(code,name,price,discount);
		}
	}
	
	static int getIdx(ArrayList<?extends RegularMenu> list, String code) {
		int size = list.size();
		int idx;
		for(int i=0; i<size; i++) {
			if(list.get(i).getCode().equals(code)) {
				return i;
			}
		}
		
		System.out.println("not found");
		return -1;
	}

	public static void main(String[] args) {
		ArrayList<RegularMenu> regularMenus = new ArrayList<RegularMenu>();
		ArrayList<SpecialMenu> specialMenus = new ArrayList<SpecialMenu>();
		
		regularMenus.add(new RegularMenu("R20","hehe",300));
		regularMenus.add(new RegularMenu("R31","meow",450));
		regularMenus.add(new RegularMenu("R44","wah",600));
		
		specialMenus.add(new SpecialMenu("S20","yey",5000,20));
		specialMenus.add(new SpecialMenu("S92","Miaw",2000,100));
		specialMenus.add(new SpecialMenu("S101","Spec",300000,50));
		
		int choice;
		try (Scanner in = new Scanner(System.in)) {
			do {
				System.out.println("Family Restaurant");
				System.out.println("---------------------------------");
				System.out.println("1. Add Regular Menu");
				System.out.println("2. Add Special Menu");
				System.out.println("3. Show All Menu");
				System.out.println("4. Delete Regular Menu");
				System.out.println("5. Delete Special Menu");
				System.out.println("6. Exit");
				System.out.print("Choice: ");
				choice = in.nextInt();
				in.nextLine();
				if(choice == 1 || choice == 2) {
					RegularMenu menu = getInfo(choice,in);
					if(menu instanceof SpecialMenu) {
						specialMenus.add((SpecialMenu) menu);
					}
					else {
						regularMenus.add(menu);
					}
				}
				else if(choice == 3) {
					System.out.println("");
					System.out.println("====================================================");
					System.out.printf("| %-3s | %-6s | %-20s | %-10s |\n","No.", "Code", "Name", "Price");
					System.out.println("====================================================");
					
					int regularSize = regularMenus.size();
					int specialSize = specialMenus.size();
					
					for(int i=0; i<regularSize; i++) {
						RegularMenu item = regularMenus.get(i);
						System.out.printf("| %3d |", i+1);
						item.toTableFormat();
						System.out.println("");
					}
					System.out.println("====================================================");
					
					System.out.println("");
					System.out.println("===============================================================");
					System.out.printf("| %-3s | %-6s | %-20s | %-10s | %-8s |\n","No.", "Code", "Name", "Price", "Discount");
					System.out.println("===============================================================");
					
					for(int i=0; i<specialSize; i++) {
						SpecialMenu item = specialMenus.get(i);
						System.out.printf("| %3d |", i+1);
						item.toTableFormat();
						System.out.println("");
					}
					System.out.println("===============================================================");
					System.out.println("Press Enter to continue..");
					in.nextLine();
				}
				else if(choice == 4 || choice == 5) {
					System.out.print("input menu code: ");
					String code = in.nextLine();
					int idx;
					if(choice == 4) {
						idx = getIdx(regularMenus,code);
						if(idx != -1) regularMenus.remove(idx);
					}
					else{
						idx = getIdx(specialMenus,code);
						if(idx != -1) specialMenus.remove(idx);
					}
				}
			}while(choice != 6);
		}
		

	}

}
