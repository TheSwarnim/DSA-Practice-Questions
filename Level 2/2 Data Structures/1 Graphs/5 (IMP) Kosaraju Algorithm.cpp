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

vvi g, gr;
vector<bool> used;
vi order;

void dfs1(int v){
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); i++)
    {
        if(!used[ g[v][i] ]){
            dfs1 (g[v][i]);
        }
    }
    order.push_back (v);
}

void dfs2(int v){
    used[v] = true;
    for (size_t i = 0; i < gr[v].size(); i++)
    {
        if(!used[ gr[v][i] ]){
            dfs2(gr[v][i]);
        }
    }    
}

void solve(){
    int n;
    cin>>n;

    g.resize(n); 
    gr.resize(n);

    int m;
    cin>>m;
    for (size_t i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;

        a--;
        b--;

        g[a].push_back(b);
        gr[b].push_back(a);
    }

    used.assign(n, false);
    for (size_t i = 0; i < n; i++)
    {
        if(!used[i]){
            dfs1(i);
        }
    }

    int cnt = 0;
    used.assign(n, false);
    for (size_t i = 0; i < n; i++)
    { 
        int v = order[n - 1 - i];
        if (!used[v]){
            cout << v << " ";
            dfs2(v);
            cnt++;
        }
    }    

    cout << endl;
    cout << cnt << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}