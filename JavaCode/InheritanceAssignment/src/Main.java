
public class Main {

	public static void main(String[] args) {
		Person pep = new Person("John","Belevue","911","john@gmail.com");
		System.out.println(pep.toString());

		
		Student pep2 = new Student("Jane","Belevue","199","jane@gmail.com",ClassStatus.Freshman);
		System.out.println(pep2.toString());
		
		Employee pep3 = new Employee("Jim","Seattle","199231","jim@gmail.com","Google",21901.22,new MyDate(15,2,2023));
		System.out.println(pep3.toString());
		System.out.println("Date Hired: " + pep3.getDate_hired().fullDate() + "\n");
		
		Faculty pep4 = new Faculty("Jam","Toronto","0239232","jam@gmail.com","FAANG",32312.66,new MyDate(10,12,2020), 40, "Senior");
		System.out.println(pep4.toString());
		
		Staff pep5 = new Staff("Jill","Vancouver","1290110128","jill@gmail.com","Umbrella",120000.00,new MyDate(7,3,2001), "Tester");
		System.out.println(pep5.toString());
	}

}
