
public class ResistantVirus extends SimpleVirus {
	private String drug;

	public String getDrug() {
		return drug;
	}

	public void setDrug(String drug) {
		this.drug = drug;
	}

	public ResistantVirus(String name, int population, String drug) {
		super(name, population);
		this.drug = drug;
	}
	
	@Override
	public String toString() {
		return super.toString() + " " + drug;
	}
}
