package vehicle;

public class Car {
	String brand; //no modifier means that it will only be visible in the same package
	private int speed;
	public String color;

	public Car() {
		brand = "Porche";
		speed = 100;
		color = "Red";
	}

	public int getSpeed() {
		return speed;
	}

	public String getBrand() {
		return brand;
	}
	
	
}
