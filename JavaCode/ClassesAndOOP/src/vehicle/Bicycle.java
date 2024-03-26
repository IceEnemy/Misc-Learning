package vehicle;

public class Bicycle {
	protected String type;

	public Bicycle() {
		type = "Mountain Bike";
	}
	
	public void testAccess() {
Car car = new Car();
		
		System.out.println(car.color);
		System.out.println(car.brand);
		System.out.println(car.getSpeed());
	}
	
}
