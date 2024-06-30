
public class BankTransfer extends PaymentMethod {

	public BankTransfer(double amount) {
		super(amount);
		this.admin = 2000;
	}

	@Override
	public String getMethod() {
		return "Bank Transfer";
	}

}
