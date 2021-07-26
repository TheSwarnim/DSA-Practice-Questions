import java.io.*;
import java.util.*;

class Main {

    public static boolean IsQueenSafe(int[][] chess, int row, int col) {
        int n = chess.length;
        // row
        for(int i = n - 1, j = col; i >= 0; i--) {
            if(chess[i][j] != 0){
                return false;
            }
        }

        // column
        for(int i = row, j = n - 1; j >= 0; j--) {
            if(chess[i][j] != 0){
                return false;
            }
        }

        // primary diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(chess[i][j] != 0){
                return false;
            }
        }

        for(int i = row + 1, j = col + 1; i < n && j < n; i++, j++){
            if(chess[i][j] != 0){
                return false;
            }
        }

        // secondary diagonal
        for(int i = row, j = col; i >= 0 && j < n; i--, j++){
            if(chess[i][j] != 0){
                return false;
            }
        }

        for(int i = row, j = col; i < n && j >= 0; i++, j--){
            if(chess[i][j] != 0){
                return false;
            }
        }
        
        return true;
    }

    public static void display(int[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {
                System.out.print(arr[i][j] == 0 ? "-\t" : "q" + arr[i][j] + "\t");
            }
            System.out.println();
        }
    }

    public static void nqueens(int qpsf, int tq, int[][] chess) {
        // base case
        if(qpsf == tq){
            display(chess);
            System.out.println();
        
            return;
        }

        for (int i = 0; i < chess.length; i++) {
            for (int j = 0; j < chess.length; j++) {
                if(chess[i][j] == 0 && IsQueenSafe(chess, i, j)) {
                    chess[i][j] = qpsf + 1;

                    nqueens(qpsf + 1, tq, chess);

                    chess[i][j] = 0;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] chess = new int[n][n];

        nqueens(0, n, chess);
    }
}