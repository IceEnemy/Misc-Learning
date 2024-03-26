import java.util.ArrayList;
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

	}
	
	/**
	 * secretWord: string, the word the user is guessing
	 * lettersGuessed: list, what letters have been guessed so far
	 * returns: boolean, True if all the letters of secretWord are in lettersGuessed;
	 * False otherwise
	 */
	 boolean isWordGuessed(String secretWord, ArrayList<Character> lettersGuessed){
		 //FILL IN YOUR CODE HERE...

	 }
	 
	 /**
	  * secretWord: string, the word the user is guessing
	  * lettersGuessed: list, what letters have been guessed so far
	  * returns: string, comprised of letters and underscores that represents
	  * what letters in secretWord have been guessed so far.
      */
	 String getGuessedWord(String secretWord, ArrayList<Character> lettersGuessed){
		 //FILL IN YOUR CODE HERE...

	 }
	 
	 /**
	  * lettersGuessed: list, what letters have been guessed so far
	  * returns: string, comprised of letters that represents what letters have not
	  * yet been guessed.
	  */
	 String getAvailableLetters(ArrayList<Character> lettersGuessed){
		 //FILL IN YOUR CODE HERE...

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

	 }
	 
	 public static void main(String[] args){
		Hangman hangman = new Hangman();
	 }
}
