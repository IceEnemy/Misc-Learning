import java.util.ArrayList;

public class Hunter {
	String name;
	ArrayList<Integer> scores = new ArrayList<Integer>();
	
	public Hunter(String name) {
		this.name = name;
	} 
	
	public String getName() {
		return name;
	}

	public void addScore(Integer score) {
		this.scores.add(score);
	}
	
	public ArrayList<Integer> getScores() {
		return scores;
	}
}
