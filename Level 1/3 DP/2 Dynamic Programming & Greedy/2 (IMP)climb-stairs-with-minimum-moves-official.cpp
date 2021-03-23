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
    vector<int> dp(n+1, 1e9);
    dp[n] = 0;

    // minimunm step required to react dp[n] from n, n-1, n-2, ...., 0
    for (int i = n - 1; i >= 0; i--)
    {
        for(int j=1; j<=arr[i] && i+j<=n; j++){
            dp[i] = min(dp[i], dp[i+j]+1);
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
    int ans = cs(arr,n);
    if(ans!=1e9) cout<<ans<<endl;
    else cout<<"null"<<endl;
    
    calcTime;
}

int main(){
    solve();

    return 0;
}