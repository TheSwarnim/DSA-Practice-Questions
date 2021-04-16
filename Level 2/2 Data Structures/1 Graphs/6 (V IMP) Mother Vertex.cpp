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

vvi g;
vector<bool> visited;

void dfs(int v){
    visited[v] = true;

    for(int i = 0; i < g[v].size(); i++){
        if(!visited[ g[v][i] ]){
            dfs( g[v][i] );
        }
    }
}

void solve(){
    int n;
    cin>>n;

    g.resize(n);

    int m;
    cin>>m;
    for (size_t i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;

        a--;
        b--;

        g[a].push_back(b);
    }

    int v = -1;
    visited.assign(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            v = i;
        }
    }

    visited.assign(n, false);
    dfs(v);
    for(bool val : visited){
        if(!val){
            cout << -1 << endl;
            return;
        }
    }

    cout << v + 1 << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}