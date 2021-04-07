#include<bits/stdc++.h>
using namespace std;
#define Vi vector<int>

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

void solve(){
    int n;
    cin>>n;
    Vi arr(n);
    for (auto &&i : arr)
    {
        cin>>i;
    }
    int k;
    cin>>k;

    int dp[k + 1][n];

    for (int t = 0; t <= k; t++)
    {
        for (int d = 0; d < n; d++)
        {
            if(t == 0 || d == 0){
                dp[t][d] = 0;
            }else {
                dp[t][d] = dp[t][d - 1];

                for (int pd = 0; pd < d; pd++)
                {
                    int ptilltm1 = dp[t - 1][pd];
                    int ptth = arr[d] - arr[pd];

                    dp[t][d] = max(dp[t][d], ptilltm1 + ptth);    
                }
            }
        }
        
    }
    
    
    cout << dp[k][n - 1] << endl;
}

int main(){
    debug = 1;
    optimize();
    
    solve();

    calcTime();
    return 0;
}