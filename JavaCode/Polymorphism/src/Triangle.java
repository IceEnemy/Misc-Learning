
public class Triangle extends Shape {

	public Triangle(int size) {
		super(size);
	}

	@Override
	public void draw() {
		for(int i=1; i<=size; i++) {
			for(int j=1; j<=i; j++) {
				System.out.print('*');
			}
			System.out.println();
		}

	}

	@Override
	public int computeArea() {
		return size*size/2;
	}

}
