package Objects;

public class Main {

	public static void main(String[] args) {
//		Circle c1 = new Circle(7);
//		System.out.println("number of objects: " + c1.getNumberofObject());
//		System.out.println("c1 Radius: " + c1.getRadius());
//		
//		Circle c2 = new Circle(3);
//		
//		Circle c3 = new Circle(1);
//		
//		System.out.println("Number of objects: " + c2.getNumberofObject());
//		
//		System.out.println("call static method: " + Circle.getNumberofObject());
//		
////		Circle.setRadius --> this is not possible because this is not a static reference
//		
//		TestAddingObject testAdd = new TestAddingObject();
//		
//		System.out.println("After the testAdd: " + Circle.getNumberofObject());
		
//		testOverloading test = new testOverloading();
//		System.out.println("No Params: " + test.calculate());
//		System.out.println("1 Param: " + test.calculate(5));
//		System.out.println("2 Params: " + test.calculate(9,10));
//		System.out.println("String: " + test.calculate("Hello"));
//		System.out.println("String a, int b: " + test.calculate("Hello", 3));
//		System.out.println("int b, String a: " + test.calculate(5, "Hello"));
		
		Cat cat = new Cat("Whiskers");
		Person person = new Person("Dan", cat);
		
		System.out.println("Person's name: " + person.getName());
		System.out.println("Person's cat's name: " + person.getCatName());
		System.out.println("Amount of " + person.getName() +"\'s Fake Teeth: " + person.getNumberofTakeTeeth());
		
		Person per1 = new Person("Bob");
		System.out.println("Person's name: " + per1.getName());
		System.out.println("Person's cat's name: " + per1.getCatName());
		System.out.println("Amount of " + per1.getName() +"\'s Fake Teeth: " + per1.getNumberofTakeTeeth());
		
		Cat cat2 = new Cat("Miumiw");
		
		per1.tameCat(cat2);
		System.out.println("Person's cat's name: " + per1.getCatName());
		
		per1.disownCat();
		System.out.println("Person's cat's name: " + per1.getCatName());
		System.out.println("The cat that got disowned: " + cat2.getName() );
		
		
	}

}
