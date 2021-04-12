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
    vi key(n);
    for (auto &&i : key)
    {
        cin>>i;
    }
    vi freq(n);
    for (auto &&i : freq)
    {
        cin>>i;
    }

    vi prefixSum(n);
    prefixSum[0] = freq[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + freq[i];
    }

    vvi dp(n, vi(n));
    for (int g = 0; g < n; g++)
    {
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0){
                dp[i][j] = freq[i];
            } else if(g  == 1){
                int cost1 = freq[i] + 2 * freq[j];
                int cost2 = 2 * freq[i] + freq[j];

                dp[i][j] = cost1 < cost2 ? cost1 : cost2;
            } else{
                /*
                int fs = 0; // frequency sum
                for(int k = i; k <= j; k++){
                    fs += freq[k];
                }
                other optimized way 👇👇 (iska upar prefix sum defined ha usko use kia ha)
                */
               int fs = prefixSum[j] - (i == 0 ? 0 : prefixSum[i - 1]);

                int mn = 1e9;
                for(int k = i; k <= j; k++){
                    int left = k == i ? 0 : dp[i][k - 1];
                    int right = k == j ? 0 : dp[k + 1][j];

                    mn = min(mn, left + right + fs);
                }
                
                dp[i][j] = mn;
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