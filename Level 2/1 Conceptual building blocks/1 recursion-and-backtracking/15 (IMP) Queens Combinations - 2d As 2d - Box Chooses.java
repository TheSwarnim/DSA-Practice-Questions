import java.io.*;
import java.util.*;

public class Main {

    public static void queensCombinations(int qpsf, int tq, int row, int col, String asf){
        // base case
		if(col == tq){
			col = 0;
			asf += "\n";
			row++;
		}
		if(row == tq){
			if(qpsf == tq){
				System.out.println(asf);
			}

			return;
		}
		if(qpsf > tq){
			return;
		}

		// include queen on present place
		queensCombinations(qpsf + 1, tq, row, col + 1, asf + "q");

		// not include queen on present place
		queensCombinations(qpsf, tq, row, col + 1, asf + "-");
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        queensCombinations(0, n, 0, 0, "");
    }
}