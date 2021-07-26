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

int getMinReverseEdges(map<int, set<int>> &dg, map<int, set<int>> &udg, int src, int n, vector<bool> &visited){
    // base case
    if(src == n){
        return 1;
    }
    
    visited[src] = true;
    int minEdge = 1e9;
    for(auto i : udg[src]){
        if(!visited[i]){
            if((dg.find(src) != dg.end()) && (dg[src].find(i) != udg[src].end())){
                int curMin = getMinReverseEdges(dg, udg, i, n, visited);
                if(curMin != -1){
                    minEdge = min(minEdge, curMin);
                }
            } else{
                int curMin = getMinReverseEdges(dg, udg, i, n, visited);
                if(curMin != -1){
                    minEdge = min(minEdge, curMin + 1);
                }
            }
        }
    }   
    visited[src] = false;

    if(minEdge == 1e9){
        return -1;
    } else {
        return minEdge;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    map<int, set<int>> dg, udg;
    vector<bool> visited(n, false);

    while(m--){
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        dg[a].insert(b);
        
        udg[a].insert(b);
        udg[b].insert(a);
    }

    if(dg[0].find(n - 1) != dg[0].end()){
        cout << 0 << endl;
    } else {
        cout << getMinReverseEdges(dg, udg, 0, n - 1, visited) << endl;
    }
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}