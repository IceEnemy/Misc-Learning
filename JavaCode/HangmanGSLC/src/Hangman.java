import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Hangman{
	final String WORDLIST_FILENAME = "words.txt";

	public Hangman(){
		ArrayList<String> wordList = loadWords();
		String secretWord = chooseWord(wordList).toLowerCase();
		startGame(secretWord);
	}
	
	/**
	 * Returns a list of valid words. Words are strings of lowercase letters.
	 * Depending on the size of the word list, this function may
	 * take a while to finish.
	 */
	ArrayList<String> loadWords(){
		ArrayList<String> wordList = new ArrayList<>(55909);
		System.out.println("Loading word list from file...");
		try{
			Scanner input = new Scanner(new File(WORDLIST_FILENAME));
			while(input.hasNext()){
				wordList.add(input.next());
			}
			input.close();
		}
		catch(FileNotFoundException ex){
            System.out.println("File not found");
        }
		System.out.println(wordList.size() + " " + "words loaded.");
		
		return wordList;
	}
	
	/**
	 * wordlist (list): list of words (strings)
	 * Returns a word from wordlist at random
	 */
	String chooseWord(ArrayList<String> wordList){
		//FILL IN YOUR CODE HERE...
		Random random = new Random();
		int index = random.nextInt(wordList.size());
		String chosenWord = wordList.get(index);
		return chosenWord;
		
	}
	
	/**
	 * secretWord: string, the word the user is guessing
	 * lettersGuessed: list, what letters have been guessed so far
	 * returns: boolean, True if all the letters of secretWord are in lettersGuessed;
	 * False otherwise
	 */
	 boolean isWordGuessed(String secretWord, ArrayList<Character> lettersGuessed){
		 //FILL IN YOUR CODE HERE...
		 for(int i = 0; i<secretWord.length(); i++){
			 if(!lettersGuessed.contains(secretWord.charAt(i))){
				 return false;
			 }
		 }
		 return true;
	 }
	 
	 /**
	  * secretWord: string, the word the user is guessing
	  * lettersGuessed: list, what letters have been guessed so far
	  * returns: string, comprised of letters and underscores that represents
	  * what letters in secretWord have been guessed so far.
      */
	 String getGuessedWord(String secretWord, ArrayList<Character> lettersGuessed){
		 //FILL IN YOUR CODE HERE...
		String wordGuess = "";
		for(int i=0; i<secretWord.length(); i++){
			char currChar = secretWord.charAt(i);
			if(lettersGuessed.contains(currChar)){
				wordGuess += currChar;
			}
			else{
				wordGuess += "_ ";
			}
		}
		return wordGuess.trim();
	 }
	 
	 /**
	  * lettersGuessed: list, what letters have been guessed so far
	  * returns: string, comprised of letters that represents what letters have not
	  * yet been guessed.
	  */
	 String getAvailableLetters(ArrayList<Character> lettersGuessed){
		 //FILL IN YOUR CODE HERE...
		 String available = "abcdefghijklmnopqrstuvwxyz";
		 for (Character letter : lettersGuessed) {
	            available = available.replace(letter.toString(), "");
	     }
		 return available;
	 }
	
	/**
	 * secretWord: string, the secret word to guess.
	 * 
	 * Starts up an interactive game of Hangman.
	 * 
	 * At the start of the game, let the user know how many 
	 * letters the secretWord contains.
	 * 
	 * Ask the user to supply one guess (i.e. letter) per round.
	 * 
	 * The user should receive feedback immediately after each guess 
	 * about whether their guess appears in the computers word.
	 * 
	 * After each round, you should also display to the user the 
	 * partially guessed word so far, as well as letters that the 
	 * user has not yet guessed.
	 * 
	 * Follows the other limitations detailed in the problem write-up.
	 */
	 void startGame(String secretWord){
		 //FILL IN YOUR CODE HERE...
		 System.out.println("Welcome to the game Hangman!");
		 System.out.println("I'm Thinking of a word that is " + secretWord.length() + " letters long.");
		 System.out.println("-----------");
		 
		 int lives = 8;
		 
		 boolean won = false;
		 
		 ArrayList<Character> lettersGuessed = new ArrayList<Character>();
		 
		 try (Scanner in = new Scanner(System.in)) {
			while(lives > 0 && won == false) {
				 System.out.println("You have " + lives + " guesses left.");
				 System.out.println("Available Letters: " + getAvailableLetters(lettersGuessed));
				 boolean gs = false;
				 Character a = null;
				 while(gs == false) {
					 System.out.print("Please guess a letter: ");
					 String inp = in.nextLine();
					 if(inp.isEmpty()) {
						 System.out.println("You didn't input anything!");
						 continue;
					 }
					 inp = inp.toLowerCase();
					 a = inp.charAt(0);
					 if(lettersGuessed.contains(a)) {
						 System.out.println("You already guessed \"" + a + "\"!");
					 }
					 else if(a < 'a' || a > 'z') {
						 System.out.println("Invalid input!");
					 }
					 else {
						 gs = true;
					 }
				 }
				 lettersGuessed.add(a);
				 if(secretWord.contains(a.toString())) {
					 System.out.println("Good guess: " + getGuessedWord(secretWord, lettersGuessed));
				 }
				 else {
					 System.out.println("Oops! That letter is not in my word: " + getGuessedWord(secretWord, lettersGuessed));
					 lives--;
				 }
				 
				 if(isWordGuessed(secretWord, lettersGuessed)) {
					 won = true;
				 }
				 System.out.println("-----------");
			 }
		}
		 
		 if(won) {
			 System.out.println("Congratulations, you won!");
		 }
		 else {
			 System.out.println("Sorry, you ran out of guesses. The word was " + secretWord);
		 }
		 
		 

	 }
	 
	 public static void main(String[] args){
		Hangman hangman = new Hangman();
	 }
}
