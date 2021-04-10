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

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        int min = 1e9;
        for (int j = 1; j*j <= i; j++)
        {
            int rem = i - j * j;
            if(dp[rem] < min){
                min = dp[rem];
            }
        }
        dp[i] = 1 + min;
    }
    
    cout << dp[n] << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}