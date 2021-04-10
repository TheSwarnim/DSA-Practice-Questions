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
    string str;
    cin >> str;

    int n = str.size();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int g = 0; g < n; g++)
    {
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0){
                dp[i][j] = 1;
            } else if(g == 1){
                dp[i][j] = str.at(i) == str.at(j) ? 3 : 2;
            } else {
                if(str.at(i) == str.at(j)){
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
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