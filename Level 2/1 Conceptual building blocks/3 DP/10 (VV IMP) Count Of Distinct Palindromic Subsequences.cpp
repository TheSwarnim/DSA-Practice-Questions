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
    cin >> str;

    int n = str.size();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    map<char, int> map;

    int prev[n];
    memset(prev, 0, sizeof(prev));

    for (int i = 0; i < n; i++)
    {
        char ch = str.at(i);

        if(map.find(ch) == map.end()){
            prev[i] = -1;
        } else {
            prev[i] = map[ch];
        }

        map[ch] = i;
    }
    
    map.clear();
    int next[n];
    memset(next, 0, sizeof(next));

    for (int i = n - 1; i >= 0; i--)
    {
        char ch = str.at(i);

        if(map.find(ch) == map.end()){
            next[i] = -1;
        } else {
            next[i] = map[ch];
        }

        map[ch] = i;
    }
    

    for (int g = 0; g < n; g++)
    {
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0){
                dp[i][j] = 1;
            } else if (g == 1){
                dp[i][j] = 2;
            } else {
                char sc = str.at(i); //starting character
                char ec = str.at(j); //ending character

                if(sc != ec){
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                } else {
                    int nis = next[i]; // next index of starting
                    int pie = prev[j]; // prev index of ending

                    if(nis > pie){
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
                    } else if(nis == pie){
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
                    } else {
                        dp[i][j] = 2 * dp[i + 1][j - 1] - dp[nis + 1][pie - 1];
                    }
                }
            }
        }
    }
    
    
    cout << dp[0][n - 1] << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}