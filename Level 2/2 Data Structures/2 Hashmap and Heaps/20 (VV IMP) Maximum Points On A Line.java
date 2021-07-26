import java.util.*;

public class Main {
	public static  int solution(int[][] pts) {
		if(pts.length == 1) {
            return pts.length;
        }

        int ans = 0;
        for (int i = 0; i < pts.length; i++) {
            var map = new HashMap<String, Integer>();
            int dublicate = 0;
            int max = 0;

            for (int j = i + 1; j < pts.length; j++) {
                int deltaX = pts[j][0] - pts[i][0];
                int deltaY = pts[j][1] - pts[i][1];

                if(deltaX == 0 && deltaY == 0){
                    dublicate++; //means same pt
                    continue;
                }

                int gcd = gcd(deltaX, deltaY);
                int dx = deltaX / gcd;
                int dy = deltaY / gcd;

                map.put(dx + "," + dy, map.getOrDefault(dx + "," + dy, 0) + 1);
                max = Math.max(max, map.get(dx + "," + dy));
            }

            ans = Math.max(ans, max + dublicate + 1);
        }

        return ans;
	}
	
    private static int gcd(int a, int b) {
        if(b == 0) {
            return a;
        } else{
            return gcd(b, a % b);
        }
    }
    public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int[][] arr = new int[n][2];
		for(int i = 0 ; i < n; i++){
			for(int j = 0 ; j < 2; j++){
				arr[i][j] = scn.nextInt();
			}
		}
		System.out.println(solution(arr));

        scn.close();
	}

}
