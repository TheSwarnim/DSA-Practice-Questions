import java.io.*;
import java.util.*;

class Main {

	public static void solution(char[][] arr, String[] words, int vidx){
		if(vidx == words.length){
			print(arr);
			return;
		}

		String word = words[vidx];
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[0].length; j++) {
				if(arr[i][j] == '-' || arr[i][j] == word.charAt(0)){
					if(canPlaceHorizontal(arr, word, i, j)){
						boolean[] weCreated = placeWordHorizontal(arr, word, i, j);
						solution(arr, words, vidx + 1);
						removeWordHorizontal(arr, word, i, j, weCreated);
					}
	
					if(canPlaceVertical(arr, word, i, j)){
						boolean[] weCreated = placeWordVertical(arr, word, i, j);
						solution(arr, words, vidx + 1);
						removeWordVertical(arr, word, i, j, weCreated);
					}
				}
			}
		}
	}

	
	private static void removeWordVertical(char[][] arr, String word, int i, int j, boolean[] weCreated) {
		for (int ii = 0; ii < word.length(); ii++) {
			if(weCreated[ii]){
				arr[i + ii][j] = '-';
			}
		}
	}


	private static boolean[] placeWordVertical(char[][] arr, String word, int i, int j) {
		boolean[] wePlaced = new boolean[word.length()];
		
		for (int ii = 0; ii < word.length(); ii++) {
			if(arr[i + ii][j] == '-'){
				arr[i + ii][j] = word.charAt(ii);
				wePlaced[ii] = true;
			}
		}

		return wePlaced;
	}


	private static boolean canPlaceVertical(char[][] arr, String word, int i, int j) {
		if(i - 1 >= 0 && arr[i - 1][j] != '+'){
			return false;
		} else if(i + word.length() + 1 < arr.length && arr[i + word.length() + 1][j] != '+'){
			return false;
		} 

		for (int ii = 0; ii < word.length(); ii++) {
			if(i + ii >= arr[0].length){
				return false;
			}
			
			if(arr[i + ii][j] == '-' || arr[i + ii][j] == word.charAt(ii)){
				continue;
			} else{
				return false;
			}
		}

		return true;
	}


	private static void removeWordHorizontal(char[][] arr, String word, int i, int j, boolean[] weCreated) {
		for (int jj = 0; jj < word.length(); jj++) {
			if(weCreated[jj]){
				arr[i][j + jj] = '-';
			}
		}
	}


	private static boolean[] placeWordHorizontal(char[][] arr, String word, int i, int j) {
		boolean[] wePlaced = new boolean[word.length()];
		
		for (int jj = 0; jj < word.length(); jj++) {
			if(arr[i][j + jj] == '-'){
				arr[i][j + jj] = word.charAt(jj);
				wePlaced[jj] = true;
			}
		}

		return wePlaced;
	}


	private static boolean canPlaceHorizontal(char[][] arr, String word, int i, int j) {
		if(j - 1 >= 0 && arr[i][j - 1] != '+'){
			return false;
		} else if(j + word.length() + 1 < arr[0].length && arr[i][j + word.length() + 1] != '+'){
			return false;
		} 

		for (int jj = 0; jj < word.length(); jj++) {
			if(j + jj >= arr[0].length){
				return false;
			}
			
			if(arr[i][j + jj] == '-' || arr[i][j + jj] == word.charAt(jj)){
				continue;
			} else{
				return false;
			}
		}

		return true;
	}


	public static void print(char[][] arr){
		for(int i = 0 ; i < arr.length; i++){
			for(int j = 0 ; j < arr.length; j++){
				System.out.print(arr[i][j]);
			}
                  System.out.println();
		}
		
	}
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		char[][] arr = new char[10][10];
		for(int i = 0 ; i < arr.length; i++){
			String str = scn.next();
			arr[i] = str.toCharArray();
		}
		int n = scn.nextInt();
		String[] words = new String[n];
		for(int i = 0 ; i  < words.length; i++){
			words[i] = scn.next();
		}

		scn.close();
		solution(arr, words, 0);
	}
}