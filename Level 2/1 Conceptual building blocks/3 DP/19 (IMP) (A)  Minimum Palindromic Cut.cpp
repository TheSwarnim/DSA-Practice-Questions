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
    
    
    vector<Vi> dp(n, Vi(n));
    
    for (int g = 0; g < n; g++)
    {
        for(int i = 0, j = g; j < n; j++, i++){
            if(g == 0){
                dp[i][j] = 0;
            } else if(g == 1){
                dp[i][j] = str.at(i) == str.at(j) ? 0 : 1;
            } else {
                if(palindrome[i][j] == 1){
                    dp[i][j] = 0;
                } else{
                    int minVal = 1e9;

                    for (int k = i; k < j; k++)
                    {
                        minVal = min(minVal, dp[i][k] + dp[k + 1][j]);
                    }
                    
                    dp[i][j] = 1 + minVal;
                }
            }
        }
    }

    // displayMatrix(dp);
    cout << dp[0][n - 1] << endl;   
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}