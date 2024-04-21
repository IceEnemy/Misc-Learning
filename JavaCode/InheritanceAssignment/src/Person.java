
public class Person {
	protected String name, address, phone_number, email_address;

	public Person(String name, String address, String phone_number, String email_address) {
		this.name = name;
		this.address = address;
		this.phone_number = phone_number;
		this.email_address = email_address;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public String getPhone_number() {
		return phone_number;
	}

	public void setPhone_number(String phone_number) {
		this.phone_number = phone_number;
	}

	public String getEmail_address() {
		return email_address;
	}

	public void setEmail_address(String email_address) {
		this.email_address = email_address;
	}
	
	public String toString() {
        return "Class: " + this.getClass().getSimpleName() + "\nName: " + name + "\n";
    }
	
}
