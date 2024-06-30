
public class QRIS extends PaymentMethod {

	public QRIS(double amount) {
		super(amount);
		this.admin = 0;
	}

	@Override
	public String getMethod() {
		return "QRIS";
	}

}
