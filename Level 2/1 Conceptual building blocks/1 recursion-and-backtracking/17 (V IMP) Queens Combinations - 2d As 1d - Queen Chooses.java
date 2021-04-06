import java.io.*;

public class Main {

    public static void queensCombinations(int qpsf, int tq, boolean[][] chess, int lcno) {
        // base case
		if(qpsf == tq) {
			for (int i = 0; i < chess.length; i++) {
				for (int j = 0; j < chess[i].length; j++) {
					if(chess[i][j] == true) {
						System.out.print("q\t");
					} else {
						System.out.print("-\t");
					}
				}
				System.out.println();
			}
			System.out.println();
		}

		for (int cell = lcno + 1; cell < chess.length * chess[0].length; cell++) {
			int row = cell / chess.length;
			int col = cell % chess.length;

			chess[row][col] = true;

			queensCombinations(qpsf + 1, tq, chess, cell);

			chess[row][col] = false;
		}
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[][] chess = new boolean[n][n];

        queensCombinations(0, n, chess, -1);
    }
}