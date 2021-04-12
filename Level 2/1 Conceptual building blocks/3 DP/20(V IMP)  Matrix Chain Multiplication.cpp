/*
 * File: test.cpp
 * Project: Level 2
 * Author: swarnim (swarnimpratap132@gmail.com)
 * -----
 * Last Modified: Sunday, 11th April 2021 3:29:22 pm
 * Modified By: swarnim (swarnimpratap132@gmail.com)
 * -----
 * Copyright ©2021 SwarnimInc
 */

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

void displayArray(vector<int> &arr){
    for (auto &&i : arr)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}

void solve(){
    int n;
    cin >> n;
    vi arr(n);
    for (auto &&i : arr)
    {
        cin >> i;
    }

    // displayArray(arr);
    
    vvi dp(n - 1, vi(n - 1));

    for (int g = 0; g < n - 1; g++)
    {
        for(int i = 0, j = g; j < n - 1; i++, j++){
            if(g == 0){
                dp[i][j] = 0;
            } else if(g == 1){
                dp[i][j] = arr[i] * arr[j] * arr[j + 1];
            } else{ 
                int mn = 1e9;
                for(int k = i; k < j; k++){
                    /**
                     * (i, k) - left half
                     * (k+1, j) - right half
                     * 
                     * arr -> i * k + 1
                     **/
                    int lc = dp[i][k];
                    int rc = dp[k + 1][j];
                    int mc = arr[i] * arr[k + 1] * arr[j + 1];

                    int tc = lc + rc + mc;

                    mn = min(mn, tc);
                    dp[i][j] = mn;
                }
            }
        }
    }
    
    cout << dp[0][n - 2] << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
} 