/*
 * Filename: /media/swarnim/Softwares/C++/Pepcoding/Level 2/1 Conceptual building blocks/3 DP/19 (IMP) (B)  Minimum Palindromic Cut.cpp
 * Path: /media/swarnim/Softwares/C++/Pepcoding/Level 2/1 Conceptual building blocks/3 DP
 * Created Date: Thursday, January 1st 1970, 5:30:00 am
 * Author: swarnim
 * 
 * Copyright (c) 2021 Your Company
 */

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

void solve(){
    string str;
    cin >> str;

    int n = str.size();

    vector<Vi> palindrome(n, Vi(n));

    for (int g = 0; g < n; g++)
    {
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0){
                palindrome[i][j] = 1;
            } else if(g == 1){
                palindrome[i][j] = str.at(i) == str.at(j) ? 1 : 0;
            } else {
                if(str.at(i) == str.at(j) && palindrome[i + 1][j - 1] == 1) {
                    palindrome[i][j] = 1;
                } else {
                    palindrome[i][j] = 0;
                }
            }
        }
    }
    
    Vi dp(n);
    dp[0] = 0;

    for (int j = 1; j < n; j++)
    {
        if(palindrome[0][j]){
            dp[j] = 0;
            continue;
        }
        
        int minVal = 1e9;
        for (int i = j; i >= 1; i--)
        {
            if(palindrome[i][j]){
                minVal = min(minVal, dp[i - 1]);
            }
        }    
        dp[j] = 1 + minVal;    
    }
    
    cout << dp[n - 1] << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}