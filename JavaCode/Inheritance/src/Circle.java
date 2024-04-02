
public class Circle extends GeometricObject {
	//any protected and public member will be inherited from the superclass
	private double radius;
	
	
	
	public Circle(double radius) {
		this.radius = radius;
	}

	public double getRadius() {
		return radius;
	}



	public void setRadius(double radius) {
		this.radius = radius;
	}



	@Override
	public double getArea() {
		return Math.PI * radius * radius; //diff behaviour
	}
	
	public double getParentArea(double h, double w) {
		setHeight(h);
		setWidth(w);
		return super.getArea();
	}
	
}
