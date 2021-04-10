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

    long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    map<char, int> lo; // last occurance
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1];
        
        char ch = str.at(i - 1);
        if(lo.find(ch) != lo.end()){
            int j = lo[ch];
            dp[i] = dp[i] - dp[j - 1];
        }

        lo[ch] = i;
    }
    
    cout << dp[n] - 1 << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}