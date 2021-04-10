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

class Pair {
    public:
        int i; // index
        int s; // steps
        int j; // jumps allowed
        string psf; // path so far

        Pair(int i, int s, int j, string psf) : i(i), s(s), j(j), psf(psf) {}
};

void solve(){
    int n;
    cin>>n;
    Vi arr(n);
    for (auto &&i : arr)
    {
        cin>>i;
    }
    
    Vi dp(n, 1e9);
    dp[n - 1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= arr[i] && i + j < n; j++)
        {
            if(dp[i + j] != 1e9) dp[i] = min(dp[i], 1 + dp[i + j]);
        }
    }
    
    if(dp[0] != 1e9){
        cout << dp[0] << endl;

        queue<Pair> queue;
        queue.push(Pair(0, arr[0], dp[0], "0"));
        
        while (!queue.empty()){
            Pair rem = queue.front();
            queue.pop();
            // cout << rem.psf << endl;
            if(rem.j == 0){
                cout << rem.psf << " ." << endl;
            }

            for (int j = 1; j <= rem.s && rem.i + j < n; j++)
            {
                if(dp[rem.i + j] != 1e9 && dp[rem.i + j] == rem.j - 1){
                    queue.push(Pair(rem.i + j, arr[rem.i + j], dp[rem.i + j], rem.psf + " -> " + to_string(rem.i + j)));
                }
            }
        }
    } else {
        cout << -1 << endl;
    }
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}