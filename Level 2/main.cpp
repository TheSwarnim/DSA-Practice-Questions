#include<bits/stdc++.h>
using namespace std;
#define v(type) vector<type>
#define vv(type) vector<v(type)>

v(bool) visited;
vv(int) graph;
v(int) stack;

void dfs(int x){
    visited[x] = true;
    for(int i : graph[x]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }
    
    visited.assign(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }   
}