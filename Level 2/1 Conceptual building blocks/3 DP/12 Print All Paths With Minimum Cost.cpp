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

class Pair{
    public:
        int i;
        int j;
        string psf;
        Pair(int i, int j, string psf): i(i), j(j), psf(psf) {}
};

void solve(){
    int n, m;
    cin >> n >> m;
    vvi arr(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }        
    }
    
    vvi dp(n, vi(m));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if(i == n - 1 && j == m - 1){
                dp[i][j] = arr[i][j];
            } else if(i == n - 1){
                dp[i][j] = arr[i][j] + dp[i][j + 1];
            } else if(j == m - 1){
                dp[i][j] = arr[i][j] + dp[i + 1][j];
            } else {
                dp[i][j] = arr[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
            }
        }        
    }
    
    cout << dp[0][0] << endl;
    // displayMatrix(dp);

    queue<Pair> queue;
    queue.push(Pair(0, 0, ""));

    while (!queue.empty()){
        Pair rem = queue.front();
        queue.pop();

        int i = rem.i;
        int j = rem.j;
        string psf = rem.psf;

        if(i == n - 1 && j == m - 1){
            // base case
            cout << psf << endl;
        } else if(i == n - 1){
            queue.push(Pair(i, j + 1, psf + "H"));
        } else if(j == m - 1){
            queue.push(Pair(i + 1, j, psf + "V"));
        } else{
            if(dp[i + 1][j] < dp[i][j + 1]){
                queue.push(Pair(i + 1, j, psf + "V"));
            } else if(dp[i + 1][j] > dp[i][j + 1]){   
                queue.push(Pair(i, j + 1, psf + "H"));
            } else{
                queue.push(Pair(i + 1, j, psf + "V"));
                queue.push(Pair(i, j + 1, psf + "H"));
            }
        }
    }
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}