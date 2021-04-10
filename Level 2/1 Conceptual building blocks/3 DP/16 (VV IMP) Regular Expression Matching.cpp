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
    string str;
    string pattern;
    cin >> str >> pattern;

    vector<Vi> dp(pattern.size() + 1, Vi(str.size() + 1));

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
            } else if(i == 0){
                dp[i][j] = 0;
            } else if(j == 0){
                char ch = pattern.at(i - 1);
                if(ch == '*'){
                    dp[i][j] = dp[i-2][j];
                } else {
                    dp[i][j] = 0;
                }
            } else {
                char pChar = pattern.at(i - 1);
                char sChar = str.at(j - 1);

                if(pChar == '*'){
                    dp[i][j] = dp[i - 2][j];

                    char pslc = pattern.at(i - 2);
                    if(pslc == '.' || pslc == sChar){
                        dp[i][j] = dp[i][j] | dp[i][j - 1];
                    }
                } else if(pChar == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(pChar == sChar){
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(pChar != sChar){
                    dp[i][j] = 0;
                }
            }
        }        
    }
    
    cout << boolalpha << (dp[pattern.size()][str.size()] == 1) << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}