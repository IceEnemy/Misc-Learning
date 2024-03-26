
public class Circle {
	private double radius; //private means access is limited only to this class
	
	//set and get functions to access private attributes (shortcut = alt+shift+S then press R
	
	//default constructor = empty constructor
	//used to initialize objects with certain values
	//public Circle() { }

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}

	public double getArea() {
		return Math.PI * radius * radius;
	}
	
	
	
	
}
