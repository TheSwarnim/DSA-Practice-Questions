public class Disjoint {
    int n;
    int[] parent;
    
    Disjoint(int n){
       this.n = n;
       parent = new int[n];
       makeSet();
    }

    void makeSet()
    {
       for (int i = 0; i < n; i++) {
          parent[i] = i;
       }
    }

    int find(int x){
       if(parent[x] != x){
          parent[x] = find(parent[x]);
       }

       return parent[x];
    }

    void union(int a, int b){
       a = find(a);
       b = find(b);

       if(a != b){
          parent[b] = a;
       }
    }
 }
