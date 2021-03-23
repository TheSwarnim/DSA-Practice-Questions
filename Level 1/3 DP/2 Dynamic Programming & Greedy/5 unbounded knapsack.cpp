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

void unboundedKnapsack(int values[], int weights[], int n, int cap){
    int dp[n+1][cap+1];
    // dp[x][y] is the maximum value which can be put in bag of cap 'y'
    // using 'x' different/same items.
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else{
                int wei = weights[i-1];

                if(j-wei>=0){
                    int val = values[i-1];
                    dp[i][j] = max(val+dp[i][j-wei], dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    
    cout << dp[n][cap] << "\n";
}

void solve(){
    optimize();
    
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int arr2[n];
    for(int i=0; i<n; i++){
        cin>>arr2[i];
    }

    int tar; cin >> tar;
    
    unboundedKnapsack(arr, arr2, n, tar);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}