import java.io.*;
import java.util.*;

public class Main {
    public static boolean canMove(boolean[][] chess,int x, int y) {
        int n = chess.length;
        if(x >= 0 && y >= 0 && x < n && y < n && chess[x][y] == true) {
            return false;
        }

        return true;
    }
    
    public static boolean IsKnightSafe(boolean[][] chess, int i, int j) {
        // top left
        if(canMove(chess, i - 2, j - 1) == false) {
            return false;
        }
        // top right
        if(canMove(chess, i - 2, j + 1) == false) {
            return false;
        }

        // bottom left
        if(canMove(chess, i + 2, j - 1) == false) {
            return false;
        }
        // bottom right
        if(canMove(chess, i + 2, j + 1) == false) {
            return false;
        }

        // left up
        if(canMove(chess, i - 1, j - 2) == false) {
            return false;
        }
        // let bottom
        if(canMove(chess, i + 1, j - 2) == false) {
            return false;
        }

        // right up
        if(canMove(chess, i - 1, j + 2) == false) {
            return false;
        }
        // right bottom
        if(canMove(chess, i + 1,j + 2) == false) {
            return false;
        }


        return true;
    }

    public static void nknights(int kpsf, int tk, boolean[][] chess, int lcno) {
        if (kpsf == tk) {
            for (int row = 0; row < chess.length; row++) {
                for (int col = 0; col < chess.length; col++) {
                    System.out.print(chess[row][col] ? "k\t" : "-\t");
                }
                System.out.println();
            }
            System.out.println();
            return;
        }

        for (int i = lcno + 1; i < chess.length * chess.length; i++) {
            int row = i / chess.length;
            int col = i % chess.length;

            if (chess[row][col] == false && IsKnightSafe(chess, row, col)) {
                chess[row][col] = true;
                nknights(kpsf + 1, tk, chess, row * chess.length + col);
                chess[row][col] = false;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[][] chess = new boolean[n][n];

        nknights(0, n, chess, -1);
    }
}