import vehicle.Car;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Circle circleObject = new Circle();
		circleObject.setRadius(14);
		System.out.println("Circle Radius " + circleObject.getRadius());
		System.out.println("Circle Area " + circleObject.getArea());
		
		Rectangle rectangleObject = new Rectangle(4,12);
		rectangleObject.draw();
		
		Car car = new Car();
		
		System.out.println(car.color);
		System.out.println(car.getBrand());
		System.out.println(car.getSpeed());
		
		vehicle.Bicycle bicycle = new vehicle.Bicycle();
		bicycle.testAccess();
	}

}
