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

void paintHouse(vector<vector<int>> &colors){
    // red blue green
    int n = colors.size();
    int k = colors[0].size();
    
    int dp[n][k];
    
    int least = 1e9;
    int secLeast = 1e9;

    for (int j = 0; j < k; j++)
    {
        dp[0][j] = colors[0][j];

        if(colors[0][j] <= least){
            secLeast = least;
            least = colors[0][j];
        }else if(colors[0][j] <= secLeast){
            secLeast = colors[0][j];
        }
    }
    
    for (int i = 1; i < n; i++)
    {
        int nleast = 1e9;
        int nsleast = 1e9;
        for (int j = 0; j < k; j++)
        {
            if(least == dp[i-1][j]){
                dp[i][j] = secLeast + colors[i][j];
            }else{
                dp[i][j] = least + colors[i][j];
            }

            if(dp[i][j] <= nleast){
                nsleast = nleast;
                nleast = dp[i][j];
            }else if(dp[i][j] <= nsleast){
                nsleast = dp[i][j];
            }
        }
        least = nleast;
        secLeast = nsleast;
    }
    
    cout << least << "\n";
}

void solve(){
    optimize();
    
    int n; cin>>n;
    int k; cin>>k;
    vector<vector<int>> colors(n, vector<int>(k));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin>>colors[i][j];
        }
    }
    
    
    paintHouse(colors);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}