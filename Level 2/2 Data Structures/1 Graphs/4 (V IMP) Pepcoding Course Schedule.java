import java.io.*;
import java.util.*;

class Main {
    public static class Edge {
        int a;
        int b;

        Edge(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] parts = br.readLine().split(" ");
        int n = Integer.parseInt(parts[0]);
        int m = Integer.parseInt(parts[1]);

        ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            edges.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++){
            parts = br.readLine().split(" ");

            int a = Integer.parseInt(parts[0]);
            int b = Integer.parseInt(parts[1]);

            edges.get(b).add(a);
        }

        int[] ans = findOrder(n, edges);

        for(int val : ans){
            System.out.print(val + " ");
        }

        br.close();
	}

    public static int[] findOrder(int n, ArrayList<ArrayList<Integer>> graph){
        int[] indegree = new int[n];
        int[] ans = new int[n];
        
        for (int i = 0; i < n; i++) {
            for(int nbrs : graph.get(i)){
                indegree[nbrs]++;
            }
        }

        LinkedList<Integer> queue = new LinkedList<Integer>();
        for (int i = 0; i < n; i++) {
            if(indegree[i] == 0){
                queue.addLast(i);
            }
        }

        int idx = 0;
        while(queue.size() > 0){
            int rem = queue.removeFirst();

            ans[idx] = rem;
            idx++;

            for(int nbrs : graph.get(rem)){
                indegree[nbrs]--;

                if(indegree[nbrs] == 0){
                    queue.addLast(nbrs);
                }
            }
        }

        if(idx == n){
            return ans;
        } else {
            return new int[]{-1};
        }
    }
}