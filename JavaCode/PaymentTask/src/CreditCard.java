
public class CreditCard extends PaymentMethod {

	public CreditCard(double amount) {
		super(amount);
		this.admin = amount*3/100;
	}

	@Override
	public String getMethod() {
		return "Credit Card";
	}
	
	

}
