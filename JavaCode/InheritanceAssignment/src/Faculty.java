
public class Faculty extends Employee{
	private int hours;
	private String rank;
	public Faculty(String name, String address, String phone_number, String email_address, String office, double salary,
			MyDate date_hired, int hours, String rank) {
		super(name, address, phone_number, email_address, office, salary, date_hired);
		this.hours = hours;
		this.rank = rank;
	}
	public int getHours() {
		return hours;
	}
	public void setHours(int hours) {
		this.hours = hours;
	}
	public String getRank() {
		return rank;
	}
	public void setRank(String rank) {
		this.rank = rank;
	}
	
	@Override
	public String toString() {
		return super.toString() + "Rank: " + rank + "\n";
	}
}
