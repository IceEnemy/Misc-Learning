package Vehicles;

public class MountainBike extends Bicycle {
	private int seatHeight;
	//

	public MountainBike(int gear, int speed, int seatHeight) {
		super(gear, speed); //calling bicycle constructor
		this.seatHeight = seatHeight;
	}

	public int getSeatHeight() {
		return seatHeight;
	}

	public void setSeatHeight(int seatHeight) {
		this.seatHeight = seatHeight;
	}
	
	public String toString() {
		return super.toString() + "seatHeight: " + seatHeight + "\n";
	}
	
}
