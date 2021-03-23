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

void getCoinChangeComb(int arr[], int n, int amt){
    int dp[n+1][amt+1];

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < amt+1; j++)
        {
            if(j==0){
                dp[i][j] = 1;
            }else if(i==0){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i-1][j];
                
                int val = arr[i-1];

                if(j-val>=0){
                    dp[i][j] += dp[i][j-val];
                }
            }
        }
    }
    
    cout<<dp[n][amt]<<"\n";
}

void spaceOptimizedCoinChangeComb(int S[], int m, int n){
    int table[n+1];

    memset(table, 0, sizeof(table)); 

    table[0] = 1; 
    
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
  
    cout << table[n] << "\n"; 
}

void solve(){
    optimize();
    
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int amt; cin>>amt;
    
    // getCoinChangeComb(arr, n, amt);
    spaceOptimizedCoinChangeComb(arr, n, amt);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}