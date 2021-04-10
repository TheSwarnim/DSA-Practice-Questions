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
    string s1;
    string s2;
    cin >> s1 >> s2;

    int m = s1.length();
    int n = s2.length();

    vector<Vi> dp(n + 1, Vi(m + 1));
    
    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if(i == n && j == m){
                dp[i][j] = 1;
            } else if(i == n){
                dp[i][j] = 0;
            } else if(j == m){
                if(s2[i] == '*'){
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = 0;
                }
            } else {
                char ch1 = s2.at(i);
                char ch2 = s1.at(j);

                if(ch1 == '*'){
                    dp[i][j] = dp[i + 1][j] | dp[i][j + 1];
                } else if(ch1 == '?'){
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    if(ch1 == ch2){
                        dp[i][j] = dp[i + 1][j + 1];
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
    }

    cout << boolalpha << (dp[0][0] == 1) << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}