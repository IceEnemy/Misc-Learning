
public abstract class Animals {
	Integer points;
	String name;
	
	Animals(String name, Integer points){
		this.name = name;
		this.points = points;
	}
	
	abstract void makeSound();
	
	public int getPoints() {
		return this.points;
	}

	public String getName() {
		return name;
	}
	
	
}
