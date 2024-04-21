
public class Employee extends Person{
	private String office;
	private double salary;
	private MyDate date_hired;
	
	public Employee(String name, String address, String phone_number, String email_address, String office,
			double salary, MyDate date_hired) {
		super(name, address, phone_number, email_address);
		this.office = office;
		this.salary = salary;
		this.date_hired = date_hired;
	}

	public String getOffice() {
		return office;
	}

	public void setOffice(String office) {
		this.office = office;
	}

	public double getSalary() {
		return salary;
	}

	public void setSalary(double salary) {
		this.salary = salary;
	}

	public MyDate getDate_hired() {
		return date_hired;
	}

	public void setDate_hired(MyDate date_hired) {
		this.date_hired = date_hired;
	}
	
	@Override
	public String toString() {
		return super.toString() + "Office: " + this.office + "\n";
	}
	
}
