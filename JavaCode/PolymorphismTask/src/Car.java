
public class Car implements CarbonFootprint{
	private double gallon_consumed;
	private FuelType fuel;
	
	public Car(double gallon_consumed, FuelType fuel) {
		this.gallon_consumed = gallon_consumed;
		this.fuel = fuel;
	}

	public String getCarbonFootprint() {
		double footprint = gallon_consumed * fuel.getEmissionFactor();
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
