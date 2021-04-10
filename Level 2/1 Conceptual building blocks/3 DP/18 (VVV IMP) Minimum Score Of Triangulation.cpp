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
    cin >> n;
    vector<long> arr(n);
    for (auto &&i : arr)
    {
        cin>>i;
    }
    
    vector<vector<long>> dp(n, vector<long>(n));

    for (int g = 0; g < n; g++)
    {
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0){
                dp[i][j] = 0;
            } else if(g == 1){
                dp[i][j] = 0;
            } else if(g == 2){
                dp[i][j] = arr[i] * arr[i + 1] * arr[i + 2];
            } else {
                int minVal = 1e9;
                for(int k = i + 1; k <= j - 1; k++) {
                    int itria = arr[i] * arr[k] * arr[j];
                    int pleft = dp[i][k];
                    int pright = dp[k][j];

                    int ttl = itria + pleft + pright;
                    minVal = min(minVal, ttl);
                }

                dp[i][j] = minVal;
            }
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