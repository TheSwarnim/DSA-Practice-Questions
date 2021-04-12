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

void displayArray(string arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] << " ";
    }
    
    cout<<"\n";
}

void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    vvi dp(s1.length() + 1, vi(s2.length() + 1));
    for(int i = s1.length(); i >= 0; i--){
        for(int j = s2.length(); j >= 0; j--){
            if(i == s1.length() && j == s2.length()){
                dp[i][j] = 0;
            } else if(i == s1.length()){
                dp[i][j] = s2.at(j) + dp[i][j + 1];
            } else if(j == s2.length()){
                dp[i][j] = s1.at(i) + dp[i + 1][j];
            } else{
                if(s1.at(i) == s2.at(j)){
                    dp[i][j] = dp[i + 1][j + 1];
                } else{
                    int f1 = s1.at(i) + dp[i + 1][j];
                    int f2 = s2.at(j) + dp[i][j + 1];

                    dp[i][j] = min(f1, f2);
                }
            }
        }
    }
    
    cout << dp[0][0] << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}