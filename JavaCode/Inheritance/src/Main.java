import Vehicles.Bicycle;
import Vehicles.MountainBike;

public class Main {

	public static void main(String[] args) {
		Circle circle = new Circle(10);
		circle.setColor("Red");
		System.out.println("Circle Color: " + circle.getColor());
		System.out.println("Circle area: " + circle.getArea());
		
		Rectangle rect = new Rectangle();
		rect.setWidth(4);
		rect.setHeight(6);
		System.out.println("Rectangle Area: " + rect.getArea());
		
		System.out.println("Test Parent Area from circle: " + circle.getParentArea(5, 2));
		
		Bicycle bike = new Bicycle(5,10);
		System.out.println("Bicycle Speed: " + bike.getSpeed());
		System.out.println("Bicycle Gear: " + bike.getGear());
		
		MountainBike mbike = new MountainBike(3,4,5);
		
		System.out.println(bike.toString());
		System.out.println(mbike.toString());
		
	}

}
