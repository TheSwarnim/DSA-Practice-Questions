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

    Vi dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i<=n; i++){
        int x = 0;
        int y = i - 1;

        while(x < n && y >= 0){
            dp[i] += dp[x] * dp[y];
            x++;
            y--;
        }
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