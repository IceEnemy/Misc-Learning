package Objects;

public class Circle {
	private double radius;
	
	private static int numberofObject = 0;
	
	public static int getNumberofObject() { //static means global variable or function i guess?
		return numberofObject;
	}
	
	public static void addNumberofObject() {
		numberofObject++;
	}
	
	public Circle(double radius) {
		this.setRadius(radius);
		numberofObject++;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}
}
