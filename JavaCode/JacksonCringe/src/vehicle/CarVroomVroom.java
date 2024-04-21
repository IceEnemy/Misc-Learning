package vehicle;

public class CarVroomVroom {
	private int fuel, hp, ArkDinosaurPower;

	public int getFuel() {
		return fuel;
	}

	public void setFuel(int fuel) {
		this.fuel = fuel;
	}

	public int getHp() {
		return hp;
	}

	public void setHp(int hp) {
		this.hp = hp;
	}

	public int getArkDinosaurPower() {
		return ArkDinosaurPower;
	}

	public void setArkDinosaurPower(int arkDinosaurPower) {
		ArkDinosaurPower = arkDinosaurPower;
	}

	public CarVroomVroom(int fuel, int hp, int arkDinosaurPower) {
		this.fuel = fuel;
		this.hp = hp;
		ArkDinosaurPower = arkDinosaurPower;
	}
	
	
	
}
