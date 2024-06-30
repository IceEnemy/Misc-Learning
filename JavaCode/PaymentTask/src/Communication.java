
public abstract class Communication {
	static int idCount = 0;
	int id;
	String job;
	PaymentMethod method;
	public abstract void sendInvoice();
	public Communication(String job, PaymentMethod method) {
		this.job = job;
		this.method = method;
		incrementId();
		this.id = idCount;
	}
	public int getId() {
		return id;
	}
	public static void incrementId() {
		Communication.idCount++;
	}
	
}
