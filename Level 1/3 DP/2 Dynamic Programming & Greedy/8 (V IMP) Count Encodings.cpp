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

void countEncodings(string s){
    // base case
    char ch = s.at(0);
    if(ch=='0'){
        cout << -1 << endl;
    }

    int n = s.size();
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        char prevCh = s.at(i-1);
        char ch = s.at(i);

        if(prevCh == '0' && ch == '0'){
            dp[i] = 0;
        }else if(prevCh == '0' && ch != '0'){
            dp[i] = dp[i-1];
        }else if(prevCh != '0' && ch == '0'){
            if(prevCh=='1' || prevCh=='2')
                dp[i] = i>=2 ? dp[i-2] : 1;
            else dp[i] = 0;            
        }else{
            dp[i] = dp[i-1];
            if(s.substr(i-1, 2).compare("26") <= 26)
                dp[i] += i>=2 ? dp[i-2] : 1;
        }
    }
    
    cout << dp[n-1] << "\n";
}

void solve(){
    optimize();
    
    string n; cin>>n;
    
    countEncodings(n);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}