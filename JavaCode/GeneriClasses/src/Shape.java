
public abstract class Shape {
	int height, width;

	public Shape(int height, int width) {
		this.height = height;
		this.width = width;
	}
	
	abstract public int getArea();
}
