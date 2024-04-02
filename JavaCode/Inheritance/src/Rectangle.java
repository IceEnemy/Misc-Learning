
public class Rectangle extends GeometricObject {
	public void zoomSize() {
//		height *= 2;
//		width *= 2;
		double h = getHeight();
		double w = getWidth();
		setHeight(h);
		setWidth(w);
	}
}
