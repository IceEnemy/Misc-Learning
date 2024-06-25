
public class Building implements CarbonFootprint{
	private double monthly_electric_bill, monthly_gas_bill, monthly_oil_bill, months_owned;

	public Building(double monthly_electric_bill, double monthly_gas_bill, double monthly_oil_bill,
			double months_owned) {
		this.monthly_electric_bill = monthly_electric_bill;
		this.monthly_gas_bill = monthly_gas_bill;
		this.monthly_oil_bill = monthly_oil_bill;
		this.months_owned = months_owned;
	}
	
	public String getCarbonFootprint() {
		double footprint = (monthly_electric_bill * 47627.2) + (monthly_gas_bill * 47627.2) + (monthly_oil_bill * 51255.9) * months_owned;
		if(footprint < 1000) {
			return footprint + " g";
		}
		else if(footprint < 1000000) {
			return footprint/1000 + " kg";
		}
		else {
			return footprint/1000000 + " metric tons";
		}
	}
}
