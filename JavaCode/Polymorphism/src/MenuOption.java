
public interface MenuOption {
	int ADD_RECTANGLE = 1;
	int ADD_TRIANGLE = 2;
	int DRAW_ALL_SHAPES = 3;
	int EXIT = 4;
	
	void display();
	int inputSize();
	int inputChoice();
	
	// default is public static final
}
