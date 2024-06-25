
public abstract class Shape {
	int size;
	
	
	
	public Shape(int size) {
		this.size = size;
	}
	
	public abstract void draw();
	abstract public int computeArea();
	
	public String toString() {
		return this.getClass().getSimpleName() + " size: " + size + ", " + "Area: " + computeArea() + "\n";
	}
}
