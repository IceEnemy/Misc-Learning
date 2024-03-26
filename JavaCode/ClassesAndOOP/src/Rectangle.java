
public class Rectangle {
	int height, width; //when we have no access modifier, the default is package
	
	
	//constructor 
	//shortcut is alt+shift+S then press O
	
	public Rectangle(int height, int width) {
		this.height = height;
		this.width = width;
	}
	
	//draw rectangle
	
	public void draw() {
		for(int i=0; i<height; i++) {
			for(int j=0; j<width; j++) {
				if(j==0 || i==0 || i==height-1 || j==width-1) System.out.print("*");
				else System.out.print(" ");
			}
			System.out.println("");
		}
	}
	
	
}
