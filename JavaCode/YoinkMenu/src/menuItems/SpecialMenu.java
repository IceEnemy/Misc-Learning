package menuItems;

public class SpecialMenu extends RegularMenu{
	private double discount;

	public SpecialMenu(String code, String name, int price, double discount) {
		super(code, name, price);
		this.discount = discount;
	}

	public double getDiscount() {
		return discount;
	}

	public void setDiscount(double discount) {
		this.discount = discount;
	}
	
	@Override
	public void toTableFormat() {
		super.toTableFormat();
		System.out.printf(" %8.2f |",discount);
	}

}
