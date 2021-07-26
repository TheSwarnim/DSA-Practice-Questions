import java.io.*;
import java.util.*;

public class Main {
    public static class Edge {
        int v;
        int wt;

        Edge(int v, int wt) {
            this.v = v;
            this.wt = wt;
        }
    }

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] parts = br.readLine().split(" ");
        int n = Integer.parseInt(parts[0]);
        int m = Integer.parseInt(parts[1]);

        ArrayList<ArrayList<Edge>> edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            edges.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++){
            parts = br.readLine().split(" ");

            int a = Integer.parseInt(parts[0]);
            int b = Integer.parseInt(parts[1]);

            a--;
            b--;

            edges.get(a).add(new Edge(b, 0));
            edges.get(b).add(new Edge(a, 1));
        }
        
        LinkedList<Edge> queue = new LinkedList<>();
        boolean[] vis = new boolean[n];
        queue.add(new Edge(0, 0));

        while(queue.size() > 0) {
            Edge rem = queue.removeFirst();

            if(rem.v == n - 1) {
                System.out.println(rem.wt);
                return;
            }
            
            vis[rem.v] = true;
            for(Edge e : edges.get(rem.v)){
                if(vis[e.v] == false){
                    if(e.wt == 0){
                        queue.addFirst(new Edge(e.v, rem.wt + 0));
                    } else {
                        queue.addLast(new Edge(e.v, rem.wt + 1));
                    }
                }
            }
        }

        System.out.println(-1);
        br.close();
	}
}
