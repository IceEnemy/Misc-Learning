public class Student extends Person {
	private final ClassStatus class_status;

	public Student(String name, String address, String phone_number, String email_address, ClassStatus class_status) {
		super(name, address, phone_number, email_address);
		this.class_status = class_status;
	}

	public ClassStatus getClass_status() {
		return class_status;
	}
	
	@Override
    public String toString() {
        return super.toString() + "Class Status: " + this.class_status + "\n";
    }
	
	
}
