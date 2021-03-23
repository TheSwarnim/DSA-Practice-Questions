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

void partitionIntoSubsets(int n, int k){
    long dp[k+1][n+1];

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i==0 || j==0 || i>j){
                dp[i][j] = 0;
            }else if(i==1){
                dp[i][j] = 1;
            }else{
                dp[i][j] = i*dp[i][j-1] + dp[i-1][j-1];
            }
        }
        
    }
    

    cout << dp[k][n] << endl;
}

void solve(){
    optimize();
    
    int n;
    cin>>n;

    int k;
    cin>>k;

    partitionIntoSubsets(n, k);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}