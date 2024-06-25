//import ja

public class Main {

	public static void main(String[] args) {
		Rectangle rect = new Rectangle(3);
		
		rect.draw();
		
		System.out.println("Area: " + rect.computeArea());
		System.out.println();
		Triangle tri = new Triangle(10);
		
		tri.draw();
		
		System.out.println("Area: " + tri.computeArea());
		System.out.println();
		
//		ArrayList<Shape> shapeList = new ArrayList<Shape>();
		
		Menu menu = new Menu();
		
		shapeManager shapeList = new shapeManager();
		
//		try (Scanner sc = new Scanner(System.in)) {
			int choice;
			
			do {
				menu.display();
				
				choice = menu.inputChoice();
				
				if(choice == MenuOption.ADD_RECTANGLE) {
//					Shape sh = new Rectangle(5);
//					sh.draw();
					int size = menu.inputSize();
					
					shapeList.addShape(new Rectangle(size));
				}
				else if(choice == MenuOption.ADD_TRIANGLE) {
//					Shape sh = new Triangle(4);
//					sh.draw();
					int size = menu.inputSize();
					
					shapeList.addShape(new Triangle(size));
				}
				else if(choice == MenuOption.DRAW_ALL_SHAPES) {
					shapeList.drawAllShape();
				}
				System.out.println();
			}while(choice != MenuOption.EXIT);
//		}

	}

}
