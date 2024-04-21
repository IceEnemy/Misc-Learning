package menuItems;

public class RegularMenu {
	protected String code, name;
	protected int price;
	
	public RegularMenu(String code, String name, int price) {
		
		this.code = code;
		this.name = name;
		this.price = price;
	}
	
	public String getCode() {
		return code;
	}
	
	public void setCode(String code) {
		this.code = code;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public int getPrice() {
		return price;
	}
	
	public void setPrice(int price) {
		this.price = price;
	}
	
	public void toTableFormat() {
		System.out.printf(" %6s | %20s | %10d |",code,name,price);
	}
	
}
