
public class Rectangle extends Shape {

	
	
	public Rectangle(int size) {
		super(size);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void draw() {
		for(int i=1; i<=size; i++) {
			for(int j=1; j<=size; j++) {
				System.out.print('*');
			}
			System.out.println();
		}

	}

	@Override
	public int computeArea() {	
		return size*size;
	}

}
