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

void solve(){
    int n;
    cin>>n;
    vi arr(n);
    for (auto &&i : arr)
    {
        cin>>i;
    }
    
    vvi dp(n, vi(n));

    for (int g = 0; g < n; g++)
    {
        for(int i = 0, j = g; j < n; i++, j++){
            int maxVal = -1;
            for (int k = i; k <= j; k++)
            {
                int left = k == i ? 0 : dp[i][k - 1];
                int right = k == j ? 0 : dp[k + 1][j];
                int val = (i == 0 ? 1 : arr[i - 1]) * arr[k] * (j == n - 1 ? 1 : arr[j + 1]);

                int ttl = left + val + right;
                maxVal = max(maxVal, ttl);
            }

            dp[i][j] = maxVal;
        }
    }
    
    cout << dp[0][n - 1] << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}