#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define calcTime cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int cs(int arr[], int n){
    // write your code here
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= arr[i] && i+j<=n; j++)
        {
            dp[i] += dp[i+j];
        }
        
    }
        
    return dp[0];
}

void solve(){
    optimize();
    
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
    
    calcTime;
}

int main(){
    solve();

    return 0;
}