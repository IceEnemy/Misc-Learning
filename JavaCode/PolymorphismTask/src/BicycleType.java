
public enum BicycleType {
	E_CYCLE(14.8),
	CONVENTIONAL(21.0);
	
	private final double emmisionFactor;

	private BicycleType(double emmisionFactor) {
		this.emmisionFactor = emmisionFactor;
	}
	
	public double getEmissionFactor() {
		return emmisionFactor;
	}
}
