
import java.util.ArrayList;

public class shapeManager {
	ArrayList<Shape> shapeList = new ArrayList<Shape>();
	
	public void addShape(Shape sh) {
		shapeList.add(sh);
	}
	
	public void drawAllShape() {
		for(Shape shape : shapeList) {
			shape.draw();
//			System.out.println("Area: " + shape.computeArea());
			System.out.println(shape);
			System.out.println();
		}
	}
}
