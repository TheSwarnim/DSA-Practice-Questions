import java.io.*;
import java.util.*;

public class Main {

    public static int getRev(int n) {
      int rev = 0;

      while (n != 0){
        int lb = (n & 1);
        rev |= lb;
        
        rev <<= 1;
        n >>= 1;
      }

      rev >>= 1;

      return rev;
    }

    public static int NthPalindromicBinary(int n) {
      int cnt = 1;
      int len = 1;
      
      while (cnt < n) {
        len++;
        cnt += (1 << (len - 1) / 2);
      }

      cnt -= (1 << (len - 1) / 2);
      int offset = n - cnt - 1;

      int ans = (1 << (len - 1));
      ans |= (offset << (len / 2));

      int valFor = (ans >> (len / 2));
      int rev = getRev(valFor);

      ans |= rev;
      return ans;
    }

    public static void main(String[] args) {
      Scanner scn = new Scanner(System.in);
      int n = scn.nextInt();
      System.out.println(NthPalindromicBinary(n));

      scn.close();
    }

}