#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

bool debug;
void optimize(){
    if(debug){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        #endif
    }
}

void calcTime(){
    if(debug){
        cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    }
}

class Graph {
    public:
        int a;
        int b;
        int weight;

        Graph(int a, int b, int weight):a(a),b(b),weight(weight){}
};

void fillGraph(vector<Graph> &arr, int m){
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin>>a>>b>>wt;

        arr.push_back({a, b, wt});
    }    
}

const int inf = 1e9;

bool bellManFord(vector<Graph> &graph, int n, int m){
    vi d(n, inf);
    d[0] = 0;

    int x;
    for(int i = 0; i < n; i++){
        x = -1;
        for(int j = 0; j < m; j++){
            int a = graph[j].a;
            int b = graph[j].b;
            int wt = graph[j].weight;

            if(d[a] < inf){
                // d[b] = min(d[b], d[a] + wt);
                if(d[b] > d[a] + wt){
                    d[b] = max(-inf, d[a] + wt);
                    x = b;
                }
            }
        }

    }
    // run the loop n times and if x != -1 in nth time, it means their is cycle in graph of -ve weight

    return x != -1;
}

void solve(){
    int n, m;
    // n : vertices
    // m : edges
    cin >> n >> m;

    vector<Graph> graph;
    fillGraph(graph, m);

    cout << bellManFord(graph, n, m) << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}