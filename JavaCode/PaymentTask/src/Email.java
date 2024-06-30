
public class Email extends Communication {

	public Email(String job, PaymentMethod method) {
		super(job, method);
		
	}

	@Override
	public void sendInvoice() {
		System.out.println("Title: Invoice JasaTukang.com ID #" + this.id);
		
		System.out.println("Body:");
		System.out.println("Yth. Konsumen,");
		System.out.println("Berikut ini adalah invoice dari transaksi anda pada JasaTukang.com.");
		System.out.println("Pekerjaan : " + this.job);
		System.out.printf("Nominal : Rp. %.2f\n", this.method.getAmount());
		System.out.println("Metode Pembayaran : " + this.method.getMethod());
		System.out.printf("Biaya Administrasi : Rp. %.2f\n", this.method.getAdmin());
		
		System.out.println("\nMasa garansi jasa adalah 30 hari terhitung setelah invoice ini dibuat.\n");
		System.out.println("Terima kasih telah menggunakan jasa kami.");

	}

}
