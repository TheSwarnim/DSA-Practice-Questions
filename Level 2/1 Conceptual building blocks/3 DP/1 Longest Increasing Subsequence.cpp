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
    Vi arr(n);
    for (auto &&i : arr)
    {
        cin >> i;
    }
    
    int dp[n];
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && dp[j] > dp[i]){
                dp[i] = dp[j];
            } 
        }        
        dp[i]++;
    }
    
    cout << *max_element(dp, dp + n) << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}