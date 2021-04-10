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
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    
    sort(arr.begin(), arr.end());

    int dp[n];
    dp[0] = 1;

    for (int i = 1; i < n; i++){
        int maxVal = 0;
        for (int j = 0; j < i; j++)
        {
            if(arr[j].second < arr[i].second && maxVal < dp[j]){
                maxVal = dp[j];
            }
        }
        dp[i] = 1 + maxVal;
    }

    cout << *max_element(dp, dp + n) <<endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}