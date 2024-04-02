package Vehicles;

//public final class bicycle, can't have any subclasses
// final method also cannot be overridden 

public class Bicycle {
	protected int gear, speed;

	public Bicycle(int gear, int speed) {
		this.gear = gear;
		this.speed = speed;
	}

	public int getGear() {
		return gear;
	}

	public void setGear(int gear) {
		this.gear = gear;
	}

	public int getSpeed() {
		return speed;
	}

	public void setSpeed(int speed) {
		this.speed = speed;
	}
	
	public void applyBrake(int decrement) {
		speed -= decrement;
	}
	
	public void speedUp(int increment) {
		speed += increment;
	}
	
	public String toString() {
		return "speed: " + speed + "\n" + "gear: " + gear + "\n";
	}
	
}
