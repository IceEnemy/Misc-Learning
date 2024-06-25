import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		Bicycle bike = new Bicycle(210,BicycleType.CONVENTIONAL);
		
		System.out.println("bike CO2 emissions: " + bike.getCarbonFootprint());
		
		Car vroom = new Car(510,FuelType.DIESEL);
		
		System.out.println("vroom CO2 emissions: " + vroom.getCarbonFootprint());
		
		Building hom = new Building(20.3,10.3,16.7,12);
		
		System.out.println("hom CO2 emissions: " + hom.getCarbonFootprint());
		
		// if i were to add new classes such as the Motorcycle or Airplane, it would be pretty simple. All i have to do is to make the new classes and make them implement the CarbonFootprint.
		// There would be no need to change anything in Main or other classes, except for maybe initializing new Motorcycle() or new Airplane()
		
		ArrayList<CarbonFootprint> carbonEmittors= new ArrayList<CarbonFootprint>();
		
		
		carbonEmittors.add(bike);
		carbonEmittors.add(vroom);
		carbonEmittors.add(hom);
		carbonEmittors.add(new Bicycle(10,BicycleType.E_CYCLE));
		carbonEmittors.add(new Car(1000,FuelType.GASOLINE));
		
		for(CarbonFootprint cE : carbonEmittors) {
			System.out.println("Carbon Footprint: " + cE.getCarbonFootprint());
		}
	}

}
