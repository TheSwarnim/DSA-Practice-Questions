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

void displayMatrix(vector<vector<int>> &arr){
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool targetSumSubset(vector<int> &arr, int tar, int n){
    vector<vector<bool>> dp(n+1, vector<bool>(tar+1));

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                dp[i][j] = false;
            } else if (j == 0) {
                dp[i][j] = true;
            } else {
                if(dp[i - 1][j] == true){
                    dp[i][j] = true;
                } else {
                    int val = arr[i - 1];
                    if (j >= val && dp[i - 1][j - val] == true) {
                        dp[i][j] = true;
                    }
                }
            }
        }
    }
    
    return dp[n][tar];
}

void solve(){
    optimize();

    int n; cin>>n;
    vector<int> arr(n);

    for (auto &&i : arr)
    {
        cin>>i;
    }

    int tar; cin>>tar;
    
    if(targetSumSubset(arr, tar, n)){
        cout<<"true\n";
    }else{
        cout<<"false\n";
    }
    
    calcTime;
}

int main(){
    solve();

    return 0;
}