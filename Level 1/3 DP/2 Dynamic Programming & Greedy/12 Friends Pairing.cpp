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

void friendsPairing(int n){
    int dp[n+1];
    dp[1]=1;
    dp[2]=2;

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2]*(i-1);
    }

    cout << dp[n] << endl;
}

void solve(){
    optimize();
    
    int n;
    cin>>n;

    friendsPairing(n);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}