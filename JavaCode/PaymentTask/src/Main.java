import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		
		try (Scanner sc = new Scanner(System.in)) {
			int init;
			
			do {
				System.out.println("Proceed with payment?");
				System.out.println("1. Yes");
				System.out.println("2. No");
				
				init = sc.nextInt();
				sc.nextLine();
				
				if(init == 1) {
					
					System.out.print("Job: ");
					String job = sc.nextLine();
					
					System.out.print("Nominal: ");
					double nominal = sc.nextDouble();
					sc.nextLine();
					
					
					System.out.println("Select Payment Method:");
			        System.out.println("1. Bank Transfer");
			        System.out.println("2. Credit Card");
			        System.out.println("3. QRIS");
			        
			        int methodChoice = sc.nextInt();
			        sc.nextLine();
					
					PaymentMethod payment = null;
					switch(methodChoice) {
						case 1:
							payment = new BankTransfer(nominal);
							break;
						case 2:
							payment = new CreditCard(nominal);
							break;
						case 3:
							payment = new QRIS(nominal);
							break;
					}
					System.out.println("Select Invoice Delivery Method:");
			        System.out.println("1. Email");
			        System.out.println("2. WhatsApp");
			        
			        int invoiceChoice = sc.nextInt();
			        Communication invoice = null;
			        sc.nextLine();
			        
			        switch(invoiceChoice) {
			        	case 1:
			        		invoice = new Email(job, payment);
			        		break;
			        	case 2:
			        		invoice = new WhatsApp(job, payment);
			        		break;
			        }
			        
			        invoice.sendInvoice();
				}
				
				
				
			}while(init != 2);
		}
	}

}
