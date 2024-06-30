
public abstract class PaymentMethod {
	double amount, admin;
	public PaymentMethod(double amount) {
		this.amount = amount;
	}
	public double getAmount() {
		return amount;
	}
	public double getAdmin() {
		return admin;
	}
	public abstract String getMethod();
}
