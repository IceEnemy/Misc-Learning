package Objects;

public class Person {
	private String name;
	private Cat cat; //aggregation (if the person doesn't exist, cat can still exist)
	private FakeTeeth fakeTeeth; //composition (if the person doesn't exist, the teeth doesn't exist)

	public Person(String name) {
		this.name = name;
		fakeTeeth = new FakeTeeth(6);
	}
	
	public Person(String name, Cat cat) {
		this.name = name;
		this.cat = cat;
		fakeTeeth = new FakeTeeth(6);
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	public String getCatName() {
		if(cat != null) {
			return cat.getName();
		}
		else {
			return name + " has no cat!";
		}
	}
	
	public int getNumberofTakeTeeth() {
		return fakeTeeth.getNumberofTeeth();
	}
	
	public void tameCat(Cat cat) {
		this.cat = cat;
	}
	
	public void disownCat() {
		this.cat = null;
	}
	
}
