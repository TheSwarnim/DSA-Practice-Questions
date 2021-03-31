import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args){
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();

    scn.close();

    int rsbm = n & -n;
    System.out.println(Integer.toBinaryString(rsbm));
  }

}