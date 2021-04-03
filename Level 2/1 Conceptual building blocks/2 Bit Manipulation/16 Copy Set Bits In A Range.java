import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args){
    Scanner scn = new Scanner(System.in);
    int a = scn.nextInt();
    int b = scn.nextInt();
    int left = scn.nextInt();
    int right = scn.nextInt();

   scn.close();

   int m1 = (1 << (right - left + 1)) - 1;
   m1 <<= (left - 1);

   m1 &= a;
   b |= m1;

   System.out.println(b);
  }

}