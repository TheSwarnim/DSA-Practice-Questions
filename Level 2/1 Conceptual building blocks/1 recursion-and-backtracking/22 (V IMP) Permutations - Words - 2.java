import java.io.*;
import java.util.*;

public class Main {
  public static void display(Character[] spots) {
    for (Character ch : spots) {
        System.out.print(ch);
    }
    System.out.println();
  }

  public static void generateWords(int cc, String str, Character[] spots, HashMap<Character, Integer> lastOccurence) {
    // base case
    if(cc == str.length()) {
        display(spots);

        return;
    }

    char ch = str.charAt(cc);
    int lstOcc = lastOccurence.get(ch);
    for (int i = lstOcc + 1; i < spots.length; i++) {
        if(spots[i] == null) {
            spots[i] = ch;
            lastOccurence.put(ch, i);

            generateWords(cc + 1, str, spots, lastOccurence);

            spots[i] = null;
            lastOccurence.put(ch, lstOcc);
        }
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = br.readLine();

    Character[] spots = new Character[str.length()];
    HashMap<Character, Integer> lastOccurence = new HashMap<>();
    for(char ch: str.toCharArray()){
      lastOccurence.put(ch, -1);
    }

    generateWords(0, str, spots, lastOccurence);
  }

}