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
    string s1;
    string s2;
    cin>>s1>>s2;

    int n = s1.length();
    int m = s2.length();

    int dp[n + 1][m + 1];

    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < m + 1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            } else {
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 +dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max({dp[i][j - 1], dp[i - 1][j]});
                }
            }
        }
    }

    cout << dp[n][m] << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}