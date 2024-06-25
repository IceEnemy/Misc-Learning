
public enum FuelType {
	GASOLINE(8887),
	DIESEL(10180);
	
	private final double emmisionFactor;

	private FuelType(double emmisionFactor) {
		this.emmisionFactor = emmisionFactor;
	}
	
	public double getEmissionFactor() {
		return emmisionFactor;
	}
}
