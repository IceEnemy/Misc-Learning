import java.util.ArrayList;

public class hunterScore {
	
	ArrayList<Hunter> hunt;
	
	public hunterScore(ArrayList<Hunter> hunt) {
		this.hunt = hunt;
	}



	public void calculateScore() {
		for(Hunter h: hunt) {
			Integer total = 0;
			System.out.println("Calculating " + h.getName() + "\'s score:");
			for(Integer score : h.getScores()) {
				System.out.println(score);
				total += score;
			}
			System.out.println("Total score = " + total);
			System.out.println();
		}
		
	}
}
