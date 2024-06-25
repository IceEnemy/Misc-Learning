
public class Bicycle implements CarbonFootprint {
	private double km_traveled;
	private BicycleType type;

	
	public Bicycle(double km_traveled, BicycleType type) {
		this.km_traveled = km_traveled;
		this.type = type;
	}

	public String getCarbonFootprint() {
		double footprint = km_traveled * type.getEmissionFactor();
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
