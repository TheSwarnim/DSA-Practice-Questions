#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define calcTime cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
#define Vi vector<int>

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

void dfs(int i, int n){
    if(i > n){
        return;
    }
    
    cout<< i << endl;
    for (int j = 0; j < 10; j++)
    {
        dfs(10 * i + j, n);   
    }
}

void solve(){
    optimize();
    
    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++)
    {
        dfs(i, n);
    }
    
    calcTime;
}

int main(){
    solve();

    return 0;
}