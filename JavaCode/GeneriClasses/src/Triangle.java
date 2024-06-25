
public class Triangle extends Shape {

	public Triangle(int height, int width) {
		super(height, width);
		// TODO Auto-generated constructor stub
	}

	@Override
	public int getArea() {
		
		return height*width/2;
	}

}
