
public class SimpleVirus {
	private String name;
	private int population;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getPopulation() {
		return population;
	}
	public void setPopulation(int population) {
		this.population = population;
	}
	public SimpleVirus(String name, int population) {
		this.name = name;
		this.population = population;
	}
	
	public String toString() {
		return name + " " + population;
	}
}
